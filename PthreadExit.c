#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_run(void *_val)
{
	int i = 1;
	while(i++ < 9){
		sleep(1);  //为了防止线程反应不过来，我就先睡了一秒
		printf("[ %d ]",i);
		printf((char*)_val);
	}
	printf("i can arrive here+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	//printf(_val);
//	pthread_exit(NULL);//线程终止方法二 (方法三：注意,还可以不写线程终止语句)
//	return (void*)-1;//线程终止方法一
	//exit(1);//如果任意一个线程调用了exit或_exit,则整个进程的所有进程都会终止.
}

int main()
{
	pthread_t tid1;
	pthread_create(&tid1,NULL,thread_run,"other pthread1 run \n");
	pthread_cancel(tid1);  //线程终止方法四

	pthread_t tid2;
	pthread_create(&tid2,NULL,thread_run,"other pthread2 run \n");
//	pthread_cancel(tid2);//方法四         +++++++++++++++++++++++++把该语句注释掉之后能正常打印出八句话++++++++++++++++++++++++

	pthread_t tid3;
	pthread_create(&tid3,NULL,thread_run,"other pthread3 run \n");
	pthread_cancel(tid3);//方法四

	printf("main pthread run:pid is %d,tid is %d\n",getpid(),(unsigned long long)pthread_self());

	sleep(20);
	printf("in main pthread sleep 20s\n");//睡20秒是为了防止主线程先于新线程退出
	return 0;
}

