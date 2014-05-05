<?php

/**
 * Migrate gallery feeds.
 */
class OsMigrateGalleryNode extends OsMigrate {
  public $entityType = 'node';
  public $bundle = 'media_gallery';

  public $csvColumns = array(
    array('id', 'ID'),
    array('title', 'Title'),
    array('body', 'Body'),
    array('images', 'Images'),
    array('destination', 'Destination'),
    array(OG_AUDIENCE_FIELD, 'Site'),
    array(OG_VOCAB_FIELD, 'Terms'),
    array('uid', 'UID'),
  );

  public $dependencies = array(
    'OsMigratePersonalNode',
    'OsMigrateProjectNode',
    'OsMigrateScienceTaxonomyTerm',
    'OsMigrateUsers',
  );

  public function __construct() {
    parent::__construct();

    // $this->addFieldMapping('body', 'body');
    $this->addFieldMapping(OG_AUDIENCE_FIELD, OG_AUDIENCE_FIELD)
      ->sourceMigration(array('OsMigratePersonalNode', 'OsMigrateProjectNode'));

    $this->addFieldMapping('media_gallery_file', 'images')
      ->separator(';');
    $this->addFieldMapping('media_gallery_file:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addFieldMapping('media_gallery_file:source_dir')
      ->defaultValue(drupal_get_path('module', 'os_migrate_demo') . '/images');
    $this->addFieldMapping('media_gallery_file:destination_dir', 'destination');

    $this->addFieldMapping(OG_VOCAB_FIELD, OG_VOCAB_FIELD)
      ->sourceMigration(array('OsMigrateScienceTaxonomyTerm'))
      ->separator('|');

    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('OsMigrateUsers');
  }
}