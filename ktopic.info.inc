<?php

// Add all kdata bundles as standard property to the node<ktopic>.
// @see ktopic_views_data_alter().
function ktopic_entity_property_info() {
  $info = array();
  $properties = &$info['node']['bundles']['ktopic']['properties'];
  $kdata_bundles = eck_extras_get_entity_bundles('kdata');
  foreach ($kdata_bundles as $kdata_bundle) {
    $properties[$kdata_bundle] = array(
      'label' => t('kdata<@kdata_type>', array('@kdata_type' => $kdata_bundle)),
      'type' => 'kdata',
      'getter callback' => 'ktopic_entity_metadata_kdata_getter_callback',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );
  }

  return $info;
}
