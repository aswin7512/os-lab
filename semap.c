#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

char shbff[100];
sem_t empty, full;

void* producer() {
	while (1) {
		sem_wait(&empty);
		printf("Enter a message to consumer: ");
		fgets(shbff, sizeof(shbff), stdin);
		sem_post(&full);
	}
}

void* consumer() {
	while (1) {
		sem_wait(&full);
		printf("Message received from producer: ");	
		printf("%s\n", shbff);
		sem_post(&empty);
	}
}

int main() {
	sem_init(&empty, 0, 1);
	sem_init(&full, 0, 0);
    	pthread_t prod_th, cons_th;
    	pthread_create(&prod_th, NULL, producer, NULL);
    	pthread_create(&cons_th, NULL, consumer, NULL);
    	pthread_join(prod_th, NULL);
    	pthread_join(cons_th, NULL);
    	return 0;
}



/*

Enter a message to consumer: Abcd
Message received from producer: Abcd

Enter a message to consumer: Efgh
Message received from producer: Efgh

Enter a message to consumer: Ijkl
Message received from producer: Ijkl

Enter a message to consumer: ^C

*/