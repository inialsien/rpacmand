#include"../include/options.h"


void parse_arguments(int argc, char** argv)
{
  //Setup options default values.
  extern cli_options_values prg_options_values;

  prg_options_values.descriptor_path = DEFAULT_DESCRIPTOR;
  
  prg_options_values.ipaddress = DEFAULT_HOST;
  prg_options_values.port = DEFAULT_PORT;     
  prg_options_values.service = DEFAULT_RPC_SERVICE;
          
  prg_options_values.timeout = DEFAULT_TIMEOUT;
  prg_options_values.max_retry = DEFAULT_MAX_RETRY;

  extern cli_options_flags prg_options_flags;

  memset(&prg_options_flags, 0, sizeof(cli_options_flags));

  extern char* optarg;
  extern int optind, opterr, optopt;
  extern const char* getopt_str;
  extern struct option cli_options[];

  int c;
  int opt_index = 0;
  

  while((c = getopt_long(argc, argv, getopt_str, cli_options, &opt_index)) != -1){

    switch(c){
      case 0:
      break;
      case 'd':
        //Retrieve device path.
	if(optarg != NULL && strlen(optarg) > 0) {
	  prg_options_values.descriptor_path = strdup(optarg);
	}else{
	  fprintf(stdout, BAD_PARAMETER_ASCII_VALUE);	
	}
      break;
      case 'i':
        //Retrieve ipaddress.
	if(optarg != NULL && strlen(optarg) > 0) {
	  prg_options_values.ipaddress = strdup(optarg);
	}else{
	  fprintf(stdout, BAD_PARAMETER_ASCII_VALUE);	
	}
      break;
      case 'p':
        //Retrieve port.
	if(optarg != NULL && strlen(optarg) > 0) {
	  prg_options_values.port = strdup(optarg);
	}else{
	  fprintf(stdout, BAD_PARAMETER_ASCII_VALUE);	
	}
      break;      
      case 's':
        //Retrieve service.
	if(optarg != NULL && strlen(optarg) > 0) {
	  prg_options_values.service = strdup(optarg);
	}else{
	  fprintf(stdout, BAD_PARAMETER_ASCII_VALUE);	
	}
      break;
      case 'o':
        prg_options_values.timeout = atoi(optarg);
	
	if(prg_options_values.timeout < 0){
          fprintf(stdout, BAD_PARAMETER_NUMERIC_VALUE);
	  exit(1);
	}
      break;
      case 'r':
	prg_options_values.max_retry = atoi(optarg);

	if(prg_options_values.max_retry < 0){
          fprintf(stdout, BAD_PARAMETER_NUMERIC_VALUE);
	  exit(1);
	}
      break;
      
      case 'l':
        //display eligible devices list.
        prg_options_flags.device_list = 1;

      break;
      case 'q':
	//Display available pids information.
        prg_options_flags.pid_list = 1;
      break;
      case 'h':
        //display_help
	prg_options_flags.help = 1;
      break;
      case 'v':
        //display_version	
        prg_options_flags.version = 1;
      break;
      case 'x':	
        prg_options_flags.execute = 1;
      break;
      default :
	fprintf(stdout, BAD_PARAMETER_MSG);
        exit(1);
      break;
    }
   }
	fprintf(stdout, "cli_options_values{\n\
\tdescriptor_path=%s\n\
\tipaddress=%s\n\
\tport=%s\n\
\tservice=%s\n\
\ttimeout=%d\n\
\tmax_retry=%d\n\
}\n",prg_options_values.descriptor_path, prg_options_values.ipaddress, prg_options_values.port, prg_options_values.service, prg_options_values.timeout, prg_options_values.max_retry);


}


unsigned short int cli_get_timeout()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.timeout;
}


unsigned short int cli_options_get_timeout(cli_options_values prg_options_values)
{
  return prg_options_values.timeout;
}


unsigned short int cli_get_max_retry()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.max_retry;
}


unsigned short int cli_options_get_max_retry(cli_options_values prg_options_values)
{
  return prg_options_values.max_retry;
}


char* cli_get_descriptor_path()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.descriptor_path;
}


char* cli_options_get_descriptor_path(cli_options_values prg_options_values)
{
  return prg_options_values.descriptor_path;
}


char* cli_get_ipaddress()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.ipaddress;
}


char* cli_options_get_ipadress(cli_options_values prg_options_values)
{
  return prg_options_values.ipaddress;
}


char* cli_get_port()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.port;
}


char* cli_options_get_port(cli_options_values prg_options_values)
{
  return prg_options_values.port;
}


char* cli_get_service()
{
  extern cli_options_values prg_options_values;
  
  return prg_options_values.service;
}


char* cli_options_get_service(cli_options_values prg_options_values)
{
  return prg_options_values.service;
}


cli_options_values get_prg_options_values()
{
  extern cli_options_values prg_options_values;

  return prg_options_values;
}


short int get_prg_flag_help()
{
  extern cli_options_flags prg_options_flags;

  return prg_options_flags.help;
}


short int cli_options_get_prg_flag_help(cli_options_flags prg_options_flags)
{
  return prg_options_flags.help;
}


short int get_prg_flag_version()
{
  extern cli_options_flags prg_options_flags;

  return prg_options_flags.version;
}


short int cli_options_get_prg_flag_version(cli_options_flags prg_options_flags)
{
  return prg_options_flags.version;
}


short int get_prg_flag_pid_list()
{
  extern cli_options_flags prg_options_flags;

  return prg_options_flags.pid_list;
}


short int cli_options_get_prg_flag_pid_list(cli_options_flags prg_options_flags)
{
  return prg_options_flags.pid_list;
}


short int get_prg_flag_device_list()
{
  extern cli_options_flags prg_options_flags;

  return prg_options_flags.device_list;
}


short int cli_options_get_prg_flag_device_list(cli_options_flags prg_options_flags)
{
  return prg_options_flags.device_list;
}


short int get_prg_flag_execute()
{
  extern cli_options_flags prg_options_flags;
    
  return prg_options_flags.execute;   
}


short int cli_options_get_prg_flag_execute(cli_options_flags prg_options_flags)
{
  return prg_options_flags.execute; 
}


cli_options_flags get_prg_options_flags()
{
  extern cli_options_flags prg_options_flags;

  return prg_options_flags;
}
