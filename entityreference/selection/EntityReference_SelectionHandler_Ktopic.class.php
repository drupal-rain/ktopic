<?php

class EntityReference_SelectionHandler_Ktopic implements EntityReference_SelectionHandler {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    if ($field['settings']['target_type'] != 'node') {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }
    return new EntityReference_SelectionHandler_Ktopic($field, $instance);
  }

  public function __construct($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity_type = $entity_type;
    $this->entity = $entity;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $allowed_types = isset($field['settings']['handler_settings']['allowed_types']) ? $field['settings']['handler_settings']['allowed_types'] : array();

    $vocab = taxonomy_vocabulary_machine_name_load('ktype');
    $terms = taxonomy_get_tree($vocab->vid);
    $options = array();
    foreach ($terms as $term) {
      //$options[$term->name] = str_repeat('-', $term->depth) . check_plain($term->name);
      $options[$term->tid] = str_repeat('-', $term->depth) . check_plain($term->name);
    }

    $form['allowed_types'] = array(
      '#type' => 'checkboxes',
      '#multiple' => TRUE,
      '#options' => $options,
      '#default_value' => $allowed_types,
      '#title' => t('Allowed Topic Types'),
      //'#size' => count($options),
    );

    return $form;
  }

  protected function getKtopicNodes($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    // Need to filter out the disabled types.
    $allowed_types = $this->field['settings']['handler_settings']['allowed_types'];
    //$allowed_types = array_filter($allowed_types);

    // @todo Support multi-lingual.
    $lang = LANGUAGE_NONE;

    $conds = array();
    if (!empty($allowed_types)) {
      $term_ids = $allowed_types; //ktopic_ktype_names_to_ids($allowed_types);
      $conds[] = array(
        'column' => 'target_id',
        'value' => $term_ids,
        'operator' => 'IN',
      );
    }
    $node_ids = KtoolsEntityField::queryEntities('ktype', $conds, 'node');
    $nodes = node_load_multiple($node_ids);

    return $nodes;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   *
   * @todo Simplify together with countReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $nodes = $this->getKtopicNodes($match, $match_operator, $limit);

    $options_list = array();
    foreach ($nodes as $node) {
      $options_list['ktopic'][$node->nid] = $node->title;
    }

    return $options_list;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {
    $nodes = $this->getKtopicNodes($match, $match_operator);

    return count($nodes);
  }

  /**
   * Implements EntityReferenceHandler::validateReferencableEntities().
   *
   * @todo
   */
  public function validateReferencableEntities(array $ids) {
    return $ids;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   *
   * @todo
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {

  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {

  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return $entity->title;
  }

}
