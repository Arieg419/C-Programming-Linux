#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void* myfunc1 (void *myvar);
void* myfunc2 (void *myvar);

char buf[24];
sem_t mutex;

int main(int argc, char const *argv[]) {
  pthread_t thread1, thread2;
  char* msg1 = "First thread ";
  char* msg2 = "Second thread ";
  int ret1, ret2;

  sem_init(&mutex, 0, 1);  // sem_init is an unnamed semaphore, deprecated on OSX

  ret1 = pthread_create(&thread1, NULL, &myfunc1, (void*) msg1);
  ret2 = pthread_create(&thread2, NULL, &myfunc2, (void*) msg2);

  printf("Main function after pthread_create\n");

  pthread_join(thread1, NULL); // is the main thread being suspended twice here?
  pthread_join(thread2, NULL);

  sem_destroy(&mutex);  // sem_destroy is an unnamed semaphore, deprecated on OSX

  return 0;
}

void *myfunc1 (void* myvar) {
  char *msg;
  msg = (char*) myvar; // implicit casting from void* to char*
  printf("%s\n", msg);

  sem_wait(&mutex);
  sprintf(buf, "%s", "Hello there!");
  sem_post(&mutex);

  pthread_exit(0);
}

void *myfunc2 (void* myvar) {
  char *msg;
  msg = (char*) myvar; // implicit casting from void* to char*

  printf("%s\n", msg);

  sem_wait(&mutex);
  printf("%s\n", buf);
  sem_post(&mutex);

  pthread_exit(0);
}
