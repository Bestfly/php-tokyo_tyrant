--TEST--
Table put
--SKIPIF--
<?php
include dirname(__FILE__) . "/skipif.inc.php";
skip_if_not_table();
?>
--FILE--
<?php
include 'config.inc.php';

$tt = new TokyoTyrantTable(TT_HOST, TT_PORT);
$tt->vanish();

$rec = $tt->put(array('test' => 'data', 'something' => time()));
var_dump($rec);

var_dump($tt->get($rec));
$tt->vanish();

?>
--EXPECTF--
int(%d)
array(2) {
  ["test"]=>
  string(4) "data"
  ["something"]=>
  string(10) "%d"
}