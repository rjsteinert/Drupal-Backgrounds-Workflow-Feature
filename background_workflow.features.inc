<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function background_workflow_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
  elseif ($module == "workflow" && $api == "workflow") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function background_workflow_imagecache_default_presets() {
  $items = array(
    'background_node_view' => array(
      'presetname' => 'background_node_view',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '680',
            'height' => '100%',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implementation of hook_node_info().
 */
function background_workflow_node_info() {
  $items = array(
    'background' => array(
      'name' => t('Background'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function background_workflow_views_api() {
  return array(
    'api' => '2',
  );
}
