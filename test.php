<?php

// purelightme_test1();
// purelightme_test2();


// echo now();

// $p = ptest('ee');
// var_dump($p);
// $r = ptest(22);
// var_dump($r);
// $t = ptest([]);
// var_dump($t);


// var_dump(rnd_guess(0));
// var_dump(rnd_reset());
// var_dump(rnd_guess(0));

// var_dump((new \ReflectionExtension('purelightme'))->getVersion());

// var_dump(ini_get('purelightme.rnd_max'));

// ini_set('purelightme.rnd_max',300);
// var_dump(get_cfg_var('purelightme.rnd_max'));
// phpinfo();

// smart_str_test();

// $fp = pure_open("/tmp/test.log","aw+");
// var_dump($fp);
// $res = pure_write($fp,"测试文本,hello");
// var_dump($res);

// var_dump(hello('purelightme'));

// internal_str();

$demo = new Demo();
$demo->name = '张三';
$demo->age = 25;
$demo->setName('李四');
var_dump($demo->name);
var_dump($demo->age);
var_dump($demo->display());
$child = new Child();
$child->setName('哈哈测试34');
var_dump($child->getName());
//$child->age = 18;
//var_dump($child->age);
//var_dump($child->getName());

//var_dump(show_site());

//server();

// echo PURELIGHTME_JOB;
