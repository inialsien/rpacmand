#include "../include/cli.h"

void display_usage()
{
  fprintf(stdout, USAGE, PRG_NAME); 
}

void display_version()
{
  fprintf(stdout, "%s %s - %s\n", PRG_NAME, PRG_VERSION, PRG_AUTHOR);
}

void display_device_list()
{
    ssize_t index = 0;
    ssize_t device_count = 0;
    
    char** devices = obdii_eligible_device_list(&device_count);
    
    for(index=0; index<device_count; index++){
        fprintf(stdout, "%d - %s\n", index, devices[index]);
        free(devices[index]);
    } 
    free(devices);
    
}
