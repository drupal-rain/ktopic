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
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'fbae0879-faa5-48f0-a214-76d19fb9083a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2145b90e-d3ed-49c8-b972-bf95a5dbc576';
    $pane->panel = 'center';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2145b90e-d3ed-49c8-b972-bf95a5dbc576';
    $display->content['new-2145b90e-d3ed-49c8-b972-bf95a5dbc576'] = $pane;
    $display->panels['center'][0] = 'new-2145b90e-d3ed-49c8-b972-bf95a5dbc576';
    $pane = new stdClass();
    $pane->pid = 'new-3494a50f-8b94-4d52-b1fa-73ad31f1ada6';
    $pane->panel = 'center';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3494a50f-8b94-4d52-b1fa-73ad31f1ada6';
    $display->content['new-3494a50f-8b94-4d52-b1fa-73ad31f1ada6'] = $pane;
    $display->panels['center'][1] = 'new-3494a50f-8b94-4d52-b1fa-73ad31f1ada6';
    $pane = new stdClass();
    $pane->pid = 'new-a24482d1-c1cc-4a3e-b040-d39826d46e88';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ktopic_name';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a24482d1-c1cc-4a3e-b040-d39826d46e88';
    $display->content['new-a24482d1-c1cc-4a3e-b040-d39826d46e88'] = $pane;
    $display->panels['center'][2] = 'new-a24482d1-c1cc-4a3e-b040-d39826d46e88';
    $pane = new stdClass();
    $pane->pid = 'new-90ce284a-5be8-4183-ab62-3029b657ce8d';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_logo_square';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '90ce284a-5be8-4183-ab62-3029b657ce8d';
    $display->content['new-90ce284a-5be8-4183-ab62-3029b657ce8d'] = $pane;
    $display->panels['center'][3] = 'new-90ce284a-5be8-4183-ab62-3029b657ce8d';
    $pane = new stdClass();
    $pane->pid = 'new-bf2a6bdf-70c5-4978-84df-d23fff3884ab';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_logo_rectangle';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bf2a6bdf-70c5-4978-84df-d23fff3884ab';
    $display->content['new-bf2a6bdf-70c5-4978-84df-d23fff3884ab'] = $pane;
    $display->panels['center'][4] = 'new-bf2a6bdf-70c5-4978-84df-d23fff3884ab';
    $pane = new stdClass();
    $pane->pid = 'new-0212efe5-602f-4103-837f-e4e55c0aafc9';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ktopic_data';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0212efe5-602f-4103-837f-e4e55c0aafc9';
    $display->content['new-0212efe5-602f-4103-837f-e4e55c0aafc9'] = $pane;
    $display->panels['center'][5] = 'new-0212efe5-602f-4103-837f-e4e55c0aafc9';
    $pane = new stdClass();
    $pane->pid = 'new-38652cac-7143-4f3c-bb3e-4be448b120fc';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ktopic_type';
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
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '38652cac-7143-4f3c-bb3e-4be448b120fc';
    $display->content['new-38652cac-7143-4f3c-bb3e-4be448b120fc'] = $pane;
    $display->panels['center'][6] = 'new-38652cac-7143-4f3c-bb3e-4be448b120fc';
    $pane = new stdClass();
    $pane->pid = 'new-42c26744-cf0d-4332-8bc8-dd97e80e2efd';
    $pane->panel = 'center';
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
    $pane->style = array();
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '42c26744-cf0d-4332-8bc8-dd97e80e2efd';
    $display->content['new-42c26744-cf0d-4332-8bc8-dd97e80e2efd'] = $pane;
    $display->panels['center'][7] = 'new-42c26744-cf0d-4332-8bc8-dd97e80e2efd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-42c26744-cf0d-4332-8bc8-dd97e80e2efd';
  $panelizer->display = $display;
  $export['node:ktopic:default:default'] = $panelizer;

  return $export;
}
