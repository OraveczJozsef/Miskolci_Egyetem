#include <stdio.h>

#include <pthread.h>
#include <windows.h>

void* wait_time();

int main() {
  int time = 8;
  pthread_t thread;

  printf("[Main] Start ... \n");
  printf("[Main] Wait %d sec ... \n", time);

  pthread_create(&thread, NULL, wait_time, NULL);

  Sleep(time * 1000);

  pthread_join(thread, NULL);
  printf("[Main] Ready ... \n");
}

void* wait_time() {
  int time = 4;
  pthread_t tid = pthread_self();

  printf("[%d] Wait ", tid);
  printf("%d sec ... \n", time);

  Sleep(time * 1000);

  printf("[%d] Ready ... \n", tid);
}