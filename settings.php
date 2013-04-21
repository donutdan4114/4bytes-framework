<?php
/**
 * Put global settings here.
 * You can create custom settings.
 */

define('REQUEST_TIME', time());

define('LOGO_PATH', 'http://donutdan4114.github.com/4bytes-framework/images/logo_medium.png');

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
 * Secures cookies by always hashing the data and keeping a checksum to
 * reference. Only disable this if you understand the consequences.
 */
addSetting('COOKIE.SECURE', TRUE);

/**
 * Cookie separator for securing cookies and validating data.
 * Only change this value if you are setting cookies that may contain
 * the same delimiter.
 */
addSetting('COOKIE.SEPARATOR', '---checksum:');

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


