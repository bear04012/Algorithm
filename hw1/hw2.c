#include <stdio.h>
#include <stdlib.h>


double checkBiggestComb(int, double *);
double checkBiggestComb2(int, double *);

void createAry();

int main(int argc, char **argv)
{
  int i,N;
  double *arr;
  double num;

  printf("How many float numbers would you like to input? \n");
  scanf("%d", &N);

  arr = (double *)malloc(sizeof(double) * N);
  for (i = 0; i < N; i++){
    if (i==0)
      printf("%dst number: \n",(i+1));
    else if(i==1)
      printf("%dnd number: \n", i+1);
    else if (i==2)
      printf("%drd number: \n", i+1);
    else
      printf("%dth number: \n", i+1);
    scanf("%lf", &arr[i]);
  }

  num = checkBiggestComb2(N, arr);
  printf("The biggest combination is %.4f\n", num);

  // double num;
  // double ary[8] = {1.1, 0.7, 1.3, 0.9, 1.4, 0.8, 0.7, 1.4};

  // num = checkBiggestComb(8, ary);
  // printf("The biggest combination is %.4f\n", num);

  return 0;
}


double checkBiggestComb(int size, double* ary) {
  int i, j;
  double biggest = ary[0] * ary[1];
  double mult;

  for (i = 0; i < size; i++){
    mult = 1.;
    for (j = i; j < size; j++)
    {
      mult *= ary[j];
      if (biggest<mult) {
        biggest = mult;
        // printf("The biggest might be %f\n ", biggest);
      }
        
    }
  }
  return biggest;
}

double checkBiggestComb2(int size, double* ary) {
  int i, index;
  double biggest = ary[0];
  double smallest = 1;
  double multB =1.;
  double multS = 1.;

  for (i=0; i<size; i++) {
    multB*=ary[i];
    if (multB>biggest) {
      biggest = multB;
      index = i;
    }
  }

  for (i=0; i<=index; i++) {
    multS *= ary[i] ;
    if (multS<smallest) {
        smallest = multS;
    }
    
  }

  printf("%f %f %.4f \n", biggest,smallest, biggest/smallest);
  return biggest/smallest;

}