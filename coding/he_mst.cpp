#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;

const long long int MAX=100005;
long long int id[MAX];

void initialize()
{
    for(long long int i = 0;i < MAX;++i)
        id[i] = i;
}

long long int root(long long int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(long long int x, long long int y)
{
    long long int p = root(x);
    long long int q = root(y);
    id[p] = id[q];
}


long long int maxspan(multimap<long long int, pair<long long int, long long int>,  greater<long long int> > p, long long int m)
{
	long long int x,y,c,i,maxc=0;
	
	multimap<long long int, pair<long long int, long long int>,  greater<long long int> > :: iterator pos;
	
	/*for(i=0;i<m;i++)
	{
		x=p[i].second.first;
		y=p[i].second.second;
		c=p[i].first;
		
		if(root(x)!=root(y))
		{
			maxc+=c;
			union1(x,y);
		}
	}*/
	
	for(pos=p.begin();pos!=p.end();pos++)
	{
		x=(pos->second).first;
		y=(pos->second).second;
		c=pos->first;
		
		
		if(root(x)!=root(y))
		{
			maxc+=c;
			union1(x,y);
		}
	}
	
	
	return maxc;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	long long int n,m,c,i,maxcost,x,y,cost;
    	cin>>n>>m;
    	
    	multimap<long long int, pair<long long int, long long int>, greater<long long int> > p;
    	initialize();
    	
    	for(i=0;i<m;i++)
    	{
    		long long int a,b,c;
    		cin>>a>>b>>c;
    		
    		p.insert(make_pair(c, make_pair(a,b)));
    	}
    	
    
    	
    	//
    	//cout<<maxcost<<endl;
    
    multimap<long long int, pair<long long int, long long int>,  greater<long long int> > :: iterator pos;

    for(pos=p.begin();pos!=p.end();pos++)
    {
        x=(pos->second).first;
        y=(pos->second).second;
        cost=pos->first;

        cout<<x<<" "<<y<<" "<<cost<<endl;

    	
    }

    maxcost=maxspan(p,m);
    cout<<maxcost<<endl;

    }
    return 0;
}
