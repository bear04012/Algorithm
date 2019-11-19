#include <stdio.h>

// int ary[5000];

int convertToN(int,int,int);
int getPow(int, int);
int checkPalindrome(int);
void printPalindrome(int);

int main(int argc, char **argv)
{
  int N,num;

  printf("Notation: \n");
  scanf("%d", &N);


  printPalindrome(N);



  // index = convertToBinary(58,0);

  // for (i = index; i>=0; i--) {
  //   printf("%d",ary[i]);
  // }

  return 0;
}

// int convertToBinary(int num,int index) {
//   if (num<2) {
//     // printf("1");
//     ary[index] = 1;
//     printf("index: %d\n",index);
//     return index;
//   } else {
//     // printf("%d",num%2);
//     ary[index] = num%2;
//     return convertToBinary(num/2,index+1);
//   }
// }

void printPalindrome(int n) {
  int i;
  int num;
  while (i<=300) {
    num = convertToN(i*i,n,0);
    if (checkPalindrome(num)) {
      printf("%d  %d\n",i,num);
    }
    
    i++;
  }
}

int checkPalindrome(int num) {
  int digits=0,temp=num,i = 0;
  int ary[1000];

  while (temp>0) {
    ary[digits] = temp%10;
    temp/=10;
    digits++;
  }

  for (i=0; i<digits/2; i++) {
    if (ary[i]!=ary[digits-i-1]) {
      return 0;
    }
  }

  return 1;


}

int convertToN(int num,int n,int digit) {
  if (num<n) {
    // printf("%d", num);
    return(num*getPow(10,digit));
  } else {

    return((num%n*getPow(10,digit))+convertToN(num/n,n,digit+1));
    // convertToN(num/n,n);
    // printf("%d",num%n);
  }
}


int getPow(int n, int m) {
  int i;
  int ans = 1;

  for (i = 0; i < m; i++) {
    ans *= n;
  }

  return ans;
}