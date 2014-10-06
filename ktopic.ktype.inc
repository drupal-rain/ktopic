<?php

// @todo Refactory from ktopic_ktype_*() to ktype_*().

// ----------------------------------------------------------------------------
// Ktype Utility

/**
 * Return list of ktopic type options.
 */
function ktype_options() {
  $vocab = taxonomy_vocabulary_machine_name_load('ktype');
  $terms = taxonomy_get_tree($vocab->vid);
  $options = array();
  foreach ($terms as $term) {
    $options[$term->tid] = $term->name;
  }

  return $options;
}

function ktopic_ktype_vocab() {
  return taxonomy_vocabulary_machine_name_load('ktype');
}

function ktopic_ktype_vid() {
  $vocab = taxonomy_vocabulary_machine_name_load('ktype');
  return $vocab->vid;
}

function ktopic_ktype_term($term_name) {
  $vid = ktopic_ktype_vid();
  $query = new EntityFieldQuery;
  $query->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('name', $term_name)
    ->propertyCondition('vid', $vid);
  $result = $query->execute();
  if ($result) {
    $term_raw = reset($result['taxonomy_term']);
    return taxonomy_term_load($term_raw->tid);
  }

  return NULL;
}

function ktopic_ktype_names_to_ids($names) {
  $ids = array();

  // @todo Optimize by using load multiple by names using one query.
  foreach ($names as $name) {
    if ($name) {
      $term = ktopic_ktype_term($name);
      if ($term) {
        $ids[] = $term->tid;
      }
    }
  }

  return $ids;
}

/**
 * @implements hook_
 */
function ktopic_taxonomy_term_presave($term) {
  // Unique Ktype Term
  if (empty($term->tid) && ktopic_ktype_is_dupe($term->name, $term->vid)) {
    throw KtypeException;
  }
}

/**
 * Checks whether a term is a duplicate, based on the module preferences.
 *
 * @param $term
 *   Name of the new term to check
 *
 * @param int $vid
 *   ID of the vocabulary the new term belongs to
 *
 * @param int $tid
 *   Term ID of the new term (used when updating an existing term name)
 *
 * @return bool
 *   TRUE if the term is a duplicate, FALSE if not
 *
 * @see taxonomy_dupecheck_is_dupe_term().
 */
function ktopic_ktype_is_dupe($term, $vid, $tid = 0) {
  // Clean up the term to check
  $term = trim($term);

  // Get matching terms in the given vocabulary (case insensitive)
  $query = new EntityFieldQuery;
  $query = $query
    ->entityCondition('entity_type', 'taxonomy_term')
    ->propertyCondition('name', $term)
    ->propertyCondition('vid', $vid);
  if ($tid) {  // Ignore an existing term of the same name; this is needed on updates to an existing term.
    $query = $query->entityCondition('entity_id', $tid, '<>');
  }
  $result = $query->execute();

  // No results, term is unique
  if (is_array($result) && !$result) {
    return FALSE;
  }

  return TRUE;
}

function ktopic_form_taxonomy_form_term_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = 'ktopic_form_taxonomy_form_term_unique_validate';
}

function ktopic_form_taxonomy_form_term_unique_validate($form, &$form_state) {
  $term = $form['#term'];
  if (empty($term->tid)) {
    $values = $form_state['values'];
    if (ktopic_ktype_is_dupe($values['name'], $values['vid'])) {
      form_set_error('name', t('@name is already existed.', array(
        '@name' => $values['name'],
      )));
    }
  }
}

class KtypeException extends Exception {
}
