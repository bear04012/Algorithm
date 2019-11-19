#include <stdio.h>
#include <stdlib.h>

int remain = 1;

struct number
{
  int list[100000];
  int size;
  int exp;
  /* data */
};


int calculate(int, int);
struct number calculate2(struct number, int);
struct number times_long(struct number, struct number);

int main(int argc, char **argv)
{
  int i, j;
  int c;

  // int N = 100000;
  // int a = 2;

  // c = calculate(a, N);

  // printf("num: %d\n",c);
  double ans = 1.;
  double val = 3.141592;

  //1
  struct number n;

  //3.14
  struct number n2;

  for (i = 0; i < 3; i++) {
    n = times_long(n, n2);
  }

  // for (i = 0; i < 3; i++)
  // {
  //   ans *= val;
  //   }
  // printf("ans: %.20lf\n", ans);

  return 0;
}

struct number calculate2(struct number n1, int N) {

  struct number result;
  if (N == 1)
  {
    return n1;
  }

  result = calculate2(n1, N / 2);

  return (N % 2 == 0 ? (times_long(result, result)) : times_long(times_long(result, result),n1));
}

struct number times_long(struct number n1, struct number n2) {

}

int calculate(int a, int N) {

  int result;
  if (N == 0)
    return 1;
  if (N == 1)
  {
    return a;
  }

  result = calculate(a, N / 2);

  return (result * result * (N % 2 == 0 ? 1 : a))%10000;

}