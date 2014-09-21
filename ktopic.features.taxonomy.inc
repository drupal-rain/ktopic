<?php
/**
 * @file
 * ktopic.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ktopic_taxonomy_default_vocabularies() {
  return array(
    'ktype' => array(
      'name' => 'Topic Type',
      'machine_name' => 'ktype',
      'description' => 'Topic types category.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
