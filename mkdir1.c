

//			This is an implementation of the mkdir call
//	Errors handled:
//		a)Checks if atleast 1 argument is given
//		b)Checks if the directory doesn't exist previously
//
//	Command options provided:
//		a) -help It displays the help related information and exits.
//		b) -v It displays a message for every directory created..

#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int d_exists(const char *path)
{
    struct stat probs;
    stat(path, &probs);
    if (S_ISDIR(probs.st_mode)){
        return 0;
    }
    return 1;
}


void main(int argc,char **argv)
{

	if(argv[1]==NULL){
	printf("Error: Please provide an argument\n");
	}

	else{


		if(strcmp(argv[1],"--help")==0){
			printf("\nUsage: mkdir [OPTION]... DIRECTORY...\nCreate the DIRECTORY(ies), if they do not already exist.\n\nMandatory arguments to long options are mandatory for short options too.\n-v, --verbose     print a message for each created directory\n--help     display this help and exit\n\nGNU coreutils online help: <https://www.gnu.org/software/coreutils/>\nFull documentation at: <https://www.gnu.org/software/coreutils/mkdir>\nor available locally via: info '(coreutils) mkdir invocation'\n\n");
										}


	else if(argv[2]==NULL){

	if(d_exists(argv[1])){
	int check;
	char* dirname=argv[1];
	check=mkdir(dirname,0777);

	if(!check){
		printf("Directory madee\n");
	}
	else{
	printf("Directory not made\n");
	exit(1);
	}
	system("dir");	
	}
	else{
		printf("mkdir: cannot create directory %s: File exists\n",argv[1]);
	}
	
	}



	else if(strcmp(argv[2],"-v")==0){

	if(d_exists(argv[1])){
	int check;
	char* dirname=argv[1];
	check=mkdir(dirname,0777);

	if(!check){
		printf("mkdir: created directory %s",argv[1]);
		printf("Directory madee\n");
	}
	else{
	printf("Directory not made\n");
	exit(1);
	}
	system("dir");
	}
	else{
		printf("mkdir: cannot create directory %s: File exists\n",argv[1]);
	}

	
	}


	}

}
