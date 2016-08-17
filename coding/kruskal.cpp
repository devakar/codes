#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

void initialise(int id[],int n)
{
	for(int i=0;i<n;i++)
		id[i]=i;
}

int root(int id[],int x)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}

void union1(int id[],int x,int y)
{
	int root_x=root(id,x);
	int root_y=root(id,y);
	id[root_x]=id[root_y];
}

int kruskal(pair<int, pair<int,int> > *p, int id[], int e)
{
	int x,y,cost,mincost=0;
	for(int i=0;i<e;i++)
	{
         x=p[i].second.first;
         y=p[i].second.second;
         cost=p[i].first;

         if(root(id,x)!=root(id,y))
         {
         	cout<<x<<"--"<<y<<"  : "<<cost<<endl;
         	mincost+=cost;
         	union1(id,x,y);
         }
	}
	return mincost;
}

int main()
{
	int n,e,i;
	cin>>n>>e;
	pair<int, pair<int,int> > p[e];
	//pair<int, pair<int,int> > q[e];
    int x,y,w,mincost;
    for(i=0;i<e;i++)
    {
    	cin>>x>>y>>w;
    	p[i]=make_pair(w, make_pair(x,y));
    }

    //sort the edges according to wieght of edge
    sort(p,p+e);

    //union disjoint set 
    int id[n];
    initialise(id,n);

    mincost=kruskal(p,id,e);
    cout<<"minimum weight of spanning tree by kruskal algorithm is :"<<mincost<<"\n";
    return 0;
}