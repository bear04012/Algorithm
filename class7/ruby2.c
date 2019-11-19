#include <stdio.h>

int ary[10000];
int bag = 14;
int jewerly[4][2] = {{2, 40}, {5, 110}, {10, 200}, {3, 50}};
int used[4];

int main(int argc, char **argv)
{
  int i, j,c;
  // for (i = 0; i <= bag; i++)
  // {
  //   for (j = 0; j < 4; j++)
  //   {
  //     // if (i - jewerly[j][0] >= 0)
  //     // {
  //     //   if (ary[i] < ary[i - jewerly[j][0]] + jewerly[j][1])
  //     //     ary[i] = ary[i - jewerly[j][0]] + jewerly[j][1];
  //     // }
  //     if (i-jewerly[j][0]>=0) {

  //     }
  //   }
  //   printf("%d \n", ary[i]);
  // }

  for (i = 0; i < 4; i++) {
    for (j =bag; j >= jewerly[i][0]; j--) {
      if (ary[j-jewerly[i][0]] + jewerly[i][1]>ary[j]) {
        ary[j] = ary[j - jewerly[i][0]] + jewerly[i][1];
      }
      // if (j-jewerly[i][0]>=0) {

      // }
    }

    printf("---------------------\n");
    for (c = 0; c <= bag; c++)
    {
      printf("%d \n", ary[c]);
    }
  }
  // for (i = 0; i <= bag; i++) {
  //   for (j = 0; j < 4; j++) {
  //     if (ary2[i]>=jewerly[j][0]) {
  //       ary[i] += jewerly[j][1];
  //     }
  //   }
  // }
  
  return 0;
}
