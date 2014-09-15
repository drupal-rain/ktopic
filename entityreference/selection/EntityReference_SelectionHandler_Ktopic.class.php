<?php

class EntityReference_SelectionHandler_Ktopic implements EntityReference_SelectionHandler {

  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    if ($field['settings']['target_type'] != 'node') {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }
    return new EntityReference_SelectionHandler_Ktopic($field, $instance);
  }

  public function __construct($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity_type = $entity_type;
    $this->entity = $entity;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $allowed_types = isset($field['settings']['handler_settings']['allowed_types']) ? $field['settings']['handler_settings']['allowed_types'] : array();

    $form['allowed_types'] = array(
      '#type' => 'select',
      '#multiple' => TRUE,
      '#options' => ktopic_type_options(),
      '#default_value' => $allowed_types,
      '#title' => t('Allowed Topic Types'),
      '#size' => count(ktopic_type_options()),
    );

    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   *
   * @todo Simplify together with countReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $allowed_types = $this->field['settings']['handler_settings']['allowed_types'];

    // @todo Support multi-lingual.
    $lang = LANGUAGE_NONE;

    $conds = array();
    if (!empty($allowed_types)) {
      $conds[] = array(
        'column' => 'target_id',
        'value' => array_keys($allowed_types),
        'operator' => 'IN',
      );
    }
    $node_ids = KtoolsEntityField::queryEntities('field_ktopic_type', $conds, 'node');
    $nodes = node_load_multiple($node_ids);
    $options_list = array();
    foreach ($nodes as $node) {
      $options_list['ktopic'][$node->nid] = $node->title;
    }

    return $options_list;
  }

  /**
   * Implements EntityReferenceHandler::countReferencableEntities().
   */
  public function countReferencableEntities($match = NULL, $match_operator = 'CONTAINS') {

    $allowed_types = $this->field['settings']['handler_settings']['allowed_types'];

    // @todo Support multi-lingual.
    $lang = LANGUAGE_NONE;

    $conds = array();
    if (!empty($allowed_types)) {
      $conds[] = array(
        'column' => 'target_id',
        'value' => array_keys($allowed_types),
        'operator' => 'IN',
      );
    }
    $node_ids = KtoolsEntityField::queryEntities('field_ktopic_type', $conds, 'node');
    $nodes = node_load_multiple($node_ids);


    return count($nodes);
  }

  /**
   * Implements EntityReferenceHandler::validateReferencableEntities().
   *
   * @todo
   */
  public function validateReferencableEntities(array $ids) {
    return $ids;
  }

  /**
   * Implements EntityReferenceHandler::validateAutocompleteInput().
   *
   * @todo
   */
  public function validateAutocompleteInput($input, &$element, &$form_state, $form) {

  }

  /**
   * Implements EntityReferenceHandler::entityFieldQueryAlter().
   */
  public function entityFieldQueryAlter(SelectQueryInterface $query) {

  }

  /**
   * Implements EntityReferenceHandler::getLabel().
   */
  public function getLabel($entity) {
    return $entity->title;
  }

}
