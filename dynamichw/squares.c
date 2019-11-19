#include <stdio.h>

int ary[4][200000];

void lagrange(int);

void printout(int);

int main(int argc, char **argv)
{
  int i, j;
  ary[0][1] = 1;
  ary[1][2] = 1;
  ary[2][3] = 1;
  ary[3][4] = 1;
  for (i = 2; i < 256; i++)
  {
    lagrange(i);
  }
  printf("\n");
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 50; j++) {
      printf("%d", ary[i][j]);
    }
    printf("\n");
  }

  printout(8);
  printout(25);
  printout(2003);
  printout(211);
  printout(20007);
  return 0;
}

void lagrange(int num) {
  int i,j;
  ary[0][num * num]++;
  int cnt = 0;
  int sum = 0;
  // for (i = 1; i <= 4; i++)
  // {
  //   sum += num * i;
  //   ary[cnt++][sum]++;
  // }
  for (i = 0; i < 3; i++) {
    for (j = 32768; j >= 0; j--) {
      if (ary[i][j]>=1) {
        ary[i + 1][j + (num * num)] += ary[i][j];
      }
    }
  }
}
void printout(int num) {
  int i,n=0;

  for (i = 0; i < 4; i++)
  {
    n += ary[i][num];
  }

  printf("%d: %d\n",num,n);

}