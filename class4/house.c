#include <stdio.h>
#include <stdlib.h>
#define N 7


void merge(int, int*, int*); 
void sort(int, int*);
void hitHouse(int,int);
void countAreas(int, int);

int board[7][7] = {{0,1,1,0,1,0,0},{0,1,1,0,1,0,1},{1,1,1,0,1,0,1},{0,0,0,0,1,1,1},{0,1,0,0,0,0,0},{0,1,1,1,1,1,0},{0,1,1,1,0,0,0}};
int rec;
int areas[100];

int main(int argc, char **argv)
{ 
  int i;
  hitHouse(0,0);

  sort(rec,areas);
  printf("%d\n",rec);

  for (i=0; i<rec; i++) {
    printf("%d\n",areas[i]);
  }

  return 0;
}

void hitHouse(int r,int c) {
  int area,i,j,ii,jj;


/*
  if (r>=N || c>=N) {
    return;
  } else if (board[r][c]==0||board[r][c] == 2) {
    hitHouse(r+1,c);
    hitHouse(r,c+1);
  }else {
    countAreas(r,c);
    printf("----------------------------\n");
    for (i = 0; i<N; i++) {
      for (j = 0; j<N; j++) {
        printf("%d",board[i][j]);
      }
      printf("\n");
    }
    rec++;
    hitHouse(r,c);
  }
  */

 for (i=0; i<N; i++) {
   for (j=0; j<N; j++) {
     if(board[i][j] == 1) {
       countAreas(i,j);
       printf("----------------------------\n");
       for (ii = 0; ii<N; ii++) {
         for (jj = 0; jj<N; jj++) {
           printf("%d",board[ii][jj]);
        }
        printf("\n");
      }
      rec++;
     }
   }
 }
  
}

void countAreas(int x, int y) {

  if (x>=N || y>=N||x<0||y<0) {
    return;
  }  else if (board[x][y]==0||board[x][y] == 2) {
    return ;
  } else if (board[x+1][y]==1||board[x-1][y]==1||board[x][y+1]==1||board[x][y-1]==1) {
    board[x][y] = 2;
    areas[rec] +=1;
    board[x+1][y]==1?countAreas(x+1,y):3;
    board[x-1][y]==1?countAreas(x-1,y):3;
    board[x][y+1]==1?countAreas(x,y+1):3;
    board[x][y-1]==1?countAreas(x,y-1):3;

  }else {
    board[x][y] = 2;
    areas[rec] +=1;

  }

}
void merge(int size, int *ary, int *ary2 ) {
  int i,test;
  int fInd = 0, rInd = 0, lInd = 0;
  int *finalary = (int*) malloc (sizeof(int)*size);

  while (1)
  {
    if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd] > ary2[rInd]))
    {
      finalary[fInd] = ary2[rInd];
      
      rInd++;
    }
    else
    {
      finalary[fInd] = ary[lInd];
      lInd++;
    }
    fInd++;
    if (fInd == size)
    {
      break;
    }
    }

  for (i = 0; i < size; i++){
    ary[i] = finalary[i];
  }
}

void sort(int size, int *ary)
{
  if (size == 1)
    return;

  sort(size / 2, ary);
  sort((size + 1) / 2, ary + (size / 2));

  merge(size, ary, ary + (size / 2));
  
}

