/* purelightme extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_purelightme.h"
#include <time.h>
#include "structure.c"
#include "global.c"
#include "ini.c"
#include "smart_str_demo.c"
#include "resource_demo.c"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void purelightme_test1()
 */
PHP_FUNCTION(purelightme_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("purelightme::test1");
}
/* }}} */

PHP_FUNCTION(now)
{
    time_t t;
    t = time(NULL);
    RETURN_LONG(t);
}


/* {{{ string purelightme_test2( [ string $var ] )
 */
PHP_FUNCTION(purelightme_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(purelightme)
{
#if defined(ZTS) && defined(COMPILE_DL_PURELIGHTME)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

//	rnd_init();
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(purelightme)
{
    REGISTER_INI_ENTRIES();

    le_pf = zend_register_list_destructors_ex(file_dtor,NULL,le_pf_name,module_number);
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(purelightme)
{
    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_GINIT_FUNCTION(purelightme)
{
    purelightme_globals->rnd = 0;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_GSHUTDOWN_FUNCTION(purelightme)
{ }
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(purelightme)
{
    DISPLAY_INI_ENTRIES();
	php_info_print_table_start();
	php_info_print_table_header(2, "purelightme support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_purelightme_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_purelightme_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ purelightme_functions[]
 */
static const zend_function_entry purelightme_functions[] = {
	PHP_FE(purelightme_test1,		arginfo_purelightme_test1)
	PHP_FE(purelightme_test2,		arginfo_purelightme_test2)
	PHP_FE(now,NULL)
	PHP_FE(ptest,NULL)
	PHP_FE(hello,NULL)
	PHP_FE(rnd_guess,NULL)
	PHP_FE(rnd_reset,NULL)
	PHP_FE(smart_str_test,NULL)
	PHP_FE(pure_open,NULL)
	PHP_FE(pure_write,NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ purelightme_module_entry
 */
zend_module_entry purelightme_module_entry = {
	STANDARD_MODULE_HEADER,
	"purelightme",					/* Extension name */
	purelightme_functions,			/* zend_function_entry */
	PHP_MINIT(purelightme),							/* PHP_MINIT - Module initialization */
	PHP_MSHUTDOWN(purelightme),							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(purelightme),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(purelightme),			/* PHP_MINFO - Module info */
	PHP_PURELIGHTME_VERSION,		/* Version */
//	STANDARD_MODULE_PROPERTIES
    PHP_MODULE_GLOBALS(purelightme),
    PHP_GINIT(purelightme),
    PHP_GSHUTDOWN(purelightme),
    NULL, /* PRSHUTDOWN() */
    STANDARD_MODULE_PROPERTIES_EX
};
/* }}} */

#ifdef COMPILE_DL_PURELIGHTME
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(purelightme)
#endif
