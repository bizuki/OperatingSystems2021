#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <pthread.h>


void print_thread_id(pthread_t *id) {
    printf("Hello from thread with id=%lu\n", *id);
}

/*
In this version we got results in random order:
    Created thread with id=139622331590208
    Hello from thread with id=139622331590208
    Created thread with id=139622323197504
    Hello from thread with id=139622323197504
    Created thread with id=139622314804800
    Created thread with id=139622306412096
    Hello from thread with id=139622306412096
    Created thread with id=139622298019392
    Hello from thread with id=139622298019392
    Hello from thread with id=139622314804800

Thats because thread is not gurantueed to be executed right after creation
int main() {
    int n = 5;
    pthread_t thread_ids[n];
    for (int i = 0; i < n; i++) {
        pthread_create(&thread_ids[i], NULL, print_thread_id, &thread_ids[i]);
        printf("Created thread with id=%lu\n", thread_ids[i]);
    }

    pthread_exit(0);
}

In second version we got strict execution because after creation of any thread we are waiting for it to finish, but unfortunatly we losing the 
benefits of threading, our program behaves like a single threaded one.
*/

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, print_thread_id, &thread_id);
        printf("Created thread with id=%lu\n", thread_id);
        pthread_join(thread_id, NULL);
    }

    pthread_exit(0);
}