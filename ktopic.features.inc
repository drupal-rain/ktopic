<?php
/**
 * @file
 * ktopic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ktopic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ktopic_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_entity_type_info().
 */
function ktopic_eck_entity_type_info() {
  $items = array(
    'kdata' => array(
      'name' => 'kdata',
      'label' => 'Data',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_node_info().
 */
function ktopic_node_info() {
  $items = array(
    'ksubject' => array(
      'name' => t('Subject'),
      'base' => 'node_content',
      'description' => t('Article-like content, only serve ktopic.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'ktopic' => array(
      'name' => t('Topic'),
      'base' => 'node_content',
      'description' => t('A wiki-like topic content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
