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
    <?php print HTML::img(LOGO_PATH, array(
      'id' => 'logo',
      'class' => 'pull-right',
      'width' => 220,
    )); ?>
    <h1>Hello, world!</h1>

    <p>The 4bytes Framework comes with Twitter bootstrap and jQuery.<br/>Check out the
      <a href="http://twitter.github.com/bootstrap/getting-started.html#examples" target="_blank">bootstrap documentation</a>.
    </p>

    <p>
      Also, <?php print HTML::link('check out a sub-page', 'contact') ?>, and see how easy it is to code with 4bytes.
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


<!-- /container -->
