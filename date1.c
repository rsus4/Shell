#include<stdio.h>
#include<time.h>
#include<string.h>

int main(int argc,char **argv)
{


  struct tm *timid;
  time_t t1;
  t1 = time(NULL);

  if(argv[1]==NULL){ 
  timid = localtime(&t1);
  printf("Time %s", asctime(timid));
  }
  else if(strcmp(argv[1],"-u")==0){  
  timid = gmtime(&t1);
  printf("UTC time: %s", asctime(timid));
  }
  else if(strcmp(argv[1],"--help")==0){
    printf("Usage: date [OPTION]\n -u, print Coordinated Universal Time(UTC)\n --help\tdisplay this help and exit\n");

  }

  return 0;
}

