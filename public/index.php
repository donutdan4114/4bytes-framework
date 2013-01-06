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
// require '../includes/json.php'; // Loads the JSON file database system.

// Include the controller for this path.
include controller(path());

/*
 * Print the layout of the path.
 * A URL argument that is a number is not interpreted.
 */
print layout(path());
