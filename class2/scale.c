#include <stdio.h>
#include <stdlib.h>

int scale(int, int*, int*);

int ary[100000000000];

int main(int argc, char **argv)
{
  int N,i, smallest;
  int *weights;
  double num;

  printf("Num of weights: \n");
  scanf("%d", &N);


  weights = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) {
    printf("%d. weight", i + 1);
    scanf("%d", &weights[i]);
  }

  smallest = scale(N, weights, ary);

  printf("smallest: %d\n", smallest);



  return 0;
}

int scale(int size, int *weights, int *ary)
{
  int i,j, current,smallest,test;
  int max = 0;

  for (i = 0; i < size; i++) {
    current = weights[i];
    max+=current;
    for (j=max; j>=0; j--) {
      if (ary[j]) {
        ary[current+j] = 1;
      }
    }
    ary[current] = 1;


    for (test=1; test<=max; test++) {
      printf("%d",ary[test]);
    }
    printf("\n");
  }

  for (i=1; i<=max; i++) {
    if (!ary[i]) {
      smallest = i;
      break;
    }
  }

  return smallest;

}
