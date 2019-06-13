#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int global = 0;
void *thread_run(void *_val)
{
//	int i = 0;
//	while(i <=10){
//		sleep(1);
//		printf(_val,i);
//		++i;
//	}
//	printf("%s:pid is %d,tid is %d\n",(char*)_val,getpid(),(unsigned long long)pthread_self());
//	exit(1);
//
	++global;
	printf(_val,global);
}

int main()
{
	//sleep(1);
	pthread_t tid1;
	int err1 = pthread_create(&tid1,NULL,thread_run,"other pthread1 run %d\n");
	printf("%d\n",err1);

	sleep(1);
	pthread_t tid2;
	int err2 = pthread_create(&tid2,NULL,thread_run,"other pthread2 run %d\n");
	printf("%d\n",err1);

	sleep(1);
	pthread_t tid3;
	int err3 = pthread_create(&tid3,NULL,thread_run,"other pthread3 run %d\n");
	printf("%d\n",err1);

	int zero = 0;
	while(zero <= 3){
		sleep(1);
		printf("in main pthread %d\n",zero);
		++zero;
	}
	printf("main pthread run:pid is %d,tid is %d\n",getpid(),(unsigned long long)pthread_self());

	sleep(5);
	//return 0;
}
