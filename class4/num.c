#include <stdio.h>
#include <string.h>



int goodNum(int,char[],int);
int checkGoodNum(char[]);
int checkletters(int,char[]);


// len = strlen(str);
// strcpy(str1,str2)
// strcat(str1,str2)
// if(strcmp(str1,str2) > 0)




int main(int argc, char **argv)
{ 
  int N,num;
  char str[100] = {0,};

  // printf("Notation: \n");
  // scanf("%d", &N);

  goodNum(9,str,0);

  printf("%s\n", str);

  // char str[50] = "12131";
  // i = checkGoodNum(str);
  // printf("%d\n",i);

  return 0;
}

int goodNum(int n, char str[],int index) {

  if (!checkGoodNum(str)) {
    return 0;
  }else if(n==0) {
    return 1;
  }

  str[index] = '1';
  if(goodNum(n-1,str,index+1))
    return 1;
  str[index] = '2';
  if(goodNum(n-1,str,index+1))
    return 1;
  str[index] = '3';
  if(goodNum(n-1,str,index+1))
    return 1;

  str[index] = '\0';

  return 0;

}

int checkGoodNum(char str[]) {
  int num = 1, len;
  len = strlen(str);
  while (num<=len/2) {
    if(!checkletters(num,str)) {
      return 0;
    }
    num++;
  }
  return 1;
}

int checkletters(int num, char str[]) {
  int i,j,len;
  char temp[1000],cmp[1000];
  len = strlen(str);
  for (i=0; i<len-num; i++) {

    for(j=0; j<num; j++) {
      if(str[i+j] != str[i+num+j])
        break;
    }
    if(j == num)
      return 0;

    // strncpy(temp,str+i,num);
    // temp[num] = '\0';
    // strncpy(cmp,str+num+i,num);
    // cmp[num] = '\0';
    // if(strcmp(temp,cmp)==0) {
    //   return 0;
    // }
  }
  return 1;
}


