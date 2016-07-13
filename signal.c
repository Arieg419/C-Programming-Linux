#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define SIGTERM 15

void myhandle(int mysignal) {
  printf("My signal -%d- is better than yours\n", mysignal);
  int signal(SIGTERM, myhandle); // when you get SIGTERM, handle with myhandle
}

int main(int argc, char const *argv[]) {
  int i = 0;
  int signal(SIGTERM, myhandle); // when you get SIGTERM, handle with myhandle

  while(1) {
    printf("i = %d", i);
    i++;
    sleep(1);
  }

  return 0;
}
