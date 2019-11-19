#include <stdio.h>

#define max(a,b) a>b?a:b

int ary[10000];
int N = 6;
int stairs[7] = {0, 10, 20, 15, 25, 10, 20};

int main(int argc, char **argv)
{
  int i;
  int cnt;
  ary[0] = 10;

  for (i = 0; i <= N; i++)
  {
    if (i <= 1) {
      ary[i] = stairs[i];
    }else if (i == 2){
      ary[i] = stairs[1] + stairs[2];
    }else {
      ary[i] = max(ary[i - 3] + stairs[i - 1] + stairs[i], ary[i - 2] + stairs[i]);
    }
  }

  for (i = 0; i <= N; i++) {
    printf("%d ", ary[i]);
  }
  printf("\n");

  return 0;
}
