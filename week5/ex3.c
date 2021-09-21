#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int buffer_pos = 0;
const int buffer_size = 10;
int buffer[10];


void* producer(void* arg) {
    while (1) {
        while (buffer_size <= buffer_pos) { // buffer is full
            usleep(10);
        }

        if (buffer_size <= buffer_pos) {
            printf("Buffer is full but we are trying to append new data. Fail");
            return -1;
        }
        buffer[buffer_pos] = rand() % 10 + 1;
        buffer_pos++;
    }
}

void* consumer(void* arg) {

    time_t last_print_time = 0;

    while (1) {
        while (buffer_pos <= 0) { // buffer is empty
            usleep(10);
        }

        if (buffer_pos <= 0) {
            printf("Buffer is empty but we are trying to fetch data. Fail");
            return -1;
        }
        if (time(NULL) - last_print_time >= 60) {
            printf("number=%d\n", buffer[buffer_pos - 1]);
            last_print_time = time(NULL);
        }
        buffer_pos--;
        
    }
}

int main() {
    pthread_t consumer_thread, producer_thread;

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);

    pthread_exit(0);
}