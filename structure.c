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
