#include <stdio.h>
// #include <ctype.h>

int isprime(int);
long getPow(int, int);
int checkMersenne(int);

int main()
{
  int i,test;
  long mersenne;
  int count = 0;

  // example for getPow
  // int a = 2;
  // int b = 4;
  // int c = getPow(a, b);
  // printf("answer is = %d\n", c);

  //example for isPrime
  // for (i = 0; i < 10; i++) {
  //   if (isprime(i))
  //   {
  //     printf("the number %d is prime \n", i);
  //   }
  //   else
  //   {
  //     printf("the number %d is not a prime \n", i);
  //   }
  // }

  //example for checkMersenne
  test = 1;
  while (count <= 6){
    mersenne = getPow(2, test);
    mersenne--;
    if (isprime(mersenne)){
      printf("%d is a mersenne number\n", mersenne);
      count++;
    }
    test++;
  }

  return 0;
}

int isprime(int n) {
  int i;
  int remainder;

  if (n <= 1){

    return 0;
  } 
  else if (n==2){
    return 1;
  } else {
    for (i=2; i <= n / 2; i++) {
      
      remainder = n % i;
      if (remainder == 0)
      {

        return 0;
      }
    }
  }
  return 1;
}

long getPow(int n, int m) {
  int i;
  int ans = 1;

  for (i = 0; i < m; i++) {
    ans *= n;
  }

  return ans;
}