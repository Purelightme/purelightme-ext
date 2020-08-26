//
// Created by purelightme on 2020/8/25.
//

#include <stdio.h>
#include "zend_types.h"

static int le_pf;
#define le_pf_name "just_test"


typedef struct pfile_ch {
    FILE *p;
} pfilech;

static void file_dtor(zend_resource *rsrc)
{
    pfilech *pch = (pfilech *) rsrc->ptr;
    fclose(pch->p);
}

PHP_FUNCTION(pure_open)
{
    FILE *fp;
    pfilech *pch;
    char *path;
    long path_len;
    char *mode;
    long mode_len;
    ZEND_PARSE_PARAMETERS_START(2,2)
        Z_PARAM_STRING(path,path_len)
        Z_PARAM_STRING(mode,mode_len)
    ZEND_PARSE_PARAMETERS_END();
    fp = fopen(path,mode);
    if (fp == NULL){
        RETURN_NULL();
    }
    pch = ecalloc(1,sizeof(pfilech));
    pch->p = fp;
    ZVAL_RES(return_value,zend_register_resource(pch,le_pf));
}

PHP_FUNCTION(pure_write)
{
    zval *res;
    pfilech *pch;
    char *content;
    long content_len;
    ZEND_PARSE_PARAMETERS_START(2,2)
        Z_PARAM_RESOURCE(res)
        Z_PARAM_STRING(content,content_len)
    ZEND_PARSE_PARAMETERS_END();
    pch = (pfilech *)zend_fetch_resource(Z_RES_P(res),le_pf_name,le_pf);
    if (pch == NULL){
        php_printf("解析资源失败");
        RETURN_NULL();
    }
    fputs(content,pch->p);
    RETURN_NULL();
}