#include <iostream>
#include "stdlib.h"

using namespace std;

struct heap
{
	int size;
	int *a;
};

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapMaxify(struct heap *maxheap, int index)
{
	int left=2*index+1;
	int right=2*index+2;
    int n=maxheap->size;
    int max=index;

	if(left<n && maxheap->a[left] > maxheap->a[index])
		max=left;

	if(right<n && maxheap->a[right] > maxheap->a[max])
		max=right;

    if(max !=index)
    {
    	swap(&maxheap->a[index],&maxheap->a[max]);
	    heapMaxify(maxheap,max);
    }
	
}


struct heap *buildMaxheap(int *b,int n)
{
	struct heap *maxheap=(struct heap *)malloc(sizeof(struct heap));
	maxheap->size=n;
	maxheap->a=b;
	for(int i=n/2; i>=0;i--)
	{
		heapMaxify(maxheap,i);
	}

    return maxheap;
}

void heapsort(int c[],int n)
{
	
	struct heap *maxHeap= buildMaxheap(c,n);

	while(maxHeap->size>1)
	{
		swap(&maxHeap->a[0], &maxHeap->a[maxHeap->size-1]);
		maxHeap->size--;
		heapMaxify(maxHeap,0);
	}
}

int main()
{
	int d[5]={5,4,3,1,2};
	int n=5;
	heapsort(d,n);
	for(int i=0;i<n;i++)
		cout<<d[i]<<"\t";

	return 0;
}