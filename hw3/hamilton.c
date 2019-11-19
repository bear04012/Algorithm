#include <stdio.h>
#include <stdlib.h>
//int ary[5000][2];
int checkAry[5000];

struct road {
  int start;
  int end;
  int cost;
} ary[5000];

int example[5][5]={{0,14,4,10,20},{14,0,7,8,7},{4,5,0,7,16},{11,7,9,0,2},{18,7,17,4,0}};

int checkDone(int);

int minimumCost(int);

int main(int argc, char **argv)
{
  int i,j, N,min, tmp=0;
  
  for (i=0; i<5000; i++) {
    checkAry[i] = i;
  }

  // printf("Num of islands: \n");
  // scanf("%d", &N);
  N=5;

  for (i = 0; i < N; i++) {
    for (j=0; j<N; j++) {
      ary[i*N+j].start = i;
      ary[i*N+j].end= j;
      // scanf("%d", &ary[i*N+j].cost);
      ary[i*N+j].cost = example[i][j];

    }
  }


  printf("----------------------- \n");
  for (i=0; i<N*N; i++) {
    printf("%d  %d  %d \n",ary[i].start,ary[i].end,ary[i].cost);
  }

  min  = minimumCost(N);


  printf("the minimum cost: %d\n", min);

  return 0;
}

int minimumCost(int size) {
  int i,j, tmp;
  int counter=0,cost = 0;


  return cost;
}



int checkDone(int islands) {
  int i;
  int temp = checkAry[0];
  for (i=1; i<islands; i++) {
    if(temp!=checkAry[i]){
      return 0;
    }
    temp = checkAry[i];
  }
  return 1;
}