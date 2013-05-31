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
		
		$options['timeline_theme']['width'] = array('default' => '100');
// 		$options['timeline_theme']['width_unit'] = array('default' => '1');
// 		$options['timeline_theme']['height'] = array('default' => '500');
// 		$options['timeline_theme']['height_unit'] = array('default' => '0');
		
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
			$result[$key]['image']['src'] = $entity->field_image['und']['0']['uri'];
			
			$result[$key]['image']['captain'] = $entity->field_timeline_caption_text['und']['0']['value'];
			

			
			//debug($row);
		}
		
		
		return theme('views_timeline', array('node' => $result));
		// Render fields to trigger rewriting and other field processing.
		$this->view->style_plugin->render_fields($this->view->result);
	}

}