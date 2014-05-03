#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"./include/cli.h"
#include"./include/options.h"
#include"./lib/libobdii.h"

int main(int argc, char** argv) {

    parse_arguments(argc, argv);

    if(get_prg_flag_help() > 0){
        display_usage();
    }
    else if (get_prg_flag_version() > 0){
        display_version();
    }
    else if (get_prg_flag_device_list() > 0){
        display_device_list();
    }
    else if (get_prg_flag_pid_list() > 0 || get_prg_flag_execute() > 0){
        fprintf(stdout, "%s\n",MSG_INIT);
        obdii_handler* handler =  obdii_get_handler(cli_get_descriptor_path(), 
                                                    STANDARD, 
                                                    cli_get_timeout(), 
                                                    cli_get_max_retry());
        if(handler != NULL){
            short int return_code = OBDII_ERROR;
            return_code = obdii_init(handler);
            
            fprintf(stdout, "%s\n", handler->version);
            
            if(return_code != OBDII_ERROR){
                if(get_prg_flag_pid_list() > 0){
                    // TODO : display available pid list 
                    fprintf(stdout, "%s\n", MSG_PIDLIST);

                }else if(get_prg_flag_execute() > 0){
                    fprintf(stdout, "%s\n", MSG_EXECUTE);
                }
            }

            //Closing obdii_handler.
            fprintf(stdout, "%s\n", MSG_CLOSE);
            obdii_close(handler);
            obdii_free_handler(handler);
        }
    }    
    else{
        display_usage();
    }
    /*
    
    xmlrpc_env env;
    xmlrpc_value* resultP;
    xmlrpc_int32 sum;

    xmlrpc_env_init(&env);
    xmlrpc_client_init2(&env, XMLRPC_CLIENT_NO_FLAGS, CLIENT_NAME, CLIENT_VERSION, NULL, 0);

    resultP = xmlrpc_client_call(&env, URL, DEFAULT_METHOD, "(ii)", 7);

    xmlrpc_read_int(&env, resultP, &sum);

    printf("The return code is %d\n", sum);

    xmlrpc_DECREF(resultP);
    xmlrpc_env_clean(&env);
    xmlrpc_client_cleanup();

    */

    return 0;
}
