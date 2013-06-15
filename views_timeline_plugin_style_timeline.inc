<?php
/**
 * @file 
 * Views style plugin
 */

class views_timeline_plugin_style_timeline extends views_plugin_style {

	/* (non-PHPdoc)
	 * @see views_plugin_style::option_definition()
	 */
	 function option_definition() {
		$options = parent::option_definition();
		
		$options['timeline_theme']['width'] = array('default' => '300');
		
		$options['timeline_fields']['title'] = array('default' => 0);
		$options['timeline_fields']['description'] = array('default' => 0);
		$options['timeline_fields']['date'] = array('default' => 0);
		$options['timeline_fields']['image'] = array('default' => 0);
		$options['timeline_fields']['image_caption'] = array('default' => 0);
		
		return $options;
	}
	
	/* (non-PHPdoc)
	 * @see views_object::_set_option_defaults()
	*/
	function options_form(&$form, &$form_state) {
// 		check to ensure at least one field is set
		$handlers = $this->display->handler->get_handlers('field');
		if (empty($handlers)) {
			$form['error_markup'] = array(
					'#prefix' => '<div class="error messages">',
					'#markup' => t('You need at least one field before you can configure TimelineJS.'),
					'#suffix' => '</div>',
			);
			return;
		}
		
		
		
		$text_sources = array('0' => t('None'));
		$date_sources = array('0' => t('None'));
		$image_sources = array('0' => t('None'));
		
		//load ctools plugins
		ctools_include('plugins');
		$text_sources = ctools_get_plugins('views_timeline', 'text_sources');
// 		$date_sources = ctools_get_plugins('views_timeline', 'date_sources');
		$image_sources = ctools_get_plugins('views_timeline', 'image_sources');
		
		foreach ($handlers as $field => $handler) {
			$field_names[$field] = $handler->ui_name();
			
			if (isset($handler->definition['field_name'])) {
				$field_name = $handler->definition['field_name'];
				$field_info = field_info_field($field_name);
			}
			
			if ($field == 'body') {
				dsm($handler);
			}
			
			
			//check for available text fields
			foreach ($text_sources as $source) {
				if (get_class($handler) == $source['handler_name']) {
					if ((isset($field_info['type']) && $field_info['type'] == $source['field_type']) || $field == 'title') {
						$text_fields[$field] = $field_names[$field];
					}
				}
			}
			
			// check for available date fields
// 			foreach ($text_sources as $source) {
// 				if (get_class($handler) == $source['handler_name']) {
// 					if (isset($field_info['type']) && $field_info['type'] == $source['field_type']) {
// 						$text_fields[$field] = $field_names[$field];
// 					}
// 				}
// 			}

			//check for available image fields
			foreach ($image_sources as $source) {
				if (get_class($handler) == $source['handler_name']) {
					if (isset($field_info['type']) && $field_info['type'] == $source['field_type']) {
						$image_fields[$field] = $field_names[$field];
					}
				}
			}
		}
		
		$form['timeline_fields'] = array(
			'#type' => 'fieldset',
			'#title' => t('Fields'),
			'#description' => t('Select fields to be used for the timeline widgets'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,	
		);
		
		$form['timeline_fields']['title'] = array(
			'#type' => 'select',
			'#title' => t('Title'),
			'#description' => t('Plain text title'),
			'#options' => $text_fields,
		);
		$form['timeline_fields']['description'] = array(
			'#type' => 'select',
			'#title' => t('Description'),
			'#description' => t('A short summary of the event'),
			'#options' => $text_fields,
		);
		$form['timeline_fields']['date'] = array(
			'#type' => 'select',
			'#title' => t('Date'),
			'#description' => t('The date of the event'),
			'#options' => $field_names,
		);
		$form['timeline_fields']['image'] = array(
			'#type' => 'select',
			'#title' => t('Image'),
			'#description' => t('Media source for image'),
			'#options' => $image_fields,
		);
		$form['timeline_fields']['image caption'] = array(
			'#type' => 'select',
			'#title' => t('Image Caption'),
			'#description' => t('Credit for media source'),
			'#options' => $field_names,
		);
		
		
		
		$form['timeline_theme'] = array(
			'#type' => 'fieldset',
			'#title' => t('width'),
			'#description' => t('The width of the timeline'),
			'#collapsible' => TRUE,
			'#collapsed' => FALSE,
		);
		
		$form['timeline_theme']['width'] = array(
			'#type' => 'textfield', 
			'#title' => t('width'),
			'#description' => t('width of the timeline'),
			'#default_value' => 100,
		);
		
	}
	
	function render() {
		//debug
		$handlers = $this->display->handler->get_handlers('field');
		
		
		
		
		
		//end debug
		
		$view = $this->view;
		$result = array();
		
		foreach($this->view->result as $key => $row) {
			//@TODO create field mappings
			//better way to access node field data?
			$entity = $row->_field_data['nid']['entity'];
			$result[$key]['debug'] = $entity;
			
			$result[$key]['title'] = $entity->title;
			
			$desc = $entity->body['und']['0']['value'];
			$result[$key]['desc'] = strip_tags($desc);
			
			$result[$key]['date'] = $entity->field_timeline_date['und']['0']['value'];
			
			$result[$key]['image']['alt'] = $entity->field_image['und']['0']['alt'];
			$result[$key]['image']['uri'] = $entity->field_image['und']['0']['uri'];
			
			$result[$key]['image']['caption'] = $entity->field_timeline_caption_text['und']['0']['value'];
			

			
			//debug($row);
		}
		
		
		return theme('views_timeline', array('result' => $result));
		// Render fields to trigger rewriting and other field processing.
		$this->view->style_plugin->render_fields($this->view->result);
	}

}