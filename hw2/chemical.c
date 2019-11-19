#include <stdio.h>
#include <stdlib.h>


int minimumFridge(int);

struct chemical{
  int hot;
  int cold;
}ary[5000];

int compare(const struct chemical *l, const struct chemical *r) {

  return (*l).cold- (*r).cold;
}

int main(int argc, char **argv)
{
  int i,j, N,min;
  

  printf("Num of chemicals: \n");
  scanf("%d", &N);


  for (i = 0; i < N; i++) {
    for (j=0; j<2; j++) {
      if(j==0) {
        printf("%d.cold: \n",i);
        scanf("%d", &ary[i].cold);
      }else {
        printf("%d.hot: \n",i);
        scanf("%d", &ary[i].hot);
      }
    }
  }

  

  qsort(ary, N, sizeof(struct chemical), compare);
  for (i=0; i<N; i++) {
    printf("%d %d \n",ary[i].hot,ary[i].cold);
  }

  min  = minimumFridge(N);

  printf("the minimum num of firdge it needs: %d\n", min);

  return 0;
}

int minimumFridge(int size) {
  int i;
  int fridge = 1;
  int tempHot = ary[0].hot;

  for (i=1; i<size; i++) {
    if (ary[i].cold<tempHot && ary[i].hot>tempHot) {
      tempHot = ary[i].hot;
    } else {
      fridge++;
      tempHot = ary[i].hot;
    }
  }

  return fridge;

}