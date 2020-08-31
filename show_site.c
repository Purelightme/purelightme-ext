//
// Created by purelightme on 2020/8/28.
//

#include "hello.h"

PHP_FUNCTION (show_site) {
    char *site = show_site();
    RETVAL_STRING(site);
    free(site);
    return;
}