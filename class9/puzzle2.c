#include <stdio.h>
#include <stdlib.h>

int board[8][8];
int r = 2, c = 3;
// void merge(int size, int *ary, int *ary2)
// {
//   int i, test;
//   int fInd = 0, rInd = 0, lInd = 0;
//   int *finalary = (int *)malloc(sizeof(int) * size);

//   while (1)
//   {
//     if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd] > ary2[rInd]))
//     {
//       finalary[fInd] = ary2[rInd];

//       rInd++;
//     }
//     else
//     {
//       finalary[fInd] = ary[lInd];
//       lInd++;
//     }
//     fInd++;
//     if (fInd == size)
//     {
//       break;
//     }
//   }

//   for (i = 0; i < size; i++)
//   {
//     ary[i] = finalary[i];
//   }
// }

// void fill(int size, int *ary)
// {
//   if (size == 2)
//     return;

//   fill(size / 2, ary);
//   fill((size + 1) / 2, ary + (size / 2));
//   fill();
//   fill();

//   merge(size, ary, ary + (size / 2));
// }
void fill(int, int, int, int, int);

// void put(int, int);

int main(int argc, char *argv[argc])
{
  int i, j;

  fill(0, 0, r, c, 8);
  // board[x][y] = -1;

  for (i = 0; i < 8; i++)
  {
    for (j = 0; j < 8; j++)
    {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}

void fill(int r, int c, int holeR, int holeC, int size)
{
  // int i, j;
  // int flag = 0;
  // if (size == 2)
  // {
  //   flag = (holeR - r) * 2 + (holeC - c) + 1;
  //   printf("flag2: %d holeR: %d holeC: %d r: %d c: %d\n", flag, holeR, holeC, r, c);
  //   for (i = r; i < size + r; i++)
  //   {
  //     for (j = c; j < size + c; j++)
  //     {
  //       if (i == holeR && j == holeC)
  //         continue;
  //       board[i][j] = flag;
  //     }
  //   }
  //   return;
  // }
  // flag = ((holeR < (r + (size / 2))) ? 0 : 2) + ((holeC < (c + (size / 2))) ? 0 : 1) + 1;

  // for (i = 0; i < 2; i++)
  // {
  //   for (j = 0; j < 2; j++)
  //   {
  //     int middleR = r + (size / 2);
  //     int middleC = c + (size / 2);
  //     printf("flag1: %d\n", flag);

  //     if (i * 2 + j + 1 == flag)
  //     {
  //       // printf("hi\n");
  //       fill(r + (i * (size / 2)), c + (j * (size / 2)), holeR, holeC, size / 2);
  //     }
  //     else
  //     {
  //       board[middleR - 1 + i][middleC - 1 + j] = flag;
  //       fill(r + (i * (size / 2)), c + (j * (size / 2)), middleR - 1 + i, middleC - 1 + j, size / 2);
  //     }
  //   }
  // }
  // }else {
  //   fill(r, c,holeR,holeC,size/2 );
  //   fill(r + size / 2, c, holeR, holeC, size / 2);
  //   fill(r + size / 2, c + size / 2, holeR, holeC, size / 2);
  //   fill(r, c + size / 2, holeR, holeC, size / 2);
  // }
}
void put(int r, int c) {
  if (board[r][c]!=0) {
    board[r + 1][c] = 1;
    board[r+1 ][c+1] = 1;
    board[r ][c+1] = 1;
  }else if (board[r+1][c]!=0) {
    board[r][c] = 2;
    board[r + 1][c + 1] = 2;
    board[r][c + 1] = 2;
  }else if (board[r][c+1]!=0) {
    board[r ][c] = 3;
    board[r + 1][c + 1] = 3;
    board[r+1][c] = 3;
  }else {
    board[r + 1][c] = 4;
    board[r][c] = 4;
    board[r][c + 1] = 4;
  }