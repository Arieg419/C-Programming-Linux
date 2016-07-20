#include <stdio.h>

typedef struct a {
  int apple;
  int orange;
  long banana;
} a;

int main(int argc, char const *argv[]) {
  struct {
    int a;
    float b;
    int c;
  } mystruct;

  a fruit;
  fruit.apple = 25;

  printf("fruit.apple is %d\n", fruit.apple);

  mystruct.a = 1;
  mystruct.b = 3.234;
  mystruct.c = 2;

  printf("a = %d, b = %f, c = %d\n", mystruct.a, mystruct.b, mystruct.c);

  return 0;
}
