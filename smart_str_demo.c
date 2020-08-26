//
// Created by purelightme on 2020/8/25.
//

#include <php_output.h>
#include "zend_smart_str.h"

PHP_FUNCTION(smart_str_test)
{
    smart_str my_str = {0};

    smart_str_appends(&my_str, "Hello, you are using PHP version ");
    smart_str_appends(&my_str, PHP_VERSION);

    smart_str_appends(&my_str, "\n");

    smart_str_appends(&my_str, "You are using ");
    smart_str_append_unsigned(&my_str, zend_hash_num_elements(CG(function_table)));
    smart_str_appends(&my_str, " PHP functions");

    smart_str_0(&my_str);

/* 现在使用 my_str */
    PHPWRITE(ZSTR_VAL(my_str.s), ZSTR_LEN(my_str.s));

/* 不要忘记释放它 */
    smart_str_free(&my_str);
}
