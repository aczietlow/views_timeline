<?php
/**
 * @file 
 * Views template to output the timeline wrapper markup
 */

/**
 * Preprocessor for views template
 */
function template_preprocess_views_timeline(&$vars) {
	//format the data to a year
	
	
	drupal_add_css(drupal_get_path('module', 'views_timeline') . '/css/timeline.css');
	drupal_add_js(drupal_get_path('module', 'views_timeline') . '/js/timeline.js');
	drupal_add_js(drupal_get_path('module', 'views_timeline') . '/js/jquery.easing.1.3.js');
}