#ifndef _obdii_rpacmand_h_
#define _obdii_rpacmand_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include <xmlrpc-c/base.h>
#include <xmlrpc-c/client.h> 


#define DEFAULT_HOST "localhost"
#define DEFAULT_PORT "9090"
#define DEFAULT_RPC_SERVICE "RPC2"

#define DEFAULT_METHOD "uploadData"

#define CLIENT_NAME "rPacman Daemon"
#define CLIENT_VERSION "1.0" 

#define MSG_INIT "Initializing OBDII Connection"
#define MSG_CLOSE "Closing OBDII Connection"

#define MSG_PIDLIST "Retrieving available OBDII pids"
#define MSG_EXECUTE "Retrieving information from OBDII databus"


char* generate_url(char* ip_address, char* port, char* rpc_service);

char* generate_url_std(char* ip_address, char* port);

#endif