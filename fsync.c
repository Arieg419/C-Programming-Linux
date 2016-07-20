#include <>
#include <>
#include <>
#include <>
#include <>
#include <>
#include <>

int main( int argc, char* argv[]) {

  char *str = "This is a string that goes to file";

  int fd;
  int ret;

  fd = creat("hello.txt", S_IWUSR | S_IRUSR);

  if (fd < -1) {
    perror("creat()");
    exit(1);
  }

  ret = write(fd, str, strlen(str));

  if (ret <= -1) {
    perror("write()");
    exit(1);
  }

  // sync to disk immediatley!
  fsync(fd);


  /*
    very long lines of code blah blah blah
  */

  close(fd);

  return 0;
}
