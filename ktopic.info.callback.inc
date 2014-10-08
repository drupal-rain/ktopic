<?php

function ktopic_entity_metadata_kdata_getter_callback($data, array $options, $name, $type, $info) {
  return ktopic_get_kdata($data, $name);
}
