#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <climits>

using namespace std;

//simple method to get the kth smallest element from array of n element 
//and running time is O(n log n)
void ksmall_simple(int a[],int n,int k)
{
	sort(a,a+n);
	cout<<"Kth smallest element using simple method is :"<<a[k-1]<<endl;
}


//using min-heap to get the kth smallest element from array of n element 
//and running time is O(n log n)

struct heap
{
	int *array;
	int size;
};

void heapify(struct heap* minHeap, int index)
{
	int left=2*index+1;
	int right=2*index+2;
	int n=minHeap->size;
	int minIndex=index;

	if(left<n && minHeap->array[left]<minHeap->array[index])
		minIndex=left;

	if(right<n && minHeap->array[right]<minHeap->array[minIndex])
		minIndex=right;
    
    if(minIndex!=index)
    {
    	swap(minHeap->array[minIndex], minHeap->array[index]);
    	heapify(minHeap,minIndex);
    }
   
}

struct heap* buildHeap(int a[],int n)
{
	struct heap *minHeap=(struct heap *)malloc(sizeof(struct heap));
	minHeap->array=a;
	minHeap->size=n;

	for(int i=n/2 ; i>=0 ;i--)
	{
		heapify(minHeap,i);
	}
    
    return minHeap;
}

int extractMin(struct heap* minHeap)
{
	if(minHeap->size==0)
		return INT_MAX;

	int root=minHeap->array[0];

	if(minHeap->size >1)
	{
		minHeap->array[0]=minHeap->array[minHeap->size -1];
		minHeap->size--;
		heapify(minHeap,0);
	}

	return root;
}

void ksmall_minHeap(int a[],int n,int k)
{
	struct heap *minHeap=buildHeap(a,n);
	int ksmall;
	for(int i=0;i<k;i++)
	{
		ksmall=extractMin(minHeap);

	}
	cout<<"Kth smallest element by using min heap is :"<<ksmall<<endl;
}


//using max-heap to get the kth smallest element from array of n element 
//and running time is O(k+(n-k)log k)
void maxHeapify(struct heap *maxHeap,int index)
{
	int left=2*index+1;
	int right=2*index+2;
	int maxIndex=index;
	int n=maxHeap->size;

	if(left<n && maxHeap->array[left]>maxHeap->array[maxIndex])
		maxIndex=left;

	if(right<n && maxHeap->array[right]>maxHeap->array[maxIndex])
		maxIndex=right;

	if(maxIndex!=index)
	{
		swap(maxHeap->array[index], maxHeap->array[maxIndex]);
		maxHeapify(maxHeap,maxIndex);
	}
}


struct heap* build_maxHeap(int a[],int n)
{
	struct heap *maxHeap =(struct heap *)malloc(sizeof(struct heap));
	maxHeap->array=a;
	maxHeap->size=n;

	for(int i=n/2;i<=0;i--)
	{
		maxHeapify(maxHeap,i);
	}

	return maxHeap;
}

/*int extractMax(struct heap* maxHeap)
{
	int n=maxHeap->size;
	int root=maxHeap->array[0];
	if(n==0)
		return INT_MIN;
	if(n>1)
	{
		maxHeap->array[0]=maxHeap->array[n-1];
		maxHeap->size--;
		maxHeapify(maxHeap,0);

	}

	return root;
}*/

void ksmall_maxHeap(int a[],int n,int k)
{
	struct heap* maxHeap=build_maxHeap(a,k);
	int ksmall,max;

	for(int i=k;i<n;i++)
	{
		max=maxHeap->array[0];
		
		if(a[i]<max)
		{
			maxHeap->array[0]=a[i];
			maxHeapify(maxHeap,0);

		}
	}

    ksmall=maxHeap->array[0];
	cout<<"Kth smallest element by using max heap is :"<<ksmall<<endl;
}


//using quick selection find kth smallest element of the array
//and time complexity in worst case is O(n^2) but in average it is O(n)
int partition(int a[],int l, int r)
{
	int x=a[r];
	int i=l-1;

	for(int j=l;j<r;j++)
	{
		if(a[j]<=x)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void ksmall_quick(int a[],int l,int r,int k)
{
	int p=partition(a,l,r);
	if(p-l==k-1)
	{
		cout<<"Kth smallest element by using quick selection is :"<<a[p]<<endl;
		return;
	}
		

	if(p-l>k-1)
		ksmall_quick(a,l,p-1,k);

	else
		ksmall_quick(a,p+1,r,k-p+l-1);

}

//using random quick selection find the kth smallest element in the array
//and the worst case time complexity is O(n^2) but the expecteed time is O(n)
int randomPartition(int a[],int l,int r)
{
	int p=rand()%(r-l+1);
	swap(a[p+l],a[r]);
	return partition(a,l,r);
}

void ksmall_randomQuick(int a[],int l,int r,int k)
{
	int p=randomPartition(a,l,r);

	if(p-l==k-1)
	{
		//cout<<p<<endl;
		//cout<<a[2]<<endl;
		cout<<"Kth smallest element by using random quick selection is :"<<a[p]<<endl;
		return;
	}


	if(p-l>k-1)
		ksmall_randomQuick(a,l,p-1,k);

	else
		ksmall_randomQuick(a,p+1,r,k-p+l-1);
} 


//using median of medians for quick selection to find the kth smallest element in the array
//and the worst case time complexity is O(n)
int getMedian(int a[], int n)
{
	sort(a,a+n);
	return a[n/2];
}


int partitionMed(int a[], int l, int r, int x)
{
	int i;
	for(i=l;i<r;i++)
	{
		if(a[i]==x)
			break;
	}

	swap(a[i],a[r]);
	return partition(a,l,r);
}


void ksmall_medianOFMedian(int a[], int l, int r, int k)
{
	int n=r-l+1,i;
	int median[(n+4)/5];

	for(i=0;i<n/5;i++)
	{
		median[i]=getMedian(a+l+i*5,5);
	}

	if(i*5<n)
	{
		median[i]=getMedian(a+l+i*5,n%5);
		i++;
	}

	int medOfMed=(i==1)?median[i-1]:getMedian(median,i);
	int p=partitionMed(a,l,r,medOfMed);

	if(p-l==k-1)
	{
		cout<<"Kth smallest element by using median of medians in quick selection is :"<<a[p]<<endl;
		return;
	}
		

	if(p-l>k-1)
		ksmall_medianOFMedian(a,l,p-1,k);

	else
		ksmall_medianOFMedian(a,p+1,r,k-p+l-1);

}


int main()
{
	int a[]={7, 10, 4, 3, 20, 15};
	int b[]={12, 3, 5, 7, 19};
	int k=3;
	int c[] = {12, 3, 5, 7, 4, 19, 26};
	int d[] = {12, 3, 5, 7, 4, 19, 26};
	int e[]={12, 3, 5, 7, 4, 19, 26};
    int nd =sizeof(d)/sizeof(d[0]);
    int nc =sizeof(c)/sizeof(c[0]);
	int n=sizeof(a)/sizeof(a[0]);
	int nb=sizeof(b)/sizeof(b[0]);
    int ne=nc;

	ksmall_simple(a,n,k);
	ksmall_minHeap(a,n,k);
	ksmall_maxHeap(b,nb,k);
	ksmall_quick(c,0,nc-1,k);
	ksmall_randomQuick(d,0,nd-1,k);
	ksmall_medianOFMedian(e,0,ne-1,k);
}