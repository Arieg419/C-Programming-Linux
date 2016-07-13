#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* myfunc (void *myvar);

int main(int argc, char const *argv[]) {
  pthread_t thread1, thread2;
  char* msg1 = "First thread ";
  char* msg2 = "Second thread ";
  int ret1, ret2;

  ret1 = pthread_create(&thread1, NULL, &myfunc, (void*) msg1);
  ret2 = pthread_create(&thread2, NULL, &myfunc, (void*) msg2);

  printf("Main function after pthread_create\n");

  pthread_join(thread1, NULL); // is the main thread being suspended twice here?
  pthread_join(thread2, NULL);

  printf("First thread ret1 == %d\n", ret1);
  printf("Second thread ret2 == %d\n", ret2);


  return 0;
}

void *myfunc (void* myvar) {
  char *msg;
  msg = (char*) myvar; // implicit casting from void* to char*

  int i;
  for (i = 0; i < 10; i++) {
    printf("%s, %d\n", msg, i);
    sleep(1);
  }

  return NULL;
}

/*
So what this code does is :

It uses the pthread_create() function to create two threads
The starting function for both the threads is kept same.
Inside the function ‘doSomeThing()’, the thread uses pthread_self()
and pthread_equal() functions to identify whether the executing
thread is the first one or the second one as created.
Also, Inside the same function ‘doSomeThing()’ a for loop is run
so as to simulate some time consuming work.

As seen in the output, first thread is created and it starts processing,
then the second thread is created and then it starts processing.
Well one point to be noted here is that the order of execution
of threads is not always fixed. It depends on the OS scheduling algorithm.

pthread_join() explanation
The function above makes sure that its parent thread does not
terminate until it is done.

http://www.thegeekstuff.com/2012/04/terminate-c-thread/
*/
