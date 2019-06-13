#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *thread1(void *_val)
{
	pthread_detach(pthread_self());//1.在新线程分离
	printf((char*)_val);
	sleep(2);
	return NULL;
}
void *thread2(void *_val)
{//                          2.在主线程分离
	printf((char*)_val);
	return NULL;
}
int main()
{
	void *tret;
	pthread_t tid1;
	pthread_create(&tid1,NULL,thread1,"other pthread1 run\n");
	sleep(1);//特别注意，1.新线程中设置分离，主线程是看不到的；2.所以主线程可以用pthread_join等待，但是要稍微睡上一秒，否则会出错
	if(pthread_join(tid1,NULL) == 0)//                                                 要睡的原因可能是线程还没来得及回收资源
		printf("wait success\n");
	else
		printf("wait failed\n");
	//sleep(2);
//	pthread_join(tid1,&tret);//等待失败在所难免，新线程的分离对于主线程来说是看不到的，主线程会一直去等待新线程，殊不知新线程已经被操作系统释放
//	printf("thread1 id:%d return code:%d\n",(unsigned long)tid1,(int)tret);

	pthread_t tid2;
	pthread_create(&tid2,NULL,thread2,"other pthread2 run\n");
	pthread_detach(tid2);//在主线程中设置分离,此时主线程是看得到的
////	if(pthread_join(tid2,NULL) == 0)//虽然pthread_join等待是无意义的，但是放在这也不会出错
////		printf("wait success\n");
////	else
////		printf("wait failed\n");

	printf("main pthread run:pid is %d,tid is %d\n",getpid(),(unsigned long long)pthread_self());

	return 0;
}



