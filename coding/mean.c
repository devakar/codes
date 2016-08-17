#include<stdio.h>
#include "get.c"


void main()
{
	int n,i;
	float mean;
	printf("enter the no. of elements");
	scanf("%d",&n);
	int* a;
	a=GetTheSet(n);
	mean=ComputeMean(a,n);
	printf("%f",mean);

}