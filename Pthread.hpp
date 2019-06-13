//getrlimit(2), pthread_create(3) pthread_attr_init(3), pthread_cancel(3), pthread_detach(3), pthread_equal(3), pthread_exit(3),
//       pthread_getattr_np(3), pthread_join(3), pthread_self(3), pthreads(7)
#include<iostream>
#include<pthread.h>

class Pthread{
	private:
		static void *func(void *arg)
		{
			cout << "Pthread" << endl;
		}
	public:
		Pthread()
		{
		}
		~Pthread()
		{
		}
		int Pthread_create()
		{
			//int pthread_create(pthread_t *tid,const pthread_attr_t *attr,void *(*start_routine)(void*),void *arg);
			//tid : 输出型参数，获取一个tid，即用户态线程id。（这个tid实际上是一个虚拟地址空间中的地址，是线程地址空间的首地址。\
			//      每一个线程在虚拟地址空间中都有自己独有的线程地址空间存储自己的数据）
			//attr : 设置线程的属性，通常置空NULL。
			//start_routine : 线程入口函数
			//arg : 入口函数的参数
			//返回值：成功返回0，失败返回错误号。
			pthread_t tid;
			return pthread_create(&tid,NULL,func,NULL);
		}

		
};
