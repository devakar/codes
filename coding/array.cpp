#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

//Given an array A[] and a number x, check for pair in A[] with sum as x (using hash map)
bool isPairSum(int a[],int n,int x)
{
	map <int ,int> m;

	for(int i=0;i<n;i++)
	{
		m.insert(make_pair(a[i],1));
	}

	for(int i=0;i<n;i++)
	{
		int temp=x-a[i];
		if(temp>=0 && m[a[i]]==1)
			return true;
	}

	return false;

}

//find majority element in the array by using moore's voting algorithm

//finding the candidate for majority element ,if there exists a majority element then it will return majority element otherwise it will any element
int candidate(int a[],int n)
{
	int major=0, count=1;

	for(int i=1;i<n;i++)
	{
		if(a[major]==a[i])
			count++;
		else
			count--;
		if(count==0)
		{
			major=i;
			count=1;
		}
	}

	return a[major];
}

//checking whether the candidate for majority element is majority element or not
bool isMajority(int a[],int n)
{
	int cand=candidate(a,n);
	int count=0;

	for(int i=0;i<n;i++)
	{
		if(a[i]==cand)
			count++;
	}
	if(count>n/2)
		return true;

	return false;
}


//Largest Sum Contiguous Subarray
int maxSumContiguous(int a[],int n)
{
	int cur_max=a[0];
	int maximum=a[0];

	for(int i=0;i<n;i++)
	{
		cur_max=max(a[i],cur_max+a[i]);
		maximum=max(cur_max,maximum);
	}
	return maximum;
}


int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n=sizeof(a)/sizeof(a[0]);
	//int x=16;

	//cout<<isPairSum(a,n,x)<<endl;
	//cout<<isMajority(a,n)<<endl;
	cout<<"Largest sum of contiguous subarray is  "<<maxSumContiguous(a,n)<<endl;

	return 0;
}