<?php
/**
 * @file
 * Image field as a media source
 */

$plugin = array(
	'name' => t('Image field for timeline'),
	'handler_name' => 'views_handler_field_field',
	'field_type' => 'image',
	'callback' => 'views_timeline_image_source_field_preparation',
);