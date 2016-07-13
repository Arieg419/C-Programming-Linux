#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHSIZE 100

int main(int argc, char const *argv[]) {
  int shmid; // shared memory id
  key_t key;
  char *shm;
  char *s;

  key = 9876;

  // gets shm ptr with specific key created in client
  shmid = shmget(key, SHSIZE, 0666); // get shared mem id, permission is set to 0666

  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // grab ptr to shm
  shm = shmat(shmid, NULL, 0); // map shared memory.

  if (shm == (char*) -1) {
    perror("shmat");
    exit(1);
  }

  for (s = shm; *s != 0; s++) {
    printf("%c", *s);
  }

  printf("\n");

  *shm = '*';

  return 0;
}
