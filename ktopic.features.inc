<?php
/**
 * @file
 * ktopic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ktopic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
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
