<?php
/**
 * @file
 * ktopic.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function ktopic_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:ktopic:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'ktopic';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'chaos';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'row' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '734628a7-6608-42bf-a2e7-d67ce9e46045';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-45b82e6e-01b1-45b4-ba07-0a8cd7bb1f61';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '45b82e6e-01b1-45b4-ba07-0a8cd7bb1f61';
    $display->content['new-45b82e6e-01b1-45b4-ba07-0a8cd7bb1f61'] = $pane;
    $display->panels['row'][0] = 'new-45b82e6e-01b1-45b4-ba07-0a8cd7bb1f61';
    $pane = new stdClass();
    $pane->pid = 'new-ee7926ba-3968-479a-8d88-1c27af7c78a7';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:group_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'og_group_subscribe',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'field_name' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ee7926ba-3968-479a-8d88-1c27af7c78a7';
    $display->content['new-ee7926ba-3968-479a-8d88-1c27af7c78a7'] = $pane;
    $display->panels['row'][1] = 'new-ee7926ba-3968-479a-8d88-1c27af7c78a7';
    $pane = new stdClass();
    $pane->pid = 'new-3245be79-0780-4d03-b9d7-f7abf5d4c6de';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:logo_square';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3245be79-0780-4d03-b9d7-f7abf5d4c6de';
    $display->content['new-3245be79-0780-4d03-b9d7-f7abf5d4c6de'] = $pane;
    $display->panels['row'][2] = 'new-3245be79-0780-4d03-b9d7-f7abf5d4c6de';
    $pane = new stdClass();
    $pane->pid = 'new-a5d7cbe0-6253-4e12-bc21-288db80214f1';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:logo_landscape';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a5d7cbe0-6253-4e12-bc21-288db80214f1';
    $display->content['new-a5d7cbe0-6253-4e12-bc21-288db80214f1'] = $pane;
    $display->panels['row'][3] = 'new-a5d7cbe0-6253-4e12-bc21-288db80214f1';
    $pane = new stdClass();
    $pane->pid = 'new-65aa891b-4081-48e2-9fd6-335c92202f45';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:logo_portrait';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '65aa891b-4081-48e2-9fd6-335c92202f45';
    $display->content['new-65aa891b-4081-48e2-9fd6-335c92202f45'] = $pane;
    $display->panels['row'][4] = 'new-65aa891b-4081-48e2-9fd6-335c92202f45';
    $pane = new stdClass();
    $pane->pid = 'new-6900e28d-53a1-4098-9f8f-712a7442bbd2';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:kdata';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '6900e28d-53a1-4098-9f8f-712a7442bbd2';
    $display->content['new-6900e28d-53a1-4098-9f8f-712a7442bbd2'] = $pane;
    $display->panels['row'][5] = 'new-6900e28d-53a1-4098-9f8f-712a7442bbd2';
    $pane = new stdClass();
    $pane->pid = 'new-65a52d4b-209a-4cd2-aaeb-123d94e71a70';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:ktype';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '65a52d4b-209a-4cd2-aaeb-123d94e71a70';
    $display->content['new-65a52d4b-209a-4cd2-aaeb-123d94e71a70'] = $pane;
    $display->panels['row'][6] = 'new-65a52d4b-209a-4cd2-aaeb-123d94e71a70';
    $pane = new stdClass();
    $pane->pid = 'new-bdd73328-8c4d-4368-b5d4-475739a7fcc0';
    $pane->panel = 'row';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:ktopic_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'safeword_machine_basic',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'bdd73328-8c4d-4368-b5d4-475739a7fcc0';
    $display->content['new-bdd73328-8c4d-4368-b5d4-475739a7fcc0'] = $pane;
    $display->panels['row'][7] = 'new-bdd73328-8c4d-4368-b5d4-475739a7fcc0';
    $pane = new stdClass();
    $pane->pid = 'new-13dc73f0-6eb9-48ab-94ed-57cd05d720c0';
    $pane->panel = 'row';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'default',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '13dc73f0-6eb9-48ab-94ed-57cd05d720c0';
    $display->content['new-13dc73f0-6eb9-48ab-94ed-57cd05d720c0'] = $pane;
    $display->panels['row'][8] = 'new-13dc73f0-6eb9-48ab-94ed-57cd05d720c0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-45b82e6e-01b1-45b4-ba07-0a8cd7bb1f61';
  $panelizer->display = $display;
  $export['node:ktopic:default:default'] = $panelizer;

  return $export;
}
