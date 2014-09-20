<?php

// Add all kdata bundles as standard property to the node<ktopic>.
function ktopic_entity_property_info() {
  $info = array();
  $properties = &$info['node']['bundles']['ktopic']['properties'];
  $kdata_types = eck_extras_get_entity_bundles('kdata');
  foreach ($kdata_types as $kdata_type) {
    $properties[$kdata_type] = array(
      'label' => t('kdata<@kdata_type>', array('@kdata_type' => $kdata_type)),
      'type' => 'kdata',
      'getter callback' => 'ktopic_entity_metadata_kdata_getter_callback',
      'computed' => TRUE,
      'entity views field' => TRUE,
    );
  }

  return $info;
}
