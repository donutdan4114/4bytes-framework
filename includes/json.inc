<?php

// Initialize the JSON_DB class.
$json = new JSON_DB();

/**
 * JSON Simple File Database.
 *
 * This provides a very simple interface for dealing with key/value pairs.
 * For a simple website, this might be more useful than a full-blown DB.
 */
class JSON_DB {

  /**
   * @var array Contains file contents when they get loaded.
   */
  private $memory = array();

  /**
   * Gets a value from the database.
   *
   * @param $file JSON filename.
   * @param $key Unique key to return the value for.
   *
   * @return mixed
   */
  function get($file, $key) {
    if (!isset($this->memory[$file])) {
      $this->load($file);
    }
    return $this->memory[$file][$key];
  }

  /**
   * Sets a key/value pair in the database.
   * The value can be an array or anything else.
   *
   * @param $file
   * @param $key
   * @param $val
   */
  function set($file, $key, $val) {
    if (!file_exists('../database/' . $file . '.json')) {
      // If the file doesn't exist, create it.
      $this->save($file);
    }
    if (!isset($this->memory[$file])) {
      $this->load($file);
    }
    $this->memory[$file][$key] = $val;
    $this->save($file);
    $this->load($file);
  }

  /**
   * Loads a file into memory.
   *
   * @param $file
   */
  private function load($file) {
    $this->memory[$file] = (array) json_decode(file_get_contents('../database/' . $file . '.json'));
  }

  /**
   * Saves a file to the file system.
   *
   * @param $file
   */
  private function save($file) {
    file_put_contents('../database/' . $file . '.json', json_encode($this->memory[$file]));
  }


}
