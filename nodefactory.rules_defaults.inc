<?php

/**
 * @file
 * Nodefactory module's default rules.
 */

/**
 * Implementation of hook_rules_defaults().
 */
function nodefactory_rules_defaults() {
  return array (
    'rules' =>
    array (
      'nodefactory_1247428190_rules_11' =>
      array (
        '#type' => 'rule',
        '#set' => 'nodefactory_1247428190_make_media_nodes',
        '#label' => 'Create song node',
        '#active' => 1,
        '#weight' => '1',
        '#categories' =>
        array (
          0 => 'nodefactory',
        ),
        '#conditions' =>
        array (
          0 =>
          array (
            '#weight' => 0,
            '#info' =>
            array (
              'arguments' =>
              array (
                'file' =>
                array (
                  'type' => 'file',
                  'label' => 'File',
                ),
              ),
              'module' => 'System',
              'label' => 'File has type',
            ),
            '#name' => 'rules_condition_file_is_type',
            '#settings' =>
            array (
              'filemime' => 'audio/*
  ',
              '#argument map' =>
              array (
                'file' => 'file_loaded',
              ),
            ),
            '#type' => 'condition',
          ),
        ),
        '#actions' =>
        array (
          0 =>
          array (
            '#weight' => 0,
            '#type' => 'action',
            '#settings' =>
            array (
              'title' => '<?php echo $title; ?>',
              'type' => 'song',
              'node_access' => 1,
              '#argument map' =>
              array (
                'author' => 'author',
                'node_added' => 'node_added',
              ),
              '#eval input' =>
              array (
                'rules_input_evaluator_php' =>
                array (
                  'title' =>
                  array (
                    0 => 'title',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_add_node',
            '#info' =>
            array (
              'label' => 'Add new content',
              'arguments' =>
              array (
                'author' =>
                array (
                  'type' => 'user',
                  'label' => 'User, who is set as author',
                ),
                'title' =>
                array (
                  'type' => 'string',
                  'label' => 'Title',
                  'description' => 'The title of the newly created content.',
                ),
              ),
              'new variables' =>
              array (
                'node_added' =>
                array (
                  'label' => 'new content of type song',
                  'type' => 'node',
                  'save' => true,
                  'label callback' => 'rules_action_add_node_variable_label',
                ),
              ),
              'module' => 'Node',
            ),
          ),
          4 =>
          array (
            '#type' => 'action',
            '#settings' =>
            array (
              'field_name' => 'field_song_mp3',
              '#argument map' =>
              array (
                'node' => 'node_added',
              ),
              'value' =>
              array (
                0 =>
                array (
                  'fid' => 0,
                  'list' => '1',
                  'data' =>
                  array (
                    'description' => '',
                  ),
                  'filepath' => '',
                  'filename' => '',
                  'filemime' => '',
                  'filesize' => 0,
                  'filefield_upload' => 'Upload',
                  'filefield_remove' => 'Remove',
                  'upload' => '',
                ),
              ),
              'code' => 'return array(0 => array(\'fid\' => $file_loaded->fid));',
              'vars' =>
              array (
                0 => 'file_loaded',
              ),
            ),
            '#name' => 'content_rules_action_populate_field',
            '#info' =>
            array (
              'label' => 'Populate new content of type song\'s field \'field_song_mp3\'',
              'arguments' =>
              array (
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' =>
              array (
                0 => 'code',
                1 => 'value|0|list',
                2 => 'value|0|filepath',
                3 => 'value|0|filename',
                4 => 'value|0|filemime',
                5 => 'value|0|filefield_upload',
                6 => 'value|0|filefield_remove',
                7 => 'value|0|upload',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 1,
          ),
          2 =>
          array (
            '#weight' => 2,
            '#info' =>
            array (
              'module' => 'Node',
              'base' => 'rules_action_save_variable',
              'label' => 'Save a content',
              'arguments' =>
              array (
                'var_name' =>
                array (
                  'type' => 'value',
                  'default value' => 'node',
                ),
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'content',
                ),
              ),
            ),
            '#name' => 'rules_save_var_node',
            '#settings' =>
            array (
              'immediate' => 1,
              '#argument map' =>
              array (
                'node' => 'node_added',
              ),
            ),
            '#type' => 'action',
          ),
          3 =>
          array (
            '#type' => 'action',
            '#settings' =>
            array (
              'field_name' => 'field_created_nodes',
              '#argument map' =>
              array (
                'node' => 'node',
              ),
              'value' =>
              array (
                0 =>
                array (
                  'nid' => NULL,
                ),
              ),
              'code' => 'return array_merge($node->field_created_nodes, array(array(\'nid\' => $node_added->nid)));',
              'vars' =>
              array (
                0 => 'node_added',
                1 => 'node',
              ),
            ),
            '#name' => 'content_rules_action_populate_field',
            '#info' =>
            array (
              'label' => 'Populate Batch node\'s field \'field_created_nodes\'',
              'arguments' =>
              array (
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' =>
              array (
                0 => 'code',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 2,
          ),
        ),
        '#version' => 6003,
        '#status' => 'default',
      ),
      'nodefactory_1247428190_rules_9' =>
      array (
        '#type' => 'rule',
        '#set' => 'nodefactory_1247428190_make_media_nodes',
        '#label' => 'Create image node',
        '#active' => 1,
        '#weight' => '1',
        '#categories' =>
        array (
          0 => 'nodefactory',
        ),
        '#conditions' =>
        array (
          0 =>
          array (
            '#info' =>
            array (
              'arguments' =>
              array (
                'file' =>
                array (
                  'type' => 'file',
                  'label' => 'File',
                ),
              ),
              'module' => 'System',
              'label' => 'File has type',
            ),
            '#name' => 'rules_condition_file_is_type',
            '#settings' =>
            array (
              'filemime' => 'image/*
',
              '#argument map' =>
              array (
                'file' => 'file_loaded',
              ),
            ),
            '#type' => 'condition',
            '#weight' => 0,
          ),
        ),
        '#actions' =>
        array (
          0 =>
          array (
            '#weight' => 0,
            '#type' => 'action',
            '#settings' =>
            array (
              'title' => '<?php echo $title; ?>',
              'type' => 'image',
              'node_access' => 1,
              '#argument map' =>
              array (
                'author' => 'author',
                'node_added' => 'node_added',
              ),
              '#eval input' =>
              array (
                'rules_input_evaluator_php' =>
                array (
                  'title' =>
                  array (
                    0 => 'title',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_add_node',
            '#info' =>
            array (
              'label' => 'Add new content',
              'arguments' =>
              array (
                'author' =>
                array (
                  'type' => 'user',
                  'label' => 'User, who is set as author',
                ),
                'title' =>
                array (
                  'type' => 'string',
                  'label' => 'Title',
                  'description' => 'The title of the newly created content.',
                ),
              ),
              'new variables' =>
              array (
                'node_added' =>
                array (
                  'label' => 'new content of type image',
                  'type' => 'node',
                  'save' => true,
                  'label callback' => 'rules_action_add_node_variable_label',
                ),
              ),
              'module' => 'Node',
            ),
          ),
          1 =>
          array (
            '#weight' => 0,
            '#type' => 'action',
            '#settings' =>
            array (
              'field_name' => 'field_image',
              '#argument map' =>
              array (
                'node' => 'node_added',
              ),
              'value' =>
              array (
                0 =>
                array (
                  'fid' => 0,
                  'list' => '1',
                  'data' =>
                  array (
                    'description' => '',
                    'alt' => '',
                    'title' => '',
                  ),
                  'alt' => '',
                  'title' => '',
                  'filepath' => '',
                  'filename' => '',
                  'filemime' => '',
                  'filesize' => 0,
                  'filefield_upload' => 'Upload',
                  'filefield_remove' => 'Remove',
                  'upload' => '',
                ),
              ),
              'code' => 'return array(0 => array(\'fid\' => $file_loaded->fid));',
              'vars' =>
              array (
                0 => 'file_loaded',
              ),
            ),
            '#name' => 'content_rules_action_populate_field',
            '#info' =>
            array (
              'label' => 'Populate new content of type image\'s field \'field_image\'',
              'arguments' =>
              array (
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' =>
              array (
                0 => 'code',
                1 => 'value|0|list',
                2 => 'value|0|alt',
                3 => 'value|0|title',
                4 => 'value|0|filepath',
                5 => 'value|0|filename',
                6 => 'value|0|filemime',
                7 => 'value|0|filefield_upload',
                8 => 'value|0|filefield_remove',
                9 => 'value|0|upload',
              ),
              'module' => 'CCK',
            ),
          ),
          3 =>
          array (
            '#weight' => 0,
            '#info' =>
            array (
              'module' => 'Node',
              'base' => 'rules_action_save_variable',
              'label' => 'Save a content',
              'arguments' =>
              array (
                'var_name' =>
                array (
                  'type' => 'value',
                  'default value' => 'node',
                ),
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'content',
                ),
              ),
            ),
            '#name' => 'rules_save_var_node',
            '#settings' =>
            array (
              'immediate' => 1,
              '#argument map' =>
              array (
                'node' => 'node_added',
              ),
            ),
            '#type' => 'action',
          ),
          2 =>
          array (
            '#type' => 'action',
            '#settings' =>
            array (
              'field_name' => 'field_created_nodes',
              '#argument map' =>
              array (
                'node' => 'node',
              ),
              'value' =>
              array (
                0 =>
                array (
                  'nid' => NULL,
                ),
              ),
              'code' => 'return array_merge($node->field_created_nodes, array(array(\'nid\' => $node_added->nid)));',
              'vars' =>
              array (
                0 => 'node_added',
                1 => 'node',
              ),
            ),
            '#name' => 'content_rules_action_populate_field',
            '#info' =>
            array (
              'label' => 'Populate Batch node\'s field \'field_created_nodes\'',
              'arguments' =>
              array (
                'node' =>
                array (
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' =>
              array (
                0 => 'code',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 2,
          ),
        ),
        '#version' => 6003,
        '#status' => 'default',
      ),
      'nodefactory_1247428190_rules_8' =>
      array (
        '#type' => 'rule',
        '#set' => 'nodefactory_1247428190_make_media_nodes',
        '#label' => 'Load file',
        '#active' => 1,
        '#weight' => '0',
        '#categories' =>
        array (
          0 => 'nodefactory',
        ),
        '#conditions' =>
        array (
        ),
        '#actions' =>
        array (
          0 =>
          array (
            '#type' => 'action',
            '#settings' =>
            array (
              'fid' => '<?php echo $fid; ?>',
              '#argument map' =>
              array (
                'file_loaded' => 'file_loaded',
              ),
              '#eval input' =>
              array (
                'rules_input_evaluator_php' =>
                array (
                  'fid' =>
                  array (
                    0 => 'fid',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_load_file',
            '#info' =>
            array (
              'label' => 'Load file by id',
              'arguments' =>
              array (
                'fid' =>
                array (
                  'type' => 'number',
                  'label' => 'File ID',
                ),
              ),
              'new variables' =>
              array (
                'file_loaded' =>
                array (
                  'type' => 'file',
                  'label' => 'Loaded file',
                  'label callback' => 'rules_action_load_file_variable_label',
                ),
              ),
              'module' => 'nodefactory',
            ),
            '#weight' => 0,
          ),
          1 =>
          array (
            '#weight' => 1,
            '#info' =>
            array (
              'label' => 'Load the file author',
              'arguments' =>
              array (
                'file' =>
                array (
                  'type' => 'file',
                  'label' => 'File',
                ),
              ),
              'new variables' =>
              array (
                'author' =>
                array (
                  'type' => 'user',
                  'label' => 'File author',
                  'label callback' => 'rules_action_file_load_author_variable_label',
                ),
              ),
              'module' => 'System',
            ),
            '#name' => 'rules_action_file_load_author',
            '#settings' =>
            array (
              '#argument map' =>
              array (
                'file' => 'file_loaded',
                'author' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
        '#status' => 'default',
      ),
    ),
    'rule_sets' =>
    array (
      'nodefactory_1247428190_make_media_nodes' =>
      array (
        'arguments' =>
        array (
          'node' =>
          array (
            'type' => 'node',
            'label' => 'Batch node',
          ),
          'fid' =>
          array (
            'label' => 'File ID',
            'type' => 'number',
          ),
          'title' =>
          array (
            'label' => 'Title',
            'type' => 'string',
          ),
        ),
        'label' => 'Make media nodes',
        'categories' =>
        array (
          0 => 'nodefactory',
        ),
        'status' => 'default',
      ),
    ),
  );
}
