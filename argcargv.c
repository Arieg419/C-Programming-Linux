#include <stdio.h>

int main(int argc, char const *argv[]) {

  printf("argc == %d\n", argc);

  for (int i = 0;  i < argc;  i++) {
    printf("arg[%d] == %s\n", i, argv[i]);
  }

  return 0;
}

// Name of program is 0th arg
