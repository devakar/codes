#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#define MAX 40005



using namespace std;
typedef long long int LL;

LL id[MAX];

void initialize()
{
	for(LL i=0;i<MAX;i++)
	  id[i]=i;
}

LL root(LL x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(LL a, LL b)
{
	LL p=root(a);
	LL q=root(b);
	id[p]=id[q];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	LL n,m,i;
    	cin>>n;
    	cin>>m;
    	
    	pair<LL, LL> p[MAX];
    	
    	
    	for(i=1;i<=m;i++)
    	{
    		LL x,y;
    		cin>>x>>y;
    		p[i]=make_pair(x,y);
    	}

       /*for(i=1;i<=m;i++)
        {
            cout<<p[i].first<<" "<<p[i].second<<endl;
        }*/
    	
    	initialize();
    	
    	for(i=1;i<n;i++)
    	{
    		LL j,a,b;
    		cin>>j;
    		a=p[j].first;
    		b=p[j].second;
            cout<<endl;
            cout<<a<<" "<<b<<endl;
    		//a=root(a);
    		//b=root(b);
            //cout<<a<<" "<<b<<endl;
    		union1(a,b);

    	}
    	
    	LL count=0;
    	
    	for(i=1;i<=n;i++)
    	{
    		if(id[i]==i)
    		  count++;
            cout<<id[i]<<" ";
    	}
    	
       count==1 ? cout<<"YES\n" : cout<<"NO\n";
    	
    }
    return 0;
}
