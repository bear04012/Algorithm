#include <stdio.h>

#define N 20

void move(int, int,int);
int checkValid(int,int,int);

int ary[N][N];

int main(int argc, char **argv)
{ 
  int r,c;

  move(0,2,1);

  for (r=0; r<N; r++) {
    for (c=0; c<N; c++) {
      printf("%d ",ary[r][c]);
    }
    printf("\n");
  }



  return 0;
}

void move (int x, int y, int cnt) {

  if (!checkValid(x,y,cnt)) {
    return;
  }else {
    if (ary[x][y]>cnt || ary[x][y]==0) {
      ary[x][y] = cnt;
    }
  }

  move(x+2, y+1,cnt+1);
  move(x+2, y-1,cnt+1);

  move(x+1, y+2,cnt+1);
  move(x+1, y-2,cnt+1);

  move(x-2, y+1,cnt+1);
  move(x-2, y-1,cnt+1);

  move(x-1, y+2,cnt+1);
  move(x-1, y-2,cnt+1);
}

int checkValid(int x, int y,int cnt) {
  if (x<0 || y<0 || x>N-1 || y>N-1) {
    return 0;
  }else if (ary[x][y]<cnt && ary[x][y]!=0) {
    return 0;
  }
  return 1; 
}


