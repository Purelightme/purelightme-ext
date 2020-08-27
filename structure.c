//
// Created by purelightme on 2020/8/20.
//

#include <zend_types.h>

PHP_FUNCTION (ptest) {
    zval *para;
    ZEND_PARSE_PARAMETERS_START(1,1)
        Z_PARAM_ZVAL(para)
    ZEND_PARSE_PARAMETERS_END();
    php_printf("类型1：%d",para->u1.type_info);
    php_printf("类型2：%d",Z_TYPE_P(para));
    if (para->u1.type_info == 4){
        RETURN_LONG(para->value.lval);
    }
    if (para->u1.type_info == 6){
        RETURN_STR(para->value.str);
    }
    php_printf("不支持的参数类型");
    RETURN_NULL();
}

PHP_FUNCTION(hello)
{
    zend_string *name;

    ZEND_PARSE_PARAMETERS_START(1,1)
        Z_PARAM_STR(name)
    ZEND_PARSE_PARAMETERS_END();
    php_printf("name: %s,len: %d",ZSTR_VAL(name),ZSTR_LEN(name));
}

PHP_FUNCTION(internal_str)
{
    zend_string *foo,*bar;
    foo = zend_string_init("foo", strlen("foo"),0);
    bar = zend_string_copy(foo);
    php_printf("foo refcount: %d",foo->gc.refcount); //应该是2
    foo = zend_new_interned_string(foo);
    php_printf("bar refcount: %d", bar->gc.refcount); //应该是1,Interned 字符串总是将 refcount 设为一
    zend_string_release(foo);
    zend_string_release(bar);
}
