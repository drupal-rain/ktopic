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
    'ktopic_type' => array(
      'name' => 'Topic',
      'machine_name' => 'ktopic_type',
      'description' => 'Topic types category.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
