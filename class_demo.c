//
// Created by purelightme on 2020/8/27.
//

#include <zend_interfaces.h>
#include "zend_types.h"

zend_class_entry *demo_ce;
zend_class_entry *child_ce;

PHP_METHOD (Demo, display) {
    RETURN_STRING("call Demo::display");
}

PHP_METHOD (Demo, setName) {
    zend_string *name;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STR(name)
    ZEND_PARSE_PARAMETERS_END();

    zend_update_property_string(demo_ce, getThis(), "name", sizeof("name") - 1, ZSTR_VAL(name));

    RETURN_TRUE;
}

const zend_function_entry demo_methods[] = {
        ZEND_ME(Demo, display, NULL, ZEND_ACC_PUBLIC)
        ZEND_ME(Demo, setName, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};

PHP_METHOD(Child,getName)
{
    zval *attr;
    attr = zend_read_property(Z_OBJCE_P(getThis()),getThis(),"name", sizeof("name") - 1,0,NULL);
    if (Z_TYPE_P(attr) == IS_STRING){
        RETURN_STR(Z_STR_P(attr));
    } else{
        RETURN_NULL();
    }
}

PHP_METHOD(Child,setName2)
{
    zend_string *name;

    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_STR(name)
    ZEND_PARSE_PARAMETERS_END();

//    zend_call_method_with_1_params(getThis(),demo_ce,NULL,"setName",NULL,strcat(ZSTR_VAL(name),"child"));
//    call_user_function(EG(function_table),getThis(),"setName",NULL,1,"from child");
}

const zend_function_entry child_methods[] = {
        ZEND_ME(Child, getName, NULL, ZEND_ACC_PUBLIC)
        ZEND_ME(Child,setName2,NULL,ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};