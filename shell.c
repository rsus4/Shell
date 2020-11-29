#include<string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include<dirent.h>


int my_cd(char **args);
int my_pwd(char **args);
int my_exit(char **args);
int my_history(char ** args);
int my_echo(char ** args);

char history[100][100*sizeof(char*)];
int history_index=0;

int d_exists(const char *path)
{
    struct stat probs;
    stat(path, &probs);
    if (S_ISDIR(probs.st_mode)){
        return 0;
    }
    return 1;
}



int my_pwd(char ** args){

  if(args[1]==NULL){
  char fortnite[100]; 
    getcwd(fortnite, sizeof(fortnite)); 
    printf("Directory: %s", fortnite); 
    printf("\n");
  }

  else if(strcmp(args[1],"-P")==0){
  char fortnite[100]; 
    getcwd(fortnite, sizeof(fortnite)); 
    printf("Directory: %s", fortnite); 
    printf("\n");
  }

  else if(strcmp(args[1],"-L")==0){
    char fortnite[100]; 
    getcwd(fortnite, sizeof(fortnite)); 
    printf("Directory: %s", fortnite); 
    printf("\n");
  }

  return 1;

}

int my_cd(char **args){

  char s[100]; 
  if (args[1] == NULL || strcmp(args[1],"~")==0) {
    chdir(getenv("HOME"));
    printf("%s\n", getcwd(s, 100)); 
  } 
  else {
    if(args[2]!=NULL){
    fprintf(stderr, "cd takes only one argument\n");
  }
  else{
    if(!d_exists(args[1]) | strcmp(args[1],"..")==0){
      chdir(args[1]); 
       printf("%s\n", getcwd(s, 100)); 
    }
    else{
      printf("Error: No such directroy exists\n");
    }
  }
  }
  return 1;
}



int my_exit(char ** args){
	return 0;
}


int my_echo(char **args){
// echo -n string 

if(args[1]==NULL){
  printf("\n");
}
else{
  if(strcmp(args[1],"-n")==0){
    int index1=2;
    while(1){
      if(args[index1]==NULL){
        break;
      }
      index1=index1+1;
    }

    for(int i=2;i<index1;i++)
    {
       printf("%s ",args[i]);
    }
  }

  else if(strcmp(args[1],"*")==0){
    struct dirent *fall;
    DIR *directory1;
    directory1 = opendir("."); /*your directory*/
    while(directory1)
    {
        fall = readdir(directory1);
        if (!fall) break;
        if(fall->d_name[0]!='.'){
          printf("%s ", fall->d_name);
        }
        
    }
    closedir(directory1);
    printf("\n");
  }

  else {
    int index1=1;
    while(1){
      if(args[index1]==NULL){
        break;
      }
      index1=index1+1;
    }

    for(int i=1;i<index1;i++)
    {
       printf("%s ",args[i]);
    }
    printf("\n");

  } 
}
}

int my_history(char **args){
  if(args[1]==NULL){
    for(int i=0;i<history_index;i++){
        printf("%s",history[i]);
      }
  }
  else if(args[1]=="-c"){
      printf("HEELLOO");
      history_index=0;
  }
  
  return 1;
}

int launch_external(char **args)
{
  pid_t pid1;
  int status;
  pid1 = fork();
  if (pid1 == 0) {
    if (execvp(args[0],args)==-1) {
     	 perror("Error");
    }
    exit(EXIT_FAILURE);
  				 } 

  else if (pid1 < 0) {
    perror("Error");
  					} 
  else {
    do { 
    wait(NULL); 
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  		}
  return 1;
}


int execute(char **args)
{
  int i;
  if (args[0] == NULL) {
    return 1;
  }
  	if (strcmp(args[0],"cd")==0){
  		return my_cd(args);
  	}
  	if (strcmp(args[0],"pwd")==0){
  		return my_pwd(args);
  	}
  	if (strcmp(args[0],"exit")==0){
  		return my_exit(args);
  	}
  	if (strcmp(args[0],"echo")==0){
  		return my_echo(args);
  	}
  	if (strcmp(args[0],"history")==0){
  		return my_history(args);
  	}

  char path[]="/home/rishitgupta/Desktop/Assignment1/Q2Final/";
  strcat(path,args[0]);
  args[0]=path;
  // printf("%s\n",args[0]);
  return launch_external(args);
}

char *read_line(){
char *line=NULL;
ssize_t size1=0;
if(getline(&line,&size1,stdin)==-1){
  if(feof(stdin)){
    exit(EXIT_SUCCESS);
  }
  else{
    perror("Error 1: ");
    exit(EXIT_FAILURE);
  }
}
strcpy(history[history_index],line);
history_index=history_index+1;
return line;
}

char **split1(char *input){
int size1=64;
int index=0;
char **splitted_array=malloc(100*sizeof(char*));
char *token;
token=strtok(input," \n");
  while(token!=NULL){
    splitted_array[index]=token;
    index++;
    token=strtok(NULL," \n");
  }
splitted_array[index]=NULL;
splitted_array[index+1]=NULL;
splitted_array[index+2]=NULL;
return splitted_array; 
}

int main(){
char *input;
char **argument_after_parse;
int while_status;

do{
	printf("@Rishits-MacBook-Pro >");
	input=read_line();
	argument_after_parse=split1(input);


	while_status=execute(argument_after_parse);
	free(input);
	free(argument_after_parse);
}while(while_status);
	return 0;
}
