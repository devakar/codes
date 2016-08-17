#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

int prim(int s, vector<pair<int,int> > *adj, bool visited[])
{
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(s,0));
	pair<int,int> p;
	int x,y,cost,mincost=0,pre=s;

	cout<<"the edges are :"<<endl;
	cout<<"u---v   : w"<<endl;

	while(!pq.empty())
	{
        p=pq.top();
        pq.pop();

        x=p.second;
        cost=p.first;

        if(visited[x])
        	continue;

        mincost+=cost;
        visited[x]=true;

        if(pre!=x)
        {
        	cout<<pre<<"---"<<x<<"   : "<<cost<<endl;
        	pre=x;
        }
        	

        for(int i=0;i<adj[x].size();i++)
        {
        	y=adj[x][i].second;
        	if(!visited[y])
        		pq.push(adj[x][i]);
        }
	}
	return mincost;
}

int main()
{
	int n,e;
	cin>>n>>e;

	vector<pair<int,int> > adj[n];
	int x,y,w,i,mincost;

	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(w,y));
		adj[y].push_back(make_pair(w,x));
	}

	bool visited[n];
	for(i=0;i<n;i++)
		visited[i]=false;

	mincost=prim(0,adj,visited);
	cout<<"minimum cost of spanning tree : "<<mincost<<endl;
	return 0;
}
