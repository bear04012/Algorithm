#include <stdio.h>

#define N 10000
#define max(a, b) (a > b ? a : b)
#define max3(a, b, c) (max(max(a,b),c))

int n, triangle[N][N];
int ary[N][N];

void input() {
  int i, j;
  FILE *file1 = fopen("triangle.txt", "r");
  fscanf(file1, "%d", &n);

  for (i = 0; i < n; i++)
  {
    for (j = 0; j <= i; j++)
    {
      fscanf(file1, "%d", &triangle[i][j]);
    }
  }
  fclose(file1);
}

void output()
{
  int i, j;
  FILE *file2 = fopen("triangle_output.txt", "w");

  for (i = 0; i < n; i++)
  {
    for (j = 0; j <= i; j++)
    {
      fprintf(file2, "%d ", ary[i][j]);
    }
    fprintf(file2,"\n");
  }
  fclose(file2);
}

int main(int argc, char **argv)
{
  int i, j;
  input();
  ary[0][0] = triangle[0][0];
  for (i = 1; i < n; i++)
  {
    for (j = 0; j <= i; j++)
    {
      if (j>0 && j<i) {
        
        ary[i][j] = max(ary[i - 1][j - 1], ary[i - 1][j]) + triangle[i][j];

      }else if(j==0) {
        ary[i][j] = ary[i - 1][0]+triangle[i][j];
      } else {
        ary[i][j] = ary[i - 1][j - 1]+triangle[i][j];
      }
    }
  }


  
  output();
  return 0;
}