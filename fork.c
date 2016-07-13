#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  int childpid;
  int childCounter = 0;
  int fatherCounter = 0;

  printf("Before it forks\n");

  sleep(5); // Sleep for five seconds check out processes running :)

  childpid = fork();

  if (childpid == 0) {
    printf("This is child process\n");
    while (childCounter < 10) {
      printf("Child process: %d\n", childCounter);
      sleep(1); // sleep for one second
      childCounter++;
    }
  } else {
    printf("This is father process.\n Son pid is %d\n", childpid);
    while (fatherCounter < 20) {
      printf("Father process: %d\n", fatherCounter);
      sleep(1); // sleep for one second
      fatherCounter++;
    }
  }

  return 0;
}
