#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int fd;
  struct stat mystat;
  void *pmap;

  fd = open("test.txt", O_RDWR);

  if (fd == -1) {
    perror("open");
    exit(1);
  }

  if (fstat(fd, &mystat) < 0 ) {
    perror("fstat");
    close(fd);
    exit(1);
  }

  pmap = mmap(0, mystat.st_size, PROT_READ | PROT_WRITE,
    MAP_SHARED, fd, 0);

  if(pmap == MAP_FAILED) {
    perror("mmap");
    close(fd);
    exit(1);
  }

  strncpy(pmap, "That", 4);

  close(fd);

  return 0;

}

/*
With mmap we bring the file to the memory space of the process. Change
what is in the memory, which directly affects the contents of the file.
*/
