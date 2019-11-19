#include <stdio.h>

int ary[10000];
int ary2[10000];
int N = 12;

int main(int argc, char **argv)
{
  int i, j;
  ary[0] = 1;
  // ary[2] = ary2[2 - 1] + ary2[2 - 1] + ary[0];
  // ary[2] = 3;
  ary2[1] = 1;
  // ary2[3] = ary[3 - 1] + ary2[3 - 1];
  // ary[4] = ary2[4 - 1] + ary2[4 - 1] + ary[2];
  for (i = 2; i <= N; i++)
  {
    ary[i] = ary2[i - 1] + ary2[i - 1] + ary[i - 2];
    ary2[i] = ary[i - 1] + ary2[i - 2];

  }

  for (i = 0; i <= N; i++)
  {
    printf("%d\n", ary[i]);
  }

  return 0;
}
