<?php
/**
 * Routes allow you to manipulate URLs.
 * All URLs are naturally /controller/method/arg1/arg2/etc...
 * You can style URLs so they don't have to exactly match up with controllers.
 * Example:
 *   Instead of using /blog/view/45
 *   You could set a route for:
 *   addRoute(array('blog/best-php-frameworks'), array(
 *     'controller' => 'blog',
 *     'method' => 'view',
 *     'args' => array(45),
 *   ));
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


