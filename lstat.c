#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat buf;

  stat("file.txt", &buf);

  printf("st_mode = %o\n", buf.st_mode);

  return 0;
}
