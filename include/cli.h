#ifndef _obdii_cli_h_
#define _obdii_cli_h_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../lib/libobdii.h"


#define PRG_NAME "rpacmand"
#define PRG_VERSION "v0.1-251213"
#define PRG_AUTHOR "Pierre LEROY <leroy.pierre1@gmail.com>"

#define USAGE "USAGE : -x [-d path -i ipaddress -p port -s service]\n\
\n\
     -x | --execute          - launch this program and send data\n\
\n\
     -d | --device path      - specify the descriptor to use\n\
     -l | --device-list      - display all eligibe descriptor to use\n\
\n\
     -i | --ipaddress        - specify the ip address to use\n\
     -p | --port             - specify the port to use\n\
     -s | --service          - specify the name of service to use\n\
\n\
     -q | --pid-list         - display all pid information\n\
     -o | --timeout X        - set timeout to X\n\
     -r | --max-retry Y      - set max retry to Y\n\
\n\
     -h | --help             - display this help\n\
     -v | --version          - display information about program version\n\n"


void display_usage();

void display_version();

void display_device_list();

#endif

