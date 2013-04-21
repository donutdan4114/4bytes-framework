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
 * You can have multiple routes that point to one place.
 * These routes will all go to the index controller:
 *   - /index.php
 *   - /index
 *   - /home
 *   - /
 *   - /index.html
 */
addRoute(array('index.php', 'index.html', 'index', 'home', ''), array(
  'name' => 'homepage',
  'controller' => 'index',
  'method' => 'view',
  'regex' => FALSE,
));

/**
 * Use regex to match any URL pattern.
 * This pattern will match:
 *   - /contact
 *   - /contact/test
 *   - /contact/one/two/three
 * But will not match:
 *   - /test/contact
 */
addRoute(array('/^contact\/(.+)/'), array(
  // Do not include a 'name' when using regex patterns.
  'controller' => 'contact',
  'method' => 'view',
  'regex' => TRUE,
));

