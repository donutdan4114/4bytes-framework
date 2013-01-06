<?php

// You tried to render a view that does not exist.
//throw new Exception("View does not exist");
trigger_error("View does not exist", E_USER_NOTICE);
