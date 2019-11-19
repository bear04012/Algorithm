#include <stdio.h>
void hanoi(int, int, int);

int main(int argc, char **argv)
{  

  hanoi(3,1,3);
  return 0;
}


void hanoi(int size, int s, int e) {

  if(size ==0)
    return;

  hanoi(size-1,s,6-s-e);
  printf("%d원판 %d->%d\n", size, s, e);
  hanoi(size-1,6-s-e,e);
}
