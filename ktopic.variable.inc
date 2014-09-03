<?php

/**
 * Implements hook_variable_info().
 */
function ktopic_variable_info($options) {
  // Text with format
  $variables['ktopic_type_options'] = array(
    'type' => 'options',
    'title' => t('Topic Type Options', array(), $options),
    'default callback' => 'ktopic_type_options',
    'description' => t('List of topic types as options.', array(), $options),
    'required' => TRUE,
    'group' => 'keatures',
  );

  return $variables;
}
