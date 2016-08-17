#include <iostream>
#include <pthread.h>

using namespace std;

void* show1(void* i)
{
	long j;
	j=(long)i;
	if(j==0)
	{
		cout<<"good"<<"good";
		//pthread_exit(NULL);
	}
		
	else if(j==1)
	{
		cout<<"morning.\n"<<"evening.\n";
		//pthread_exit(NULL);
	}
	pthread_exit(NULL);	
	

}

int main()
{
	pthread_t thread[2];

	pthread_create(&thread[0],NULL,show1,(void *)0);
	pthread_create(&thread[1],NULL,show1,(void *)1);

	pthread_exit(NULL);

	return 0;

}