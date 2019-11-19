#include <stdio.h>

int board[10][9]={{0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,0},{0,0,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0},{0,1,0,1,1,1,1,1,0},{0,1,1,1,1,0,1,1,0},{0,0,0,1,1,1,1,0,0},{0,0,0,1,1,1,0,0,0},{0,0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
int r = 8;
int c = 7;
int startR=5;
int startC=3;

void bombJuglings(int,int);
void draw2D();

int main(int argc, char **argv)
{  
  int alive=0,i,j;
  int maxTime=board[1][1];

  
  bombJuglings(startR,startC);

  for (i=1; i<=r; i++) {
    for (j=1; j<=c; j++) {
      printf("%d  ",board[i][j]);
      if (board[i][j]>maxTime) {
        maxTime = board[i][j];
      }
      if (board[i][j]==1) {
        alive++;
      }
    }
    printf("\n");
  }
  printf("%d\n%d\n",maxTime,alive);

  

  
  return 0;
}


void bombJuglings(int r, int c){
  int area,i,j,smallest;

  if (board[r][c]!=1) {
    return;
  } else {
    smallest=100;
    if (board[r+1][c]<2 && board[r-1][c]<2 && board[r][c+1]<2 &&board[r][c-1]<2) {
      smallest = 3;
    }
    if (board[r+1][c]>=3 && board[r+1][c]<smallest) {
      smallest = board[r+1][c]+1;
    } 
    if (board[r-1][c]>=3 && board[r-1][c]<smallest) {
      smallest = board[r-1][c]+1;
    } 
    if (board[r][c+1]>=3 && board[r][c+1]<smallest) {
      smallest = board[r][c+1]+1;
    } 
    if (board[r][c-1]>=3 && board[r][c-1]<smallest) {
      smallest = board[r][c-1]+1;
    } 
    board[r][c] = smallest;


    draw2D();

    bombJuglings(r+1,c);
    bombJuglings(r-1,c);
    bombJuglings(r,c+1);
    bombJuglings(r,c-1);
  }
}

void draw2D() {
  int i,j;

  printf("--------------------------\n");
  for (i=1; i<=r; i++) {

    for (j=1; j<=c; j++) {
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
