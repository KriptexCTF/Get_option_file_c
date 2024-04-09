#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
int main(int argc, char** argv){
	int flag_s = 0, flag_h = 0, flag_f = 0, flag_d = 0;
	char* ip; 
	const char* short_options = "ihs:f:d:";
	const struct option long_options[] = {
		{"help", no_argument, NULL, 'h'},
		{"scan_port", required_argument, NULL, 's'},
		{"file_name", required_argument, NULL, 'f'},
		{"file_daata", required_argument, NULL, 'd'},
		{NULL, 0, NULL, 0}
	};
	int arr_size = 5;
	FILE* file;
	int r = 0;
	int option_index = 0;
	while((r = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1){
		switch(r){
			case 'f':
				if((flag_f == 0)&(optarg[0] != '-')){
					file = fopen(optarg, "w");
					printf("FILE %s createed!\n", optarg);	
					flag_f += 1;
				}
				else if(flag_f > 0){
					printf("To many -f / --file_name arg!\n");
				}
				else{
					printf("error\n");
				}
				break;
			case 'd':
				if(flag_f == 1){
					fputs(optarg, file);
					printf("Writing to file completed!\n");
					fclose(file);
					flag_d += 1;
				}
				else{
					printf("No -f / --file_name arg!\n");
				}
				break;
			case 's':
				if(flag_h == 0){
					if(flag_h == 0){
						if(flag_s < 1){
							printf("IP: %s\nStart scaning...\n", optarg);
							sleep(1);
							printf("Complited!\n");
						}
						if(flag_s == 1){printf("To many -s arguments!\n");}
					}
				}
				else if(flag_h >= 1){printf("You cannot use scaning and help manual at the same time.\n");}
				flag_s += 1;
				break;
			case 'h':
				if(flag_s == 0){
					printf("You can use:\n");
					for(int i = 0; i < arr_size - 1; i++){
						printf("   --%s, %d, -%c\n",
							long_options[i].name,
							long_options[i].has_arg,
							long_options[i].val
						);
					}
				}
				else if(flag_s == 1){printf("You cannot use scaning and help manual at the same time.\n");}
				flag_h += 1;
				break;
			case '?':
				printf("Try --help / -h for help.\n");
				break;
			default:
				printf("No arguments!\n");
				return 0;
		}
	}
	if(argc == 1){
		printf("No arguments!\n");
		return 0;

	}
}
