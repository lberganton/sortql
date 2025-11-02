# SortQL

This project implements SortQL in C, a revolutionary sorting algorithm that uses SQL statements.

Why use such boring and complex algorithms like Quicksort, Mergesort, or Heapsort when SQL has `ORDER BY`?
Modern software doesn't need to worry about efficiency and memory usage. We have enough memory and fast CPUs.

The algorithm takes an array as input, creates a SQL table with an integer field, inserts all array elements
into the table, performs a select with an `ORDER BY` clause to get the values in ascending order, and then puts them back into the array.

## Build

### Dependencies

- gcc
- make
- sqlite3

### Building

```sh
make
```

This will generate `libsortql.so`, which can be linked during the compilation of your own programs.

## Usage

Include the `sortql.h` header in your project, link `libsortql.so` during compilation, and call the `sortql()` function when you needed.

Here is an example of a program that takes two integers and shows which one is the greatest:

```c
#include "sortql.h"
#include <stdio.h>

int main(void) {
  int inputs[2];

  printf("First number:\n");
  scanf("%d", &inputs[0]);

  printf("Second number:\n");
  scanf("%d", &inputs[1]);

  sortql(inputs, 2);

  printf("The greatest number is %d\n", inputs[1]);

  return 0;
}
```
