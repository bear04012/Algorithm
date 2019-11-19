#include <stdio.h>

int ary[10000];
int main(int argc, char **argv)
{
  int i,j;
  int alive = 1, start = 0;
  int cnt;
  int a = 2, b = 4, c = 6, N = 6;

  for (i = 0; i < N; i++) {
    for (j = alive-1; j >= start; j--) {
      ary[j]++;
      if (ary[j] >= a && ary[j] < b)
      {
        alive++;
      }else if (ary[j]==6) {
        start++;
      }
    }
    for (j = start; j < alive; j++)
    {
      printf("%d ", ary[j]);
    }
    printf("\n");
  }

  printf("\nalive is: %d\n",alive-start);

  return 0;
}
