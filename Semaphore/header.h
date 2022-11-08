#include <iostream>
#include <vector>
#include <semaphore>
#include <cstdlib>
#include <thread>
#include <mutex>

int buffer[10];
int in = -1;
int out = -1;

void* producer(void* arg);
void* consumer(void* arg);