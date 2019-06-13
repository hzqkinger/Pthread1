#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread1(void *_val)
{
	printf("thread1 returning...\n");
	return (void*)1;
}
void *thread2(void *_val)
{
	printf("thread2 returning...\n");
	pthread_exit((void*)2);
}
void *thread3(void *_val)
{
	while(1){
		printf("thread3 returning...\n");
		usleep(200000);
	}

}
int main()
{
	void *tret;
	pthread_t tid1;
	pthread_create(&tid1,NULL,thread1,"other pthread1 run\n");
	pthread_join(tid1,&tret);
	printf("thread1 id:%d return code:%d\n",(unsigned long)tid1,(int)tret);

	pthread_t tid2;
	pthread_create(&tid2,NULL,thread2,"other pthread2 run\n");
	pthread_join(tid2,&tret);
	printf("thread1 id:%d return code:%d\n",(unsigned long)tid2,(int)tret);

	pthread_t tid3;
	pthread_create(&tid3,NULL,thread3,"other pthread3 run\n");
	sleep(1);
	pthread_cancel(tid3);
	pthread_join(tid3,&tret);//线程等待，新线程没运行完就会一直阻塞在这里
	printf("thread1 id:%d return code:%d\n",(unsigned long)tid3,(int)tret);

	printf("main pthread run:pid is %d,tid is %d\n",getpid(),(unsigned long long)pthread_self());

	sleep(1);
	return 0;
}


