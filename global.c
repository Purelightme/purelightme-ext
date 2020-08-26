//
// Created by purelightme on 2020/8/24.
//
#include <zend_types.h>

ZEND_BEGIN_MODULE_GLOBALS(purelightme)
    zend_long rnd;
ZEND_END_MODULE_GLOBALS(purelightme)

ZEND_DECLARE_MODULE_GLOBALS(purelightme)

static void rnd_init()
{
    php_random_int(0,INI_INT("purelightme.rnd_max"),&PURELIGHTME_G(rnd),0);
}

PHP_FUNCTION(rnd_guess)
{
    zend_long input;
    ZEND_PARSE_PARAMETERS_START(1,1)
        Z_PARAM_LONG(input)
    ZEND_PARSE_PARAMETERS_END();

    if(input == PURELIGHTME_G(rnd)){
        rnd_init();
        RETURN_TRUE;
    }

    if (input < PURELIGHTME_G(rnd)){
        RETURN_STRING("too less");
    }

    RETURN_STRING("too large");
}

PHP_FUNCTION(rnd_reset)
{
    rnd_init();
    RETURN_TRUE;
}
