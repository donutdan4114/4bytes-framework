<?php
/**
 * Routes allow you to manipulate URLs.
 * All URLs are naturally /controller/method/arg1/arg2/etc...
 * You can style URLs so they don't have to exactly match up with controllers.
 */

/**
 * This route will match the homepage.
 * You can create a link to the homepage by simply doing:
 *   print HTML::link('Go to homepage', 'homepage');
 */
addRoute(array(''), array(
  'name' => 'homepage',
  'controller' => 'index',
  'method' => 'view',
));

addRoute(array('contact'), array(
  'name' => 'contact',
  'controller' => 'contact',
  'method' => 'view',
));

