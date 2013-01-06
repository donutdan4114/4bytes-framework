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
require '../includes/system.inc';

// HTML helper file.
require '../includes/html.inc';

// Need to load the routes.
require '../routes.php';

// Need to load settings.
require '../settings.php';

// require '../includes/json.php'; // Loads the JSON file database system.


// Include the controller for this path.
print include_controller(path());

