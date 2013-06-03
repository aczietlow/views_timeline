<?php
/**
 * @file 
 * Views template to output the timeline wrapper markup
 */

/**
 * Preprocessor for views template
 */
function template_preprocess_views_timeline(&$vars) {
	//@TODO format the data to a year
	$count = count($vars['result']);
	for($i=0; $i<$count; $i++) {
		$date = new DateTime($vars['result'][$i]['date']);
		$vars['result'][$i]['date'] = $date->format('Y');
	}
	
	drupal_add_css(drupal_get_path('module', 'views_timeline') . '/css/timeline.css');
	drupal_add_js(drupal_get_path('module', 'views_timeline') . '/js/timeline.js', array('type' => 'file', 'scope' => 'header'));
	//drupal_add_js(drupal_get_path('module', 'views_timeline') . '/js/jquery.easing.1.3.js');
}