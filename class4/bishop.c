#include <stdio.h>


void settle(int,int );
void attack(int,int,int);
void attack_undo(int,int,int);
int checkValid(int,int,int);


// int board[5][5]={{1,1, 0, 1, 1},{0 ,1, 0, 0, 0},{1, 0, 1, 0, 1},{1, 0, 0, 0, 0},{1, 0, 1, 1, 1}};
int board[4][4] = {{0,1,1,1},{1,1,1,0},{1,0,1,1},{1,1,0,1}};
int count2d[5][5]={0,};
int max =0;

int main(int argc, char **argv)
{ 
  int N,r,c,num;
  N=4;

  // printf("Notation: \n");
  // scanf("%d", &N);

  settle(4,0);

  // for (r=0; r<N; r++) {
  //   for (c=0; c<N; c++) {
  //     printf("%d ",count2d[r][c]);
  //   }
  //   printf("\n");
  // }

  printf("max: %d\n",max);



  return 0;
}

void settle(int n,int cnt) {
  int r,c;



  for(r=0; r<n; r++) {
    for (c=0; c<n; c++) {
      if(board[r][c]==1 && count2d[r][c] == 0) {

        board[r][c]=3;
        attack(r,c,n);
        settle(n,cnt+1);
        attack_undo(r,c,n);
        board[r][c]=2;
        settle(n,cnt);
      }

      if(r==n-1 && c==n-1) {
        if(cnt>max) 
          max = cnt;
        return;
      }
        
        
    }
  }
}

void attack(int r,int c,int n) {
  int i=1;
  while (i<n) {

    if (checkValid(r+i,c+i,n)) {
      count2d[r+i][c+i]++;
    }
    if (checkValid(r+i,c-i,n)) {
      count2d[r+i][c-i]++;
    }
    if (checkValid(r-i,c+i,n)) {
      count2d[r-i][c+i]++;
    }
    if (checkValid(r-i,c-i,n)) {
      count2d[r-i][c-i]++;
    }
    i++;
  }
}

void attack_undo(int r,int c,int n) {
  int i=1;
  while (i<n) {

    if (checkValid(r+i,c+i,n)) {
      count2d[r+i][c+i]--;
    }
    if (checkValid(r+i,c-i,n)) {
      count2d[r+i][c-i]--;
    }
    if (checkValid(r-i,c+i,n)) {
      count2d[r-i][c+i]--;
    }
    if (checkValid(r-i,c-i,n)) {
      count2d[r-i][c-i]--;
    }
    i++;
  }
}


int checkValid(int r, int c,int n) {
  if (r>=n||r<0||c>=n||c<0) {
    return 0;
  }else {
    return 1;
  }
}