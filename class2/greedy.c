#include <stdio.h>
#include <stdlib.h>

int greedy(int, int*,int);

int main(int argc, char **argv)
{
  int i, N,C, result;
  int *ary;
  double num;

  printf("Num of types of coins: \n");
  scanf("%d", &N);

  printf("Total Cost: \n");
  scanf("%d", &C);

  ary = (int *)malloc(sizeof(int) * N);

  for (i = 0; i < N; i++) {
    printf("%d.coin: \n",i);
    scanf("%d", &ary[i]);
  }
  result = greedy(N, ary, C);

  printf("the total numbers of coin: %d\n", result);

  return 0;
}

int greedy(int N, int* ary, int totalCost) {
  int n = 0;
  int index = N - 1;
  while (totalCost != 0)
  { 
    if (totalCost>=ary[index]) {
      totalCost -= ary[index];
      n++;
    } else {
      index--;
    }
  }
  return n;

}
