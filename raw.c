#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "max.h"

int main() {
  clock_t begin = clock();

  int x = 0, y = 0;

  printf("x: %d, y: %d\n", x, y);

  while (++x < MAX_COUNT);
  printf("x increment finished\n");
  while (++y < MAX_COUNT);
  printf("y increment finished\n");

  printf("x: %d, y: %d\n", x, y);

  clock_t end = clock();
  double runtime = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Runtime: %lfms\n", runtime);
  return 0;
}
