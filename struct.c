#include <stdio.h>

int main(int argc, char const *argv[]) {
  struct {
    int a;
    float b;
    int c;
  } mystruct;

  mystruct.a = 1;
  mystruct.b = 3.234;
  mystruct.c = 2;

  printf("a = %d, b = %f, c = %d\n", mystruct.a, mystruct.b, mystruct.c);

  return 0;
}
