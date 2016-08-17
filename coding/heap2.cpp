#include <iostream>
#include <algorithm>

using namespace std;

max_heapify(int a[], int i, int n)
{
	int l=2*i;
	int r=2*i+1;
	int largest;
	if(l<n && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(a,largest,n);
	}
}

void heap_build(int a[], int n)
{
	for(int i=(n/2);i>=0;i--)
		max_heapify(a,i,n);
}

void heap_sort(int a[], int n)
{
	heap_build(a,n);
	int heap_size=n;
	for(int i=n-1;i>0;i--)
	{
		swap(a[i],a[0]);
        max_heapify(a,0,--heap_size);
	}
}

int main()
{
	int n,i;
		
	cin>>n;
	int a[n];	
	for(i=0;i<n;i++)
		cin>>a[i];

	//heap_build(a,n);

	heap_sort(a,n);

	for(i=0;i<n;i++)
		cout<<a[i]<<"\t";
}