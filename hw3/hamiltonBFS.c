#include <stdio.h>
#define N 5

struct queue {
  int ways[N];
  int start;
  int cost;
} Q[100];

int start, end;

int example[5][5]={{0,14,4,10,20},{14,0,7,8,7},{4,5,0,7,16},{11,7,9,0,2},{18,7,17,4,0}};


struct queue pop() {
  return Q[start++];
}
void push(struct queue data) {
  int i;
  for (i=0; i<N; i++) {
    Q[end].ways[i] = data.ways[i];
  }
  Q[end].start = data.start;
  Q[end++].cost = data.cost;
}

int findMin();

int checkConnected();

int main() {
  int i;
  int min;
  struct queue route;
  route.ways[0] = 1;
  route.ways[1] = 0;
  route.ways[2] = 0;
  route.ways[3] = 0;
  route.ways[4] = 0;
  route.start = 0;
  route.cost = 0;
  push(route);

  min = findMin();
  printf("min: %d\n", min);

  // printf("x: %d y: %d min: %d \n",min.x,min.y,min.num);

  return 0;
}

int findMin() {
  //tempStart = to reset the rollBack
  //endStart = to keep where it ends
  int i, small = 10000000, cnt = 0,tempStart;

  while (cnt<N*N-1)
  {
    struct queue tmp = pop();

    printf("%d %d %d %d %d\n", tmp.ways[0], tmp.ways[1], tmp.ways[2], tmp.ways[3], tmp.ways[4]);

    if (checkConnected(tmp)) {
      tmp.cost += example[tmp.start][0];
      printf("cost: %d\n", tmp.cost);
      if (small>tmp.cost) {
        small = tmp.cost;
      }
      printf("small: %d\n", small);
      cnt++;
    }
    
    for(i=0; i<N; i++) {
      if(tmp.ways[i] == 0) {
        tempStart = tmp.start;
        tmp.ways[i] = 1;
        tmp.cost += example[tmp.start][i];
        tmp.start = i;

        push(tmp);

        //RollBack
        tmp.ways[i] = 0;
        tmp.cost -= example[tempStart][i];
        tmp.start = tempStart;
      }
    }
  }
  return small;
}
int checkConnected(struct queue data) {

  int i;
  for (i = 0; i < N; i++) {
    if (data.ways[i]==0) {
      return 0;
    }
  }
  return 1;
}