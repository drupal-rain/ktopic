<?php
/**
 * @file
 * ktopic.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ktopic_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_logo|node|ktopic|form';
  $field_group->group_name = 'group_logo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ktopic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Logo',
    'weight' => '5',
    'children' => array(
      0 => 'logo_square',
      1 => 'logo_landscape',
      2 => 'logo_portrait',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-logo field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_logo|node|ktopic|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_topic|node|ktopic|form';
  $field_group->group_name = 'group_topic';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'ktopic';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Topic',
    'weight' => '3',
    'children' => array(
      0 => 'kdata',
      1 => 'ktype',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-topic field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_topic|node|ktopic|form'] = $field_group;

  return $export;
}
