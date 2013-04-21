## Blocks
***
**Small files that contain reusable HTML**

Examples of blocks include navs, footers, promo tiles, and asides.

You can print out blocks in your controllers, views, and layouts.

Example:
```
<?= block('main_nav') ?>
```

You can pass variables to the block:
```
 <?= block('main_nav', array('page' => 'about')) ?>
```