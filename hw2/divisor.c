#include <stdio.h>

int ary[5000];

void printDivisor(int,int);
int tryDivide(int,int,int);
int findGCD(int,int);

int main(int argc, char **argv)
{
  int i,index;
  
//  printDivisor(24,30);
  printf("%d\n", findGCD(126,180));
  return 0;
}

int findGCD(int a, int b) {

  if(b == 0)
    return a;

  return findGCD(b ,a%b);

}


void printDivisor(int num1,int num2) {
  int bigDivisor=1;;
  int smallMultiple=1;;
  int n=2;

  while(n<num1) {
    if (tryDivide(num1,num2,n)) {
      bigDivisor*=n;
      smallMultiple*=n;
      num1/=n;
      num2/=n;
      n=2;
    }
    n++;
  }

  smallMultiple*=num1;
  smallMultiple*=num2;

  printf("biggest Divisor is %d, and smallest muliple is %d\n",bigDivisor,smallMultiple);
  


}

int tryDivide(int num1, int num2, int n) {
  if (num1%n==0 && num2%n==0) {
    return 1;
  }
  return 0;
}
