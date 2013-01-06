<?php
/**
 * 4bytes Framework
 *
 * This is the main file that loads the site.
 * Notice how small it is. Wow, so small.
 *
 * @author Daniel Pepin <me@danieljpepin.com>
 */

/**
 * Include misc files.
 * If you need to include anything misc, do it here.
 */
require '../includes/functions.inc';

// HTML helper file.
require '../includes/html.inc';

// require '../includes/json.php'; // Loads the JSON file database system.

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
addRoute(array(''), array(
  'controller' => 'index',
  'method' => 'view',
  'args' => args(),
));


// Include the controller for this path.
print include_controller(path());

