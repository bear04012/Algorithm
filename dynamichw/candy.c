#include <stdio.h>

#define N 10000
#define max(a, b) (a > b ? a : b)
#define max3(a, b, c) (max(max(a, b), c))
int r, c;
int board[100][100];
int record[100][100];
void input()
{
  int i, j;
  FILE *file1 = fopen("candy.txt", "r");
  fscanf(file1, "%d %d", &r,&c);

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      fscanf(file1, "%d", &board[i][j]);
    }
  }
  fclose(file1);
}

void output()
{
  int i, j;
  FILE *file2 = fopen("candy_output.txt", "w");

  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++)
    {
      fprintf(file2, "%d ", record[i][j]);
    }
    fprintf(file2, "\n");
  }
  fclose(file2);
}

int main(int argc, char **argv)
{
  int i, j;
  input();
  record[0][0] = board[0][0];
  for (i = 0; i < r; i++)
  {
    for (j = 0; j < c; j++) {
      if (i<1 && j>0) {
        record[i][j] = record[i][j - 1] + board[i][j];
      } else if (i>0 && j==0) {
        record[i][j] = record[i - 1][j] + board[i][j];
      } else {
        record[i][j] = max3(record[i - 1][j], record[i][j - 1], record[i - 1][j - 1]) + board[i][j];
      }
    }
    
  }

  output();

  return 0;
}