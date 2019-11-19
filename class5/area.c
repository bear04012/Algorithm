#include <stdio.h>
#include <stdlib.h>
// #include <ctype.h>

void merge(int, int*, int*); 
void sort(int, int*);
void rectangle(int,int,int,int);
void hitSpace(int, int,int,int);
void countAreas(int, int,int,int);

int areas[100];
int rec;
int board[101][101];
int rectangles[10][4];

// int board2[5][7]={{0,0,0,0,1,1,0},{0,1,0,0,1,1,0},{1,1,1,1,0,0,0},{1,1,1,1,0,0,0},{0,1,0,0,0,0,0}};


int main()
{
  int r,c,num,i,j,cnt;

  r = 5;
  c = 7;
  num = 3;

  for (i=0; i<num; i++) {
    printf("x1: \n");
    scanf("%d", &rectangles[i][0]);

    printf("y1: \n");
    scanf("%d", &rectangles[i][1]);

    printf("x2: \n");
    scanf("%d", &rectangles[i][2]);

    printf("y2: \n");
    scanf("%d", &rectangles[i][3]);

    rectangle(rectangles[i][0],rectangles[i][1],rectangles[i][2],rectangles[i][3]);
  }


  for (i=0; i<r; i++) {
    for (j=0; j<c; j++) {
      printf("%d",board[i][j]);
    }
    printf("\n");
  }

  hitSpace(0,0,r,c);


  sort(rec,areas);
  for (i=0; i<rec; i++) {
    printf("%d.rec: %d\n",i+1,areas[i]);
  }

  
  return 0;
}

void rectangle(int x1, int y1, int x2, int y2) {
  int r, c,i,j;
  for (r = y1; r<y2; r++) {
    for (c = x1; c<x2; c++) {
      board[r][c] = 1;
    }
  }
}

void hitSpace(int x, int y,int r, int c) {
  int area,i,j;

  if (x>=r || y>=c) {
    return;
  } else if (board[x][y]==1||board[x][y] == 2) {
    hitSpace(x+1,y,r,c);
    hitSpace(x,y+1,r,c);
  }else {
    countAreas(x,y,r,c);
    printf("----------------------------\n");
    for (i = 0; i<r; i++) {
      for (j = 0; j<c; j++) {
        printf("%d",board[i][j]);
      }
      printf("\n");
    }
    rec++;
    hitSpace(x,y,r,c);
  }
  
}

void countAreas(int x, int y,int r, int c) {

  

  // if (x>=r || y>=c) {
  //   return;
  // } else if (board2[x][y]==1||board2[x][y] == 2) {
  //   return ;
  // } else {
  //   board2[x][y] = 2;
  //   areas[rec] +=1;
  //   countAreas(x+1,y,r,c);
  //   countAreas(x,y+1,r,c);
  // }

  
  
  if (x>=r || y>=c||x<0||y<0) {
    return;
  }  else if (board[x][y]==1||board[x][y] == 2) {
    return ;
  } else if (board[x+1][y]==0||board[x-1][y]==0||board[x][y+1]==0||board[x][y-1]==0) {
    board[x][y] = 2;
    areas[rec] +=1;
    board[x+1][y]==0?countAreas(x+1,y,r,c):3;
    board[x-1][y]==0?countAreas(x-1,y,r,c):3;
    board[x][y+1]==0?countAreas(x,y+1,r,c):3;
    board[x][y-1]==0?countAreas(x,y-1,r,c):3;

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

