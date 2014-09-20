<?php


function ktopic_views_data_alter(&$data) {

  $data_tmp = &$data['views_entity_node'];
  $kdata_bundles = eck_extras_get_entity_bundles('kdata');
  foreach ($kdata_bundles as $bundle) {
    //$data_tmp[$bundle]['relationship']['base'] = 'entity_eck_kdata';
    $data_tmp[$bundle]['relationship']['group'] = t('Ktopic');
    $data_tmp[$bundle]['relationship']['handler'] = 'kdata_entity_views_handler_relationship';
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
    // Add entity_kdata to this table, this make fields data available.
    $data_tmp[$bundle] += $data['entity_kdata'];
  }

  //$data['entity_node']['field_ktopic_data']['relationship']['handler'] = 'entity_views_handler_relationship_by_bundles';
}

