#include <stdio.h>
#include <pthread.h>

#define NUM_OF_LOOPS = 2000000
long long sum = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* counting_thread(void *arg) {
  int offset = *(int*) arg; // casting + ptr deref
  for (size_t i = 0; i < count; i++) {
    /* Start Crtitical Section */
    pthread_mutex_lock(&mutex);

    sum += offset;

    /* End Crtitical Section */
    pthread_mutex_unlock(&mutex);
  }

  pthread_exit(NULL);
}


int main(int argc, char const *argv[]) {

  /* Spawn threads*/
  pthread_t id1;
  int offset = 1;
  pthread_create(&id1, NULL, counting_thread, &offset1);

  pthread_t id2;
  // offset = -1; this causes race condition! tampering with same var
  int offset2 = -1;
  pthread_create(&id2, NULL, counting_thread, &offset2);

  /* Join threads */
  pthread_join(id1, NULL);
  pthread_join(id2, NULL);

  printf("Sum is %lld\n", sum);
  return 0;
}
