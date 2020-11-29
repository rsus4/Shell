

//			This is an implementation of the rm call
//	Errors handled:
//		a)Checks if atleast 1 argument is given
//		b)Checks if the argument given is a file and not a directory
//
//	Command options provided:
//		a) -i Provides an interactive prompt before removing file.
//		b) -v Displays the name of each file as it is removed.
#include<stdio.h> 
#include<string.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int exists(const char* name)
{
	//returns 0 if the file is a directory
	//returns1 if the file is a file and not a directory
    DIR* Mydirectory = opendir(name);
    if(Mydirectory != NULL)
    {
     closedir(Mydirectory);
     return 0;
    }
    if(errno == ENOTDIR)
    {
     return 1;
    }
    return -1;
}

int main(int c, char *argv[]) 
{ 
	
if(argv[1]==NULL){
	printf("Error: Please provide an argument\n");
}

else{
	
	//No argument with rm
	if(argv[2]==NULL){
	if(exists(argv[1])==1){
		printf("File removed");
    	remove(argv[1]);    
    	}
    	else{
    	printf("Error: Use rmdir to remove directories\n");
	}
}



	// -i Provides an interactive prompt before removing file.
	else if(strcmp(argv[2],"-i")==0){
	
	if(exists(argv[1])==1){
		printf("rm: remove regular empty file %s ? (y/n) \n",argv[1]);
		char a;
		scanf("%c",&a);
		if(a=='y'){
		printf("File removed\n"); 
    		remove(argv[1]);    
		}
		else{
			printf("File not removed\n");
		}
	}
	else{
			printf("Error: Use rmdir to remove directories");
		}
	} 



	// -v Displays the name of each file as it is removed.
	else{
		if(exists(argv[1])==1){
			printf("%s\n",argv[1]);
			printf("File removed\n");
    		remove(argv[1]);   
							  }
		else{
    	printf("Error: Use rmdir to remove directories\n");
		}

		}
		}
return 1; 

} 
