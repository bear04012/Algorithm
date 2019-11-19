#include <stdio.h>

int ary[10000];
int N = 12;


int main(int argc, char **argv)
{
  int i;
  int cnt;
  for (i = 0; i <= N; i++)
  {
    cnt = 0;
    if (i==0) {
      ary[i] = 1;
    }else if(i==1) {
      ary[i] = 1;
    } else {

      ary[i] = ary[i - 1] + ary[i - 2] + ary[i - 2];
      // cnt += ary[i - 1];
      // cnt += ary[i - 2];
      // cnt += ary[i - 2];
      // ary[i] = cnt;
    }
    
  }

  for (i = 0; i <= N; i++) {
    printf("%d\n", ary[i]);
  }

  return 0;
}
