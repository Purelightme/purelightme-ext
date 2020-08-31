//
// Created by purelightme on 2020/8/28.
//

#include "zend_types.h"
#include <stdio.h>
#include <sys/socket.h>
#include <assert.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>


PHP_FUNCTION(server)
{
    int socketfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    assert(socketfd > 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    addr.sin_port = htons(8001);
    bind(socketfd,&addr,sizeof(addr));
    listen(socketfd,5);
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr);
    int clientfd = accept(socketfd, (struct sockaddr *) &client_addr, &client_addr_len);

    int mem_size = 5;
    int length = 0;
    int len;

    char *buf = (char *)malloc(mem_size * sizeof(char));
    char *response = (char *)malloc(mem_size * sizeof(char));

    while (1) {
        len = read(clientfd, buf, 1);
        if (len > 0) {
            if (length + len > mem_size){
                mem_size *= 2;
                response = (char *)realloc(response, sizeof(char) * mem_size);
            }
            buf[len] = '\0';
            length += len;
            strcat(response,buf);
        } else if (len == 0) {
            php_printf("收到的所有%d数据：%s",length,response);
            break;
        } else {
            php_printf("出错了\n");
            break;
        }
    }
    close(clientfd);
    close(socketfd);
}