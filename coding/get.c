#include<stdio.h>
#define MAX 10

int* GetTheSet(int n)
{
	static int a[MAX];
	int i;
	printf("enter the elements");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	return a;
}

float ComputeMean(int a[],int n)
{
	int sum=0,i;
	float mean;
	for(i=0;i<n;i++)
		sum+=a[i];

	mean=(float)sum/n;
	return mean;
}