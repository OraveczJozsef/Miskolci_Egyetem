#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <windows.h>

#include <unistd.h>

#include <pthread.h>

const int N_THREADS = 20;

void *wait_random_time(void* _);
int random_integer(int minimum, int maximum);

int main() {
  pthread_t threads[N_THREADS];
  int i;

  srand(time(NULL));

  printf("[Main] Start ...\n");
  for (i = 0; i < N_THREADS; i++) {
    pthread_create(&threads[i], NULL, wait_random_time, NULL);
  }

  printf("[Main] Join ...\n");
  for (i = 0; i < N_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  printf("[Main] Ready ...");
  return 0;
}

void *wait_random_time(void* _) {
  pthread_t tid;
  int wait_time;

  tid = pthread_self();
  wait_time = 8;//random_integer(1, 10);

  printf("[%d] Wait %d sec ...\n", tid, wait_time);
  printf("%d\n", wait_time);
  Sleep(wait_time * 1000);
  printf("[%d] Ready!\n", tid);
}

int random_integer(int minimum, int maximum) {
    return (rand() % (maximum-minimum+1)) + 1;
}