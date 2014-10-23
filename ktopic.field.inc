<?php

define('KTOPIC_FIELD_NAME', 'field_ktopic_name');
define('KTOPIC_FIELD_TYPE', 'field_ktopic_type');

/**
 * @implements hook_field_info().
 */
function ktopic_field_info() {
  return array(
    'ktopic_name' => array(
      'label' => t('Ktopic Reference (Name)'),
      'description' => t("This field stores the ktopic name as reference identity."),
      'settings' => array('allowed_types' => array()),
      'default_widget' => 'options_select',
      'default_formatter' => 'ktopic_default',
    ),
  );
}

/**
 * @implements hook_field_settings_form().
 */
function ktopic_field_settings_form($field, $instance, $has_data) {
  $settings = $field['settings'];

  $form['allowed_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#options' => ktype_options(),
    '#default_value' => $settings['allowed_types'],
    '#title' => t('Allowed Topic Types'),
    '#size' => count(ktype_options()),
  );

  return $form;
}

/**
 * @implements hook_field_is_empty().
 */
function ktopic_field_is_empty($item, $field) {
  if (empty($item['name']) && (string) $item['name'] !== '0') {
    return TRUE;
  }
  return FALSE;
}

/**
 * @implements hook_field_widget_info_alter().
 */
function ktopic_field_widget_info_alter(&$info) {
  $widgets = array(
    'options_select' => array('ktopic_name'),
    'options_buttons' => array('ktopic_name'),
  );

  foreach ($widgets as $widget => $field_types) {
    $info[$widget]['field types'] = array_merge($info[$widget]['field types'], $field_types);
  }
}

/**
 * @implements hook_field_formatter_info().
 */
function ktopic_field_formatter_info() {
  kore_include('image');
  $image_default = kore_image_settings_default();
  return array(
    'ktopic_default' => array(
      'label' => t('Default'),
      'field types' => array('ktopic_name'),
    ),
    'ktopic_logos' => array(
      'label' => t('Topic logos'),
      'field types' => array('entityreference'),
      'settings' => array(
        'type' => 'square',
        'link' => FALSE,
        'image' => $image_default,
      ),
    ),
  );
}

function ktopic_logo_types() {
  return array(
    'square' => t('Square'),
    'portrait' => t('Portrait'),
    'landscape' => t('Landscape'),
  );
}

function ktopic_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  if ($display['type'] == 'ktopic_logos') {
    $element['type'] = array(
      '#type' => 'select',
      '#title' => t('Logo type'),
      '#options' => ktopic_logo_types(),
      '#default_value' => $settings['type'],
    );
    $element['link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Link to topic'),
      '#default_value' => $settings['link'],
    );
    kore_include('image');
    $id = array(
      $field['field_name'],
      'settings_edit_form',
      'settings',
      'image',
    );
    $element['image'] = kore_image_settings_form($id, 'fields', $settings['image']);
  }

  return $element;
}

function ktopic_field_formatter_settings_summary($field, $instance, $view_mode) {
  $summary = 'abc';

  return $summary;
}

/**
 * @implements hook_field_formatter_view().
 */
function ktopic_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'ktopic_default':
      break;
    case 'ktopic_logos':
      $vars = array(
        'items' => $items,
        'settings' => $display['settings'],
        'target_type' => $field['settings']['target_type'],
      );
      $element[] = array(
        '#markup' => theme('ktopic_logos', $vars),
      );
      break;
  }

  return $element;
}

/**
 * @implements hook_options_list().
 *
 * Being used to provide a list of options for field_type<list>.
 */
function ktopic_options_list($field, $instance, $entity_type, $entity) {
  $allowed_types = $field['settings']['allowed_types'];

  // @todo Support multi-lingual.
  $lang = LANGUAGE_NONE;

  $conds = array();
  if (!empty($allowed_types)) {
    $conds[] = array(
      'column' => 'target_id',
      'value' => array_keys($allowed_types),
      'operator' => 'IN',
    );
  }
  $node_ids = KtoolsEntityField::queryEntities('field_ktopic_type', $conds, 'node');
  $nodes = node_load_multiple($node_ids);
  $options_list = array();
  foreach ($nodes as $node) {
    $options_list[$node->field_ktopic_name[$lang][0]['machine']] = $node->title;
  }

  return $options_list;
}
