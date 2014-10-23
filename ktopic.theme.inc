<?php

/**
 *
 */
function ktopic_theme() {
  return array(
    'ktopic_logos' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'target_type' => NULL,
      ),
      'template' => 'templates/ktopic-logos',
    ),
  );
}

function template_preprocess_ktopic_logos(&$vars) {
  $settings = $vars['settings'];
  $items = $vars['items'];
  $target_type = $vars['target_type'];

  kore_include('image');
  $vars['logos'] = array();
  foreach ($items as $delta => $item) {
    $entity_wrapper = entity_metadata_wrapper($target_type, $item['target_id']);
    $image = 0;
    switch ($settings['type']) {
      case 'square':
        $image = $entity_wrapper->field_logo_square->value();
        break;
      case 'portrait':
        $image = $entity_wrapper->field_logo_portrait->value();
        break;
      case 'landscape':
        $image = $entity_wrapper->field_logo_landscape->value();
        break;
    }
    if ($image) {
      $kore_image = kore_image_prepare($image[0]['fid'], 'image', $settings);
      // Link to entity.
      if ($settings['link']) {
        $kore_image['#link'] = entity_uri($target_type, entity_load_single($target_type, $item['target_id']));
      }
      $vars['logos'][$delta] = $kore_image;
    }
  }
}

/**
 * Implements hook_preprocess_HOOK().
 *
 * Add ktopic identity for others.
 */
function ktopic_preprocess_page(&$vars) {
  if (!isset($vars['node'])) return;

  // Now extensions can check $vars['ktopic'].
  if ($vars['node']->type == 'ktopic') {
    $vars['ktopic'] = $vars['node'];
  }

  // dsm($vars);
}
