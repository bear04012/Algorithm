#include <stdio.h>
#include <stdlib.h>

void dice(int, int,int);

int dices[1000];


int main(int argc, char **argv)
{
  int index=0;
  // int SizeOfArray;
  // int *arr;

  // printf("만들고 싶은 배열의 원소의 수 : ");
  // scanf("%d", &SizeOfArray);

  // arr = (int *)malloc(sizeof(int) * SizeOfArray);
  // // int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성

  // free(arr);

  dice(6,5,index);

  return 0;
}

void dice (int n, int sum, int index) {
  int i;
  if (sum==0&& n==0) {
    for (i=1; i<=index; i++) {
      printf("%d",dices[i]);
    }
    printf("\n");
    return;
  }else if (n<=0 && sum!=0) {
    return;
  } else {
    index++;

    dices[index] = 1;
    dice(n-1,sum-1,index);

    dices[index] = 2;
    dice(n-1,sum-2,index);

    dices[index] = 3;
    dice(n-1,sum-3,index);

    dices[index] = 4;
    dice(n-1,sum-4,index);

    dices[index] = 5;
    dice(n-1,sum-5,index);

    dices[index] = 6;
    dice(n-1,sum-6,index);

  }

 
}