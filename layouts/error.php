<html>
  <head>
    <?php print HTML::title("Page Not Found"); ?>
    <?php print HTML::css('bootstrap'); ?>
    <?php print HTML::css('bootstrap-responsive'); ?>
    <?php print HTML::css('4bytes'); ?>
  </head>
  <body>

    <div class="container">

      <div class="navbar navbar-inverse navbar-fixed-top">
        <div class="navbar-inner">
          <div class="container">
            <a class="brand" href="/"><?php print setting('SYSTEM.SITE'); ?></a>
            <!--/.nav-collapse -->
          </div>
        </div>
      </div>

      <!-- Main hero unit for a primary marketing message or call to action -->
      <div class="hero-unit">

        <h1>Page Not Found</h1>

        <p>
          Looks like we don't have a page for /<?php print request_uri(); ?>...<br/>
          Check out our <a href="/">homepage</a>.
        </p>

      </div>

      <hr>

      <div id="footer">
        <div class="container">
          <p class="muted credit">Created by
            <a href="http://danieljpepin.com" target="_blank">DJP</a> |
            View on
            <a href="http://donutdan4114.github.com/4bytes-framework/" target="_blank">GitHub</a> |
            Learn more about
            <a href="http://twitter.github.com/bootstrap/" target="_blank">Twitter Bootstrap</a>
          </p>
        </div>
      </div>

    </div>
  </body>
</html>
