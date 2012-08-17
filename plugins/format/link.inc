<?php

/**
 * @file
 * The default format for adresses.
 */

$plugin = array(
  'title' => t('Website Link'),
  'format callback' => 'addressfield_format_link_generate',
  'type' => 'link',
  'weight' => -99,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function addressfield_format_link_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['link_block'] = array(
      '#type' => 'addressfield_container',
      '#attributes' => array('class' => array('custom-block')),
      '#weight' => 200,
    );
    $format['link_block']['link'] = array(
      '#title' => t('Contact Link'),
      '#size' => 40,
      '#attributes' => array('class' => array('address-link')),
      '#type' => 'textfield',
      '#tag' => 'span',
      '#default_value' => isset($address['link']) ? $address['link'] : '',
      '#field_prefix' => 'http://',
    );
  }
  else {
    // Add our own render callback for the format view
    $format['#pre_render'][] = '_addressfield_link_render_address';
  }
}
