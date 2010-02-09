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
      'title_label' => '',
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
