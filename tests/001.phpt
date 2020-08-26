--TEST--
Check if purelightme is loaded
--SKIPIF--
<?php
if (!extension_loaded('purelightme')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "purelightme" is available';
?>
--EXPECT--
The extension "purelightme" is available
