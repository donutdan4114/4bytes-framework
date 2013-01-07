<?php
/**
 * Put global settings here.
 * You can create custom settings.
 */

/**
 * This effects what types of errors your application shows.
 */
error_reporting(E_ERROR | E_WARNING | E_PARSE);


/**
 * This salt is used for hashing data.
 * This should be a unique, random string.
 */
addSetting('SYSTEM.SALT', 'put_random_string_here');

/**
 * This string is used to encrypt data on the site.
 */
addSetting('SYSTEM.ENCRYPT_KEY', 'put_random_string_here');

/**
 * Custom variable for site name.
 */
addSetting('SYSTEM.SITE', '4bytes Framework');

/**
 * You can encrypt cookies so they cannot be edited.
 */
addSetting('COOKIE.ENCRYPT', TRUE);

/**
 * Your MySQL settings.
 */
addSetting('MYSQL.SETTINGS', array(
  'host' => 'localhost',
  'database' => '',
  'port' => 3306,
  'user' => 'root',
  'pass' => '',
));


