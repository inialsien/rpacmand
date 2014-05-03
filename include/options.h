#ifndef __obdii_cli_options_h__
#define __obdii_cli_options_h__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<getopt.h>

#include"./rpacmand.h"

/**
 *
 */
#define DEFAULT_MAX_RETRY 5
#define DEFAULT_TIMEOUT 5 
#define DEFAULT_DESCRIPTOR "/dev/ttyUSB0"
#define DEFAULT_PIDNO 1


/**
 *
 */
#define BAD_PARAMETER_MSG "Unknown parameter, please check help (-h / --help)\n"

/**
 *
 */
#define BAD_PARAMETER_ASCII_VALUE "Bad parameter, please specify string value"

/**
 *
 */
#define BAD_PARAMETER_NUMERIC_VALUE "Bad parameter, please specify a numeric value"


/**
 * \struct This defines vars which were given by the client.
 * \brief This defines vars which were given by the client.
 */
typedef struct cli_options_values{
  char* descriptor_path;          /*!< Device descriptor path  */
  char* ipaddress;                /*!< XML-RPC ip address      */
  char* port;                     /*!< XML-RPC port            */
  char* service;                  /*!< XML-RPC service name    */
  unsigned short int timeout;     /*!< Program ask timeout     */
  unsigned short int max_retry;   /*!< Program number of retry */
} cli_options_values; 

static cli_options_values prg_options_values;


/**
 * \struct This defines vars which were set to be used by the client.
 * \brief This defines vars which were set to be used by the client.
 */
typedef struct cli_options_flags{
  short int help;                 /*!< Help flag                */
  short int version;              /*!< Program version flag     */
  short int pid_list;             /*!< Available pids list flag */
  short int device_list;          /*!< Device list flag         */
  short int execute;              /*!< Run mode flag            */
} cli_options_flags;

static cli_options_flags prg_options_flags;


static struct option cli_options[] = 
{
  //Options with required arguments.
  {"device",      required_argument, 0, 'd'},
  {"ipaddress",   required_argument, 0, 'i'},
  {"port",        required_argument, 0, 'p'},
  {"service",     required_argument, 0, 's'},
  {"timeout",     required_argument, 0, 'o'},
  {"max-retry",   required_argument, 0, 'r'},

  //Options without arguments.
  {"device-list", no_argument, 0, 'l'},
  {"pid-list",    no_argument, 0, 'q'},
  {"help",        no_argument, 0, 'h'},
  {"version",     no_argument, 0, 'v'},
  {"execute",     no_argument, 0, 'x'},
 
  //EOL
  {0,0,0,0}
};


/**
 *
 */
static const char* getopt_str = "d:i:p:s:o:r:lqhvx";


/**
 * \fn Parse all given arguments
 * \brief Parse at program launch all given arguments.
 *
 * \param argc arguments count
 * \param argv arguments tab
 *
 * \return void.
 */
void parse_arguments(int argc, char** argv);


unsigned short int cli_get_timeout();


unsigned short int cli_options_get_timeout(cli_options_values prg_options_values);


unsigned short int cli_get_max_retry();


unsigned short int cli_options_get_max_retry(cli_options_values prg_options_values);


char* cli_get_descriptor_path();


char* cli_options_get_descriptor_path(cli_options_values prg_options_values);


char* cli_get_ipaddress();


char* cli_options_get_ipadress(cli_options_values prg_options_values);


char* cli_get_port();


char* cli_options_get_port(cli_options_values prg_options_values);


char* cli_get_service();


char* cli_options_get_service(cli_options_values prg_options_values);


cli_options_values get_prg_options_values();



short int get_prg_flag_help();


short int cli_options_get_prg_flag_help(cli_options_flags prg_options_flags);


short int get_prg_flag_version();


short int cli_options_get_prg_flag_version(cli_options_flags prg_options_flags);


short int get_prg_flag_pid_list();


short int cli_options_get_prg_flag_pid_list(cli_options_flags prg_options_flags);


short int get_prg_flag_device_list();


short int cli_options_get_prg_flag_device_list(cli_options_flags prg_options_flags);


short int get_prg_flag_execute();


short int cli_options_get_prg_flag_execute(cli_options_flags prg_options_flags);


cli_options_flags get_prg_options_flags();


#endif
