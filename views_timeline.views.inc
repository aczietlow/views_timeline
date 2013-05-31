<?php 
/**
 * @file 
 * Views Stlye plugin for Views Timeline Module
 */


/**
 * Implements hook_views_plugins()
 * http://api.drupal.org/api/views/views.api.php/function/hook_views_plugins/7
 */
function views_timeline_views_plugins() {
	return array(
			'style' => array(
				'timeline' => array (
					'title' => t('Timeline'),
					'path' => drupal_get_path('module', 'views_timeline'),
					'handler' => 'views_timeline_plugin_style_timeline',
					'uses options' => TRUE,
					'help' => t('Display the results in a Timeline.'),
					'type' => 'normal',
					'theme' => 'views_timeline',
					'theme path' => drupal_get_path('module', 'views_timeline') . '/theme',
					'theme file' => 'views_timeline.theme.inc',
					
					'uses row plugin' => FALSE,
					'uses row class' => FALSE,
					'uses fields'     => TRUE,
					'uses grouping' => FALSE,
				),
			),
		);
}