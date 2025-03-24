#include <stdio.h>
#include <pthread.h>

char shbff[100]
int mutex = 1;

void* producer() {
    printf("Enter a message to consumer: ");
    wait(mutex);
    gets(shbff);
    signal(mutex);
}

void* consumer() {
    printf("Message received from producer: ");
    wait(mutex);
    printf("%s\n", shbff);
    signal(mutex);
}

int main() {
    pthread_t prod_th, cons_th;
    pthread_create(prod_th, NULL, producer, NULL);
    pthread_create(cons_th, NULL, consumer, NULL);
    pthread_join(prod_th, NULL);
    pthread_join(cons_th, NULL);
    return 0;
}