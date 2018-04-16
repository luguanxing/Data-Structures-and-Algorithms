#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>

//信号量
sem_t binSem;

//消费者线程
void* customer(void* arg) {
	while(1) {
		sem_wait(&binSem);
		printf("---消费者线程使用了信号量\n");
	}
}

//生产者线程
void* producer(void* arg) {
	while(1) {
		sem_post(&binSem);
		printf("+++生产者线程生产了信号量\n");
		::Sleep(1000);
	}
}

int main()  {
	//初始化信号量
	sem_init(&binSem, 0, 0);
	//创建线程
	pthread_t t_producer;
	pthread_t t_customer;
	pthread_create(&t_producer, NULL, producer, NULL);
	pthread_create(&t_customer, NULL, customer, NULL);
	::Sleep(100000);
}

