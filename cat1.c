
//			This is an implementation of the cat call
//	Errors handled:
//		a)Checks if atleast 1 argument is given
//		b)Checks if file exists or not
//
//	Command options provided:
//		a) -c It will show content with line number.
//		b) -E Will highlight the end of line.



#include<stdio.h>
#include<string.h>

int does_not_exist(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 0;
    }
    return 1;
}

void main(int argc,char **argv){


if(argv[1]==NULL){
	printf("Error: Please provide an argument\n");
}
else{


	if(does_not_exist(argv[1])){
		printf("Error: This file does not exist in the current directory\n");
	}

	else{

		if(argv[2]==NULL){
	FILE *file;
	char line[100];
	file=fopen(argv[1],"r");
	while(fscanf(file,"%[^\n]\n",line)!=EOF){
	printf("%s\n",line);
	}
	fclose(file);
	}

	else if(strcmp(argv[2],"-n")==0){
	FILE *file;
	char line[100];
	file=fopen(argv[1],"r");
	int index=1;
	while(fscanf(file,"%[^\n]\n",line)!=EOF){
	printf("%d",index);
	printf(") ");	
	printf("%s\n",line);
	index=index+1;
	}
	fclose(file);
	}

	else if(strcmp(argv[2],"-E")==0){

	FILE *file;
	char line[100];
	file=fopen(argv[1],"r");
	int index=1;
	while(fscanf(file,"%[^\n]\n",line)!=EOF){
	printf("%s$\n",line);
	index=index+1;
	}
	fclose(file);
	}

	}
	
}
	
}
