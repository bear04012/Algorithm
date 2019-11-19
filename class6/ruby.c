#include <stdio.h>

int ary[10000];
int bag = 14;
int jewerly[4][2] = {{2, 40}, {5, 110}, {10, 200}, {3, 50}};

int main(int argc, char **argv)
{
  int i,j;
  for (i = 0; i <= bag; i++) {
    for (j = 0; j < 4; j++) {
      if(i-jewerly[j][0] >= 0) {
        if (ary[i] < ary[i - jewerly[j][0]] + jewerly[j][1])
          ary[i] = ary[i - jewerly[j][0]] + jewerly[j][1];
      }
    }
    printf("%d \n",ary[i]);
  }
  return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>

int greedy(int, int*,int);


int ary[10000];
int bag = 14;
int jewerly[4][2] = {{2,40},{5,110},{10,200},{3,50}};


int getBiggest(int);
int isLow(int);
int main(int argc, char **argv)
{
  int cnt=0,i,value;
  while(cnt<=bag){
    value = 0;

    if (isLow(cnt)) {
      ary[cnt] = 0;
    } else {
      value = getBiggest(cnt);
      ary[cnt] = value;
    }


    // ary[cnt] = value;
    // ary[cnt] = ary[cnt]+ary[]
  }




  return 0;
}
int isLow(int cnt){
  int i;
  for (i = 0; i < 4; i++) {
    if (cnt>=jewerly[i][0]) {
      return 0;
    }
  }
  return 1;
}

int getBiggest(int cnt) {
  int i, value = 0, small = 0, temp = cnt;

  while (1) {
    cnt = temp;

    for (i = 0; i < 4; i++){
      if (cnt > jewerly[i][0]){
        value += jewerly[i][1];
        cnt -= jewerly[i][0];
      }
    }
  }
  
}

*/