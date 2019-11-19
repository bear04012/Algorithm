
#include <stdio.h>
#define N 5

char board[5][7] = {"LLLLLLL", "LWWWWWL", "LWWWWWL", "LWWWWWL", "LLLLLLL"};
//char board[5][7] = {"WLLWWWL", "LLLWLLL", "LWLWLWW", "LWLWLLL", "WLLWLWW"};
int r = 5;
int c=7;
int checkBoard[100][100];

struct queue {
  int ways[N];
  int cost;
} Q[100];

int start, end;

struct queue pop() {
  return Q[start++];
}
void push(struct queue data) {
  int i;
  for (i=0; i<N; i++) {
    Q[end].ways[i] = data.ways[i];
  }
  Q[end++].cost = data.cost;
}

int findMax();
void draw2D();
void count(int,int);
void reset();
int findBiggest();
int checkValid(int, int);

int main() {
  int i,max;


  max =  findMax();
  printf("%d\n", max - 1);

  return 0;
}

int ifEndNode(int x, int y)
{
  return 1;
}



int findMax() {
  int i, j,biggest=0,tmp;

  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (board[i][j] == 'L' && ifEndNode(i, j)) {
        count(i, j);
        tmp = findBiggest();
        if (biggest < tmp)
        {
          biggest = tmp;
        }
        draw2D();
        reset();
      }
    }
  }
  return biggest;
}

void count(int row, int col) {
  int smallest;
  if (board[row][col]=='W' || !checkValid(row,col)||checkBoard[row][col]>0) {
    return;
  } else {
    smallest = 100;
    if (checkBoard[row + 1][col] < 1 && checkBoard[row - 1][col] < 1 && checkBoard[row][col + 1] < 1 && checkBoard[row][col - 1] < 1){
      smallest = 1;
    }
    if (checkBoard[row + 1][col] > 0 && checkBoard[row + 1][col] < smallest){
      smallest = checkBoard[row + 1][col] + 1;
    }
    if (checkBoard[row - 1][col] > 0 && checkBoard[row - 1][col] < smallest){
      smallest = checkBoard[row - 1][col] + 1;
    }
    if (checkBoard[row][col + 1] > 0 && checkBoard[row][col + 1] < smallest){
      smallest = checkBoard[row][col + 1] + 1;
    }
    if (checkBoard[row][col - 1] > 0 && checkBoard[row][col - 1] < smallest){
      smallest = checkBoard[row][col - 1] + 1;
    }
    checkBoard[row][col] = smallest;

    count(row + 1, col);
    count(row - 1, col);
    count(row, col+1);
    count(row, col-1);
  }
}

// void countBFS(int x, int y) {

//   queue.push(x, y,0);
//   while (!queueIsEmpty())
//   {
//     i,j,v = queue.pop();

//     if(check[i][j-1] > v+1)
//         queue.push(i, j - 1, v + 1);
//     if (check[i][j + 1] > v + 1)
//       queue.push(i, j + 1, v + 1);
//     if (check[i - 1][j] > v + 1)
//       queue.push(i - 1, j, v + 1);
//     if (check[i + 1][j] > v + 1)
//       queue.push(i + 1, j, v + 1);
//   }
// }

void reset() {
  int i, j;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      checkBoard[i][j] = 0;
    }
  }
}
int findBiggest() {
  int i, j, cnt = 0;
  for (i = 0; i < r; i++) {
    for (j = 0; j < c; j++) {
      if (cnt<checkBoard[i][j]) {
        cnt = checkBoard[i][j];
      }
    }
  }
  return cnt;
}
void draw2D()
{
  int i, j;

  printf("--------------------------\n");
  for (i = 0; i < r; i++)
  {

    for (j = 0; j < c; j++)
    {
      printf("%d ", checkBoard[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int checkValid(int row, int col) {

  if (row<0||row>=r||col<0||col>=c) {
    return 0;
  } else {
    return 1;
  }
}