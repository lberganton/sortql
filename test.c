#include "sortql.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_LENGTH 10

static void fill_array(int *array, int length) {
  int i;
  srand(time(NULL));
  for (i = 0; i < length; i++) {
    array[i] = rand() % length + 1;
  }
}

static void print_array(int *array, int length) {
  int i;

  printf("[");

  for (i = 0; i < length; i++) {
    if (i > 0) {
      printf(", ");
    }
    printf("%d", array[i]);
  }

  printf("]\n");
}

int main(void) {
  int array[ARRAY_LENGTH];

  fill_array(array, ARRAY_LENGTH);

  print_array(array, ARRAY_LENGTH);

  sortql(array, ARRAY_LENGTH);

  print_array(array, ARRAY_LENGTH);

  return 0;
}
