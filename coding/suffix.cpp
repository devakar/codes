#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int suffarray[20];

typedef struct Suffix
{
	int index;
	int rank[2];
}suffix;

bool comp(suffix s1, suffix s2)
{
	return ( (s1.rank[0]==s2.rank[0]) ? (s1.rank[1]<s2.rank[1] ? true:false) : (s1.rank[0]<s2.rank[0] ? true:false) );
}

void build(string s)
{
	int n=s.size();
	int i,k;
	suffix suff[n];
	
	for(i=0;i<n;i++)
	{
		suff[i].index=i;
		suff[i].rank[0]= s[i]-'a';
		suff[i].rank[1]= ((i+1)<n) ? (s[i+1]-'a') :-1;
		
	}
	
	sort(suff,suff+n,comp);
	int ind[n];
	
	for(k=4;k<2*n;k*=2)
	{
		int rank=0;
		int pre_rank=suff[0].rank[0];
		suff[0].rank[0]=rank;
		ind[suff[0].index]=0;
		
		for(i=1;i<n;i++)
		{
			if(suff[i].rank[0]==pre_rank && suff[i].rank[1]==suff[i-1].rank[1])
			{
				pre_rank=suff[i].rank[0];
				suff[i].rank[0]=rank;
			}
			else
			{
				pre_rank=suff[i].rank[0];
				suff[i].rank[0]=++rank;
			}
			ind[suff[i].index]=i;
		}
		
		for(i=0;i<n;i++)
		{
			int next=suff[i].index+k/2;
			suff[i].rank[1]=(next<n)?suff[ind[next]].rank[0] :-1;
		}
		
		sort(suff,suff+n,comp);
	}
	
	//int suffarray[n];
	for(i=0;i<n;i++)
		suffarray[i]=suff[i].index;
		
	//return suffarray;
}

int main() {
	// your code goes here
	string s="abdcasd";
	int n=s.size();
	//int *suffarray=
	build(s);
	int i;
	for(i=0;i<n;i++)
		cout<<suffarray[i]<<" ";
	return 0;
}