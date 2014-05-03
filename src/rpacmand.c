#include"../include/rpacmand.h"

char* generate_url(char* ip_address, char* port, char* rpc_service)
{
    const char* protocol = "http://";
    unsigned int length = 0;
    char* url;
    char* url_tmp;
    length = strlen(protocol) + strlen(ip_address) + strlen(port) + 3 + strlen(rpc_service);
    url = (char*) malloc(sizeof(char)*length);
    
    if(url != NULL){
        url_tmp = url;
        memset(url_tmp, '\0', sizeof(char)*length);    
        
        memcpy(url_tmp, protocol, sizeof(char)*strlen(protocol));    
        url_tmp += strlen(protocol);
        memcpy(url_tmp, ip_address, sizeof(char)*strlen(ip_address));    
        url_tmp += strlen(ip_address);
        *url_tmp = ':';
        url_tmp++;
        memcpy(url_tmp, port, sizeof(char)*strlen(port));    
        url_tmp += strlen(port);
        *url_tmp = '/';
        url_tmp++;
        memcpy(url_tmp, rpc_service, sizeof(char)*strlen(rpc_service));    
    }
    
    return url;
}



char* generate_url_std(char* ip_address, char* port)
{
    return generate_url(ip_address, port, DEFAULT_RPC_SERVICE);
}