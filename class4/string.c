#include <stdio.h>
#include <string.h>




// len = strlen(str);
// strcpy(str1,str2)
// strcat(str1,str2)
// if(strcmp(str1,str2) > 0)




int main(int argc, char **argv)
{ 
  char str[50] = "Hello my name is yoon.";
  char str1[10];
  char str2[10];

  strncpy(str1,str,5);
  str1[5] = '\0';
  strncpy(str2,str,5);
  str2[5] = '\0';

  printf("%s \n", str);
  printf("%s \n", str1);
  printf("%d \n", strcmp(str1,str2));

  return 0;
}