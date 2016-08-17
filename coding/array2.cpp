#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;



//inversion count using merge sort.

int merge(int a[], int temp[], int l, int mid, int r)
{
	int i=l,j=mid+1,k=l,inv_count=0;

	while(i<=mid && j<=r)
	{
		if(a[i]>a[j])
		{
			temp[k++]=a[j++];
			inv_count+= mid-i+1;
		}
		else
			temp[k++]=a[i++];
	}

	while(i<=mid)
		temp[k++]=a[i++];

	while(j<=r)
		temp[k++]=a[j++];

	for(i=l;i<=r;i++)
		a[i]=temp[i];

    return inv_count;
}

int mergeSort(int a[], int temp[], int l, int r)
{
	int inv_count=0,mid;
	
	if(l<r)
	{
        mid=l+(r-l)/2;
		inv_count+=mergeSort(a,temp,l,mid);
		inv_count+=mergeSort(a,temp,mid+1,r);
		inv_count+=merge(a,temp,l,mid,r);
	}
	return inv_count;
}

int inversionCount(int a[], int n)
{
	int temp[n];
	return mergeSort(a,temp,0,n-1);
}

int main()
{
	int a[]={1,20,6,4,5};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<inversionCount(a,n);
	return 0;
}