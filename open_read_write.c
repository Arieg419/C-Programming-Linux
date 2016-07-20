#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>



int main(int argc, char* argv[]) {

  int fd;
  char buf[14];

  // WRITE ONLY PURPOSE

  fd = open("file.txt", O_CREAT | O_WRONLY, 0600);

  if (fd == -1) {
    printf("Failed to create and open the file\n");
    exit(1);
  }

  write(fd, "Hello World!\n", 13);

  // READ ONLY PURPOSE

  fd = open("file.txt", O_RDONLY);

  if (fd == -1) {
    printf("Failed to create and open the file\n");
    exit(1);
  }

  read(fd, buf, 13);

  buf[13] = '\0';

  close(fd);

  printf("This is the buffer %s\n", buf);

  return 0;
}
