#include <stdio.h>
#include <stdlib.h>
//int ary[5000][2];
int checkAry[5000];

struct road {
  int start;
  int end;
  int cost;
} ary[5000];

int example[5][5]={{0,5,10,8,7},{5,0,5,3,6},{10,5,0,1,3},{8,3,1,0,1},{7,6,3,1,0}};

void sort(int, struct road[]);
void merge(int, struct road[], struct road[]);

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
    for (j=i+1; j<N; j++) {
      ary[tmp].start = i;
      ary[tmp].end= j;
      // scanf("%d", &ary[i*N+j].cost);
      ary[tmp++].cost = example[i][j];

    }
  }


  sort(N*(N-1)/2,ary);
  printf("----------------------- \n");
  for (i=0; i<N*(N-1)/2; i++) {
    printf("%d  %d  %d \n",ary[i].start,ary[i].end,ary[i].cost);
  }

  min  = minimumCost(N);


  printf("the minimum cost: %d\n", min);

  return 0;
}

void merge(int size,struct road ary[],struct road ary2[]) {
  int i,test;
  int fInd = 0, rInd = 0, lInd = 0;
  struct road *finalary = (struct road*) malloc (sizeof(struct road)*size);

  while (1)
  {
    if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd].cost > ary2[rInd].cost))
    {
      finalary[fInd].start = ary2[rInd].start;
      finalary[fInd].end = ary2[rInd].end;
      finalary[fInd].cost = ary2[rInd].cost;
      
      rInd++;
    }
    else
    {
      finalary[fInd].start = ary[lInd].start;
      finalary[fInd].end = ary[lInd].end;
      finalary[fInd].cost = ary[lInd].cost;
      lInd++;
    }
    fInd++;
    if (fInd == size)
    {
      break;
    }
    }

  for (i = 0; i < size; i++){
    ary[i].start = finalary[i].start;
    ary[i].end = finalary[i].end;
    ary[i].cost = finalary[i].cost;
  }
}

void sort(int size,struct road ary[])
{
  if (size == 1)
    return;

  sort(size / 2, ary);
  sort((size + 1) / 2, ary + (size / 2));

  merge(size, ary, ary + (size / 2));
  
}

int minimumCost(int size) {
  int i,j, tmp;
  int counter=0,cost = 0;
  for(i=0; i<size*(size-1)/2; i++) {

    if (checkDone(size)) {
      break;
    }

    if (checkAry[ary[i].start] != checkAry[ary[i].end]) {

      tmp = checkAry[ary[i].end];
      for(j=0; j<size; j++) {
        if(checkAry[j] == tmp)
          checkAry[j] = checkAry[ary[i].start];
      }
      
      cost+=ary[i].cost;


        // if (checkAry[ary[i].start]<counter || checkAry[ary[i].end]<counter) {
        //   counter = checkAry[ary[i].start]>checkAry[ary[i].end]? checkAry[ary[i].end]:checkAry[ary[i].start];

        // } else {
          
        // }
        
        // checkAry[ary[i].start] = counter;
        // checkAry[ary[i].end] = counter;
        // cost+=ary[i].cost;
        // counter++;


    }
  }

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