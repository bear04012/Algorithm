#include <stdio.h>
#include <stdlib.h>

void merge(int size, int *ary, int *ary2 ) {
  int i,test;
  int fInd = 0, rInd = 0, lInd = 0;
  int *finalary = (int*) malloc (sizeof(int)*size);

  while (1)
  {
    if ((size / 2 == lInd) || (((size + 1) / 2 != rInd) && ary[lInd] > ary2[rInd]))
    {
      finalary[fInd] = ary2[rInd];
      
      rInd++;
    }
    else
    {
      finalary[fInd] = ary[lInd];
      lInd++;
    }
    fInd++;
    if (fInd == size)
    {
      break;
    }
    }

  for (i = 0; i < size; i++){
    ary[i] = finalary[i];
  }
}

void sort(int size, int *ary)
{
  if (size == 1)
    return;

  sort(size / 2, ary);
  sort((size + 1) / 2, ary + (size / 2));

  merge(size, ary, ary + (size / 2));
  
}

int main(int argc, char *argv[argc])
{
  int ary[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int i;


  sort(10, ary);

  for (i = 0; i < 10;i++)
    printf("%d ", ary[i]);

  return 0;
}