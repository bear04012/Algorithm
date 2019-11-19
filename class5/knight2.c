#include <stdio.h>

struct queue {
  int x;
  int y;
  int num;
} Q[100];
int start, end;


struct queue pop() {
  return Q[start++];
}
void push(struct queue data) {
  Q[end].x = data.x;
  Q[end].y = data.y;
  Q[end++].num = data.num;
}

int board[10][10];
int checkValid(int,int,int);

struct queue findPawn();

int main() {
  struct queue min;

  struct queue knight;
  knight.x = 0;
  knight.y = 0;
  knight.num = 0;
  push(knight);
  min = findPawn();

  printf("x: %d y: %d min: %d \n",min.x,min.y,min.num);

  return 0;
}

struct queue findPawn() {
  int i,j, move[8][2] = {{1,2},{2,1},{-1,2},{2,-1},{-1,-2},{-2,1},{1,-2},{-2,-1}};

  while(1) {
    struct queue tmp = pop();
    if (tmp.x==9&&tmp.y==9) {
      return tmp;
    }
    struct queue tmp2;
    for (i=0; i<8; i++) {
      if (!checkValid(tmp.x+move[i][0],tmp.y+move[i][1],10)) {
        continue;
      }
      tmp2.x = tmp.x+move[i][0];
      tmp2.y = tmp.y+move[i][1];
      tmp2.num = tmp.num+1;
      board[tmp2.x][tmp2.y] =-1;
      
      push(tmp2);
    }

    // for (i=0; i<10; i++) {
    //   for (j=0; j<10;j++) {
    //     printf(" %d ",board[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("------------------------\n");
    // cnt++;
    

  }

  return Q[99];

}
int checkValid(int r, int c,int n) {
  if (r>=n||r<0||c>=n||c<0) {
    return 0;
  }else if (board[r][c]==-1){
    return 0;
  } else {
    return 1;
  }
}