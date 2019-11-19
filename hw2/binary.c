#include <stdio.h>

// int ary[5000];

void convertToBinary(int);

int main(int argc, char **argv)
{
  int i,index;

  convertToBinary(58);
  
  printf("\n");


  // index = convertToBinary(58,0);

  // for (i = index; i>=0; i--) {
  //   printf("%d",ary[i]);
  // }

  return 0;
}

// int convertToBinary(int num,int index) {
//   if (num<2) {
//     // printf("1");
//     ary[index] = 1;
//     printf("index: %d\n",index);
//     return index;
//   } else {
//     // printf("%d",num%2);
//     ary[index] = num%2;
//     return convertToBinary(num/2,index+1);
//   }
// }


void convertToBinary(int num) {
  if (num<2) {
    printf("%d", num);
  } else {
    convertToBinary(num/2);
    printf("%d",num%2);
  }
}