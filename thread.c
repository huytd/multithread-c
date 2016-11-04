#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include "max.h"

void *inc_x(void *x_void_ptr) {
  int *x_ptr = (int*)x_void_ptr;
  while (++(*x_ptr) < MAX_COUNT) ;
  printf("x increment finished\n");
  return NULL;
}

void *inc_y(void *y_void_ptr) {
  int *y_ptr = (int*)y_void_ptr;
  while (++(*y_ptr) < MAX_COUNT) ;
  printf("y increment finished\n");
  return NULL;
}

int main() {
  clock_t begin = clock();

  int x = 0, y = 0;

  printf("x: %d, y: %d\n", x, y);

  pthread_t inc_x_thread;
  if (pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
    fprintf(stderr, "Error creating thread\n");
    return 1;
  }

  pthread_t inc_y_thread;
  if (pthread_create(&inc_y_thread, NULL, inc_y, &y)) {
    fprintf(stderr, "Error creating thread\n");
    return 1;
  }

  if (pthread_join(inc_x_thread, NULL)) {
    fprintf(stderr, "Error joining thread\n");
    return 2;
  }

  if (pthread_join(inc_y_thread, NULL)) {
    fprintf(stderr, "Error joining thread\n");
    return 2;
  }

  printf("x: %d, y: %d\n", x, y);

  clock_t end = clock();
  double runtime = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Runtime: %lfms\n", runtime);
  return 0;
}
