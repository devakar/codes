#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

const long long int MAX=31320;
long long int id[MAX];
#define bs 1000000007

void initialize()
{
	long long int i;
	for(i=0;i<MAX;i++)
	    id[i]=i;
}

long long int root(long long int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(long long int x, long long int y)
{
	long long int p=root(x);
	long long int q=root(y);
	id[p]=id[q];
}

long long int mincoeff(multimap<long long int, pair<long long int, long long int> >p)
{
	long long int a,b,c,minc=1;
	
	multimap<long long int, pair<long long int, long long int> > :: iterator pos;
	
	for(pos=p.begin(); pos!=p.end(); ++pos)
	{
		a=(pos->second).first;
		b=(pos->second).second;
		c=pos->first;
		
		if(root(a)!=root(b))
		{
			minc=(minc*c)%bs;
			union1(a,b);
		}
		
	}
	//minc=minc%;
	return minc;
	
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	long long int n,m,i,coeff,x,y,cost;
    	cin>>n>>m;
    	
    	multimap<long long int, pair<long long int, long long int> >p;
    	initialize();
    	
    	for(i=0;i<m;i++)
    	{
    		long long int a,b,c;
    		cin>>a>>b>>c;
    		p.insert(make_pair(c, make_pair(a,b)));
    	}
    	
    	multimap<long long int, pair<long long int, long long int> > :: iterator pos;

        for(pos=p.begin();pos!=p.end();pos++)
    {
        x=(pos->second).first;
        y=(pos->second).second;
        cost=pos->first;

        cout<<x<<" "<<y<<" "<<cost<<endl;

    	
    }

    	coeff=mincoeff(p);
    	cout<<coeff<<"\n";
    }
    return 0;
}
