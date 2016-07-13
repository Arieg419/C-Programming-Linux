#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>


#define SHSIZE 100

int main(int argc, char const *argv[]) {
  int shmid; // shared memory id
  key_t key;
  char *shm;
  char *s;

  key = 9876;

  // this creates shared memory
  shmid = shmget(key, SHSIZE, IPC_CREAT | 0666); // get shared mem id, permission is set to 0666

  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // gets the created shm pointer
  shm = shmat(shmid, NULL, 0); // map shared memory.

  if (shm == (char*) -1) {
    perror("shmat");
    exit(1);
  }

  memcpy(shm, "Hello World", 11);

  s = shm;
  s += 11;
  *s = 0;

  while (*shm != '*') {
    sleep(1);
  }

  return 0;
}

// IMPORTANT - ipcs for viewing shared memory blocks
// ipcrm -M 9876 to remove shared memory blocks
