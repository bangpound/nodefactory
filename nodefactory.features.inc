<?php

/**
 * Implementation of hook_content_default_fields().
 */
function nodefactory_content_default_fields() {
  module_load_include('inc', 'nodefactory', 'nodefactory.defaults');
  $args = func_get_args();
  return call_user_func_array('_nodefactory_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function nodefactory_ctools_plugin_api() {
  module_load_include('inc', 'nodefactory', 'nodefactory.defaults');
  $args = func_get_args();
  return call_user_func_array('_nodefactory_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function nodefactory_node_info() {
  module_load_include('inc', 'nodefactory', 'nodefactory.features.node');
  $args = func_get_args();
  return call_user_func_array('_nodefactory_node_info', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function nodefactory_strongarm() {
  module_load_include('inc', 'nodefactory', 'nodefactory.defaults');
  $args = func_get_args();
  return call_user_func_array('_nodefactory_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function nodefactory_views_default_views() {
  module_load_include('inc', 'nodefactory', 'nodefactory.features.views');
  $args = func_get_args();
  return call_user_func_array('_nodefactory_views_default_views', $args);
}
