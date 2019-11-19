#include <stdio.h>
#include <stdlib.h>
int atoi(const char *string);

char N[] = "27123";
int ary[10000];
int num[10];

int main(int argc, char **argv)
{
  int i,j;
  int val;


  for (i = 0; i < 5; i++) {
    char c = N[i];
    num[i] = atoi(&c);
    // printf("num: %d\n", num[i]);
    val = 0;

    if (i==0) {
      ary[i] = 1;
    } else if (i==1) {
      val += num[i] + (num[i - 1] * 10);
      if (val>34) {
        ary[i] = 1;
      }else {
        ary[i] = 2;
      }
    } else {
      val += num[i] + (num[i - 1] * 10);
      if (val > 34)
      {
        ary[i] = ary[i-1];
      }
      else
      {
        ary[i] = ary[i-1]+ary[i-2];
      }
    }
    printf("ary[%d]:%d\n",i, ary[i]);
  }

    

    // for (j = i; j >= 0; j--) {
    //   if (i==0) {
    //     ary[i] = 1;
    //   }else if (i==1) {
    //     val += num[i]+num[i];
    //   }
    //   else
    //   {
    //   }

  // cnt = atoi(N);
  // printf("num: %d\n", cnt);

  return 0;
}
