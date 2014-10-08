<?php

// Add all kdata bundles as standard property to the node<ktopic>.
// @see ktopic_views_data_alter().
function ktopic_entity_property_info() {
  $info = array();
  $kdata_bundles = kdata_get_bundles();
  if (empty($kdata_bundles)) {
    return $info;
  }
  $properties = &$info['node']['bundles']['ktopic']['properties'];
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
