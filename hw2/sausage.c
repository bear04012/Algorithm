#include <stdio.h>
#include <stdlib.h>
//int ary[5000][2];
int checkAry[5000];

struct sausage {
  int l;
  int w;
} ary[5000];

void sort(int, struct sausage[]);
void merge(int, struct sausage[], struct sausage[]);



int minimumTime(int);

int main(int argc, char **argv)
{
  int i,j, N,min;
  

  printf("Num of sausages: \n");
  scanf("%d", &N);


  for (i = 0; i < N; i++) {
    for (j=0; j<2; j++) {
      if(j==0) {
        printf("%d.sl: \n",i);
        scanf("%d", &ary[i].l);
      }else {
        printf("%d.sw: \n",i);
        scanf("%d", &ary[i].w);
      }
    }
  }

  sort(N,ary);

  for (i=0; i<N; i++) {
    printf("%d %d \n",ary[i].l,ary[i].w);
  }

  min  = minimumTime(N);


  printf("the minimum time it takes: %d\n", min);

  return 0;
}

void merge(int size,struct sausage ary[],struct sausage ary2[]) {
  int i,test;
  int fInd = 0, rInd = 0, lInd = 0;
  struct sausage *finalary = (struct sausage*) malloc (sizeof(struct sausage)*size);

  while (1)
  {
    if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd].l > ary2[rInd].l))
    {
      finalary[fInd].w = ary2[rInd].w;
      finalary[fInd].l = ary2[rInd].l;
      
      rInd++;
    }
    else
    {
      finalary[fInd].w = ary[lInd].w;
      finalary[fInd].l = ary[lInd].l;
      lInd++;
    }
    fInd++;
    if (fInd == size)
    {
      break;
    }
    }

  for (i = 0; i < size; i++){
    ary[i].l = finalary[i].l;
    ary[i].w = finalary[i].w;
  }
}

void sort(int size,struct sausage ary[])
{
  if (size == 1)
    return;

  sort(size / 2, ary);
  sort((size + 1) / 2, ary + (size / 2));

  merge(size, ary, ary + (size / 2));
  
}

int minimumTime(int size) {
  int min = 0;
  int i;
  int cnt = 0;
  int tempSW;
  while (cnt < size) {
    min++;
    for (i=0; i<size; i++) {
      if (!checkAry[i]) {
        tempSW = ary[i].w;
        checkAry[i] = 1;
        cnt++;
        break;
      }
    }
    for (i=0; i<size; i++) {
      if (tempSW<ary[i].w && !checkAry[i]) {
        cnt++;
        checkAry[i] = 1;
        tempSW = ary[i].w;
      }
    }
    
  }

  return min;

}