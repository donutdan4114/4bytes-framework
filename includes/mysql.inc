<?php

/**
 * Initializes the DB connection for MySQL.
 */

// Load information from settings.
// You can edit your settings in your settings.php file.
$db = setting('MYSQL.SETTINGS');

// Initialize the connection.
$mysql = new PDO('mysql:host=' . $db['host'] . ';dbname=' . $db['database'] . ';charset=UTF-8', $db['user'], $db['pass']);
