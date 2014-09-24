<?php

$plugin = array(
  'title' => t('Kdata of Ktopic'),
  'description' => t('Kdata attached to the node<ktopic>.'),
  'keyword' => 'kdata',
  'required context' => new ctools_context_required(t('node<ktopic>'), 'node'),
  'context' => 'ktopic_ktopic_kdata_context',
  'edit form' => 'ktopic_ktopic_kdata_settings_form',
  'defaults' => array(
    'bundle' => '',
  ),
);

/**
 * Return a new context based on an existing context.
 */
function ktopic_ktopic_kdata_context($context, $conf) {
  $ktopic = $context->data;
  if (empty($ktopic)) {
    return ctools_context_create_empty('entity:kdata');
  }

  $ktopic_wrapper = entity_metadata_wrapper('node', $ktopic);
  $kdata = $ktopic_wrapper->{$conf['bundle']}->value();
  if (!empty($kdata)) {
    return ctools_context_create('entity:kdata', $kdata);
  }

  return FALSE;
}

/**
 * Settings form for selecting the kdata type to relate.
 */
function ktopic_ktopic_kdata_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $kdata_types = eck_extras_get_entity_bundles('kdata');
  $form['bundle'] = array(
    '#type' => 'select',
    '#title' => t('Kdata Type'),
    '#description' => t('Select the Kdata type.'),
    '#options' => array_combine($kdata_types, $kdata_types),
    '#default_value' => isset($conf['bundle']) ? $conf['bundle'] : '',
  );

  return $form;
}
