#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

void dijkstra(int s,vector<pair<int,int> > *adj, int dist[], int parent[], int n, int e)
{
    for(int i=0;i<n;i++)
    {
    	dist[i]=INT_MAX;
    	parent[i]=-1;
    }
    dist[s]=0;

    priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pair<int,int> p;
    int x,y,cost,d,c,i;

    pq.push(make_pair(0,s));

    while(!pq.empty())
    {
         p=pq.top();
         pq.pop();
         x=p.second;
         cost=p.first;

         for(i=0;i<adj[x].size();i++)
         {
         	y=adj[x][i].second;
         	c=adj[x][i].first;
         	d=dist[x]+ c;

         	if(dist[y]>d)
         	{
         		dist[y]=d;
         		parent[y]=x;
         		adj[x][i].first=d;
         		pq.push(adj[x][i]);

         	}
         }

    }
}

int main()
{
	int n,e;
	cin>>n>>e;

	vector<pair<int,int> > adj[n];

	int x,y,w,i;

	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(w,y));
		adj[y].push_back(make_pair(w,x));
	}

	int dist[n];
	int parent[n];

	dijkstra(0,adj,dist,parent,n,e);

	for(i=0;i<n;i++)
		cout<<dist[i]<<", ";

}