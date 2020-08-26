/* purelightme extension for PHP */

#ifndef PHP_PURELIGHTME_H
# define PHP_PURELIGHTME_H

extern zend_module_entry purelightme_module_entry;
# define phpext_purelightme_ptr &purelightme_module_entry

# define PHP_PURELIGHTME_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_PURELIGHTME)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_PURELIGHTME_H */

#ifdef ZTS
#define PURELIGHTME_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(purelightme, v)
#else
#define PURELIGHTME_G(v) (purelightme_globals.v)
#endif
