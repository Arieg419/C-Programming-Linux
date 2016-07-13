#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int ret;

  printf("Calling execl...\n");
  ret = execl("/usr/bin/ls", "ls", "-l", NULL);

  printf("failed execl, %d\n", ret);
  return 0;
}
