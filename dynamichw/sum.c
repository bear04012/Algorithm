#include <stdio.h>
#define max(a,b) (a>b?a:b)

int ary[10000];
int N = 12;
int ary2d[2][3] = {{1, 2, 4}, {8, 16, 32}};
int sum2d[2][3];
int location[3][4] = {{1, 1, 2, 3}, {1, 2, 1, 2}, {1, 3, 2, 3}};

int main(int argc, char **argv)
{
  int i,j,r=2,c=3,x1,y1,x2,y2;
  int cnt;
  sum2d[0][0] = ary2d[0][0];
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++) {
      if (i==0 &&j>0) {
        sum2d[i][j] = sum2d[i][j - 1] + ary2d[i][j];
      }else if(j==0&& i>0){
        sum2d[i][j] = sum2d[i - 1][j] + ary2d[i][j];
      }else {
        sum2d[i][j] = sum2d[i - 1][j] + sum2d[i][j - 1] - sum2d[i - 1][j - 1] + ary2d[i][j];
      }
    }
  }
  for (i = 0; i < 3; i++) {
    y1 = location[i][0]-1;
    y2 = location[i][2]-1;
    x1 = location[i][1]-1;
    x2 = location[i][3]-1;
    if (x1>0 && y1>0) {
      ary[i] = sum2d[y2][x2] - sum2d[y1 - 1][x2] - sum2d[y2][x1 - 1] + sum2d[y1 - 1][x1 - 1];
    } else if (x1>0) {
      ary[i] = sum2d[y2][x2] - sum2d[y2][x1 - 1];
    } else if (y1>0) {
      ary[i] = sum2d[y2][x2] - sum2d[y1 - 1][x2];
    }else {
      ary[i] = sum2d[y2][x2];
    }
  }
  // for (i = 0; i < r; i++) {
  //   for (j = 0; j < c; j++) {
  //     printf("%d ", sum2d[i][j]);
  //   }
  //   printf("\n");
  // }

  for (i = 0; i < 3; i++)
  {
    printf("%d\n", ary[i]);
    }

  return 0;
}