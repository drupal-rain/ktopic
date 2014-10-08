<?php

/**
 * @implements hook_views_data_alter().
 */
function ktopic_views_data_alter(&$data) {
  $data_tmp = &$data['views_entity_node'];
  $kdata_bundles = kdata_get_bundles();
  foreach ($kdata_bundles as $bundle) {
    $data_tmp[$bundle]['relationship']['group'] = t('Ktopic');
    $data_tmp[$bundle]['relationship']['handler'] = 'views_handler_relationship';
    // @tips If need more complex situation, add 'join handler' to it.
    //   Like when multiple kdata attached to the same node and need to figure out
    //   which one is the right data to display.
    $data_tmp[$bundle]['relationship']['base'] = 'eck_kdata';
    $data_tmp[$bundle]['relationship']['base field'] = 'nid';
    $data_tmp[$bundle]['relationship']['relationship table'] = 'node';
    $data_tmp[$bundle]['relationship']['relationship field'] = 'nid';
    $data_tmp[$bundle]['relationship']['extra'][] = array(
      'field' => 'type',
      'value' => $bundle,
    );
  }
}
