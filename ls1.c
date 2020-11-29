#include <dirent.h>
#include<stdio.h>
#include<string.h>
// ./ls1 -a 
int main(int argc, char **argv)
{
    struct dirent *fall;
    DIR *directory1;
//printf("HIII\n");
    if(argv[1]==NULL){
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

    else if(strcmp(argv[1],"-a")==0){
    directory1 = opendir("."); /*your directory*/
    while(directory1)
    {
        fall = readdir(directory1);
        if (!fall) break;
        printf("%s ", fall->d_name);
        
    }
    closedir(directory1); 
     printf("\n");


    }

    else if(strcmp(argv[1],"-1")==0){
            directory1 = opendir("."); /*your directory*/
    while(directory1)
    {
        fall = readdir(directory1);
        if (!fall) break;
        if(fall->d_name[0]!='.'){
          printf("%s\n", fall->d_name);
        }
    }
    closedir(directory1);
    }

    // else
    // {
    // directory1=opendir(argv[1]);
    // while(directory1){
    //     fall = readdir(directory1);
    //     if(!fall){
    //     break;
    //     }
    //     if(fall->d_name[0]!='.'){
    //       printf("%s\n", fall->d_name);
    //     }  
    // }
    // closedir(directory1);
    // }

    


// else{
// 	directory1=opendir(argv[1]);
// 	while(directory1){
// 		fall = readdir(directory1);
// 		if(!fall){
// 		break;
// 		}
// 		printf("%s",fall->d_name);	
// 	}
// 	closedir(directory1);
//      printf("\n");

// 	}

   
    return 1;
    
}
