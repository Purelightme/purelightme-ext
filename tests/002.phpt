--TEST--
purelightme_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('purelightme')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = purelightme_test1();

var_dump($ret);
?>
--EXPECT--
The extension purelightme is loaded and working!
NULL
