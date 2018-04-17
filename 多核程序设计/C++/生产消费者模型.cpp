#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>

//信号量
sem_t binSem;

//生产者线程
void* producer(void* arg) {
	while(1) {
		//输出成功后才生产(无代价)，避免生产马上被抢先于输出
		printf("+++生产者线程%d生产了信号量\n", arg);
		sem_post(&binSem);
		::Sleep(1000);
	}
}

//消费者线程
void* customer(void* arg) {
	while(1) {
		//消费后(有代价)成功后才输出，避免输出后要等不同步
		sem_wait(&binSem);
		printf("---消费者线程%d使用了信号量\n", arg);
		::Sleep(100);
	}
}

int main()  {
	//初始化信号量
	sem_init(&binSem, 0, 0);
	//创建线程
	pthread_t t_producers[3];
	pthread_t t_customers[5];
	for (int i = 0; i < 3; i++) {
		pthread_create(&t_producers[i], NULL, producer, (void*)i);
	}
	for (int i = 0; i < 5; i++) {
		pthread_create(&t_customers[i], NULL, customer, (void*)i);
	}
	for (int i = 0; i < 5; i++) {
		pthread_join(t_customers[i], NULL);
	}
}

