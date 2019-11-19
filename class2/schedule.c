#include <stdio.h>
#include <stdlib.h>

int schedule();
void sort(int, int[][2]);
void merge(int, int[][2], int[][2]);

int ary[100000][2];
int N;


int main(int argc, char **argv)
{
  int i,j,maximum;
  double num;





  
  printf("Num of meeting: \n");
  scanf("%d", &N);



  for (i = 0; i < N; i++) {
    for(j=0;j<2;j++) {
      if (j==0) {
        printf("%d. start", i + 1);
        scanf("%d", &ary[i][j]);
      } else {
        printf("%d. end", i + 1);
        scanf("%d", &ary[i][j]);
      }
    }
  }

  


  maximum = schedule();

  printf("maximum: %d\n", maximum);



  return 0;
}

void merge(int size, int ary[][2], int ary2[][2] ) {
  int i,test;
  int fInd = 0;
  int rInd = 0;
  int lInd = 0;
  int finalary[1000][2];

  while (1)
  {
    if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd][1] > ary2[rInd][1]))
    {
      finalary[fInd][0] = ary2[rInd][0];
      finalary[fInd][1] = ary2[rInd][1];
      
      rInd++;
    }
    else
    {
      finalary[fInd][0] = ary[lInd][0];
      finalary[fInd][1] = ary[lInd][1];
      lInd++;
    }
    fInd++;
    if (fInd == size)
    {
      break;
    }
    }

  for (i = 0; i < size; i++){
    ary[i][0] = finalary[i][0];
    ary[i][1] = finalary[i][1];
  }
}

void sort(int size, int ary[][2])
{
  if (size == 1)
    return;

  sort(size / 2, ary);
  sort((size + 1) / 2, ary + (size / 2));

  merge(size, ary, ary + (size / 2));
  
}

int schedule()
{ 
  int i;
  int startTime = ary[0][1];
  
  int cnt = 1;

  for (i=0; i<N; i++) {
    if (startTime<=ary[i][0]) {
      startTime = ary[i][1];
      cnt++;
    }
  }

  return cnt;

}
