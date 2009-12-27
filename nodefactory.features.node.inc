<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _nodefactory_node_info() {
  $items = array(
    'media_batch' => array(
      'name' => t('Media batch'),
      'module' => 'features',
      'description' => t('Upload multiple media files'),
      'has_title' => '0',
      'title_label' => t(''),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}
