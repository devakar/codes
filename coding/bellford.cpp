#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <climits>

using namespace std;

bool bellford(int s, vector<pair<int,int> > *adj, bool visited[], int dist[], int parent[],int n,int e)
{
	//priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	queue<pair<int,int> >pq;
	pq.push(make_pair(s,0));
	pair<int,int> p;
	int x,y,cost,mincost=0,pre=s,d,c;

	//cout<<"the edges are :"<<endl;
	//cout<<"u---v   : w"<<endl;

	 for(int i=0;i<n;i++)
    {
    	dist[i]=INT_MAX;
    	parent[i]=-1;
    }
    dist[s]=0;

	while(!pq.empty())
	{
        p=pq.front();
        pq.pop();

        x=p.second;
        cost=p.first;

        //if(visited[x])
        //	continue;

        //mincost+=cost;
        visited[x]=true;

        /*if(pre!=x)
        {
        	cout<<pre<<"---"<<x<<"   : "<<cost<<endl;
        	pre=x;
        }*/
        	

        for(int i=0;i<adj[x].size();i++)
        {
        	y=adj[x][i].second;
        	c=adj[x][i].first;
        	d=dist[x]+c;
        	if(dist[y]>d)
        	{
        		dist[y]=d;
        		parent[y]=x;
                adj[x][i].first=d;
                if(!visited[y])
        		    pq.push(adj[x][i]);
        	}
        	
        }
	}
	
    

	return true;
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
		//adj[y].push_back(make_pair(w,x));
	}

	bool visited[n];
	for(i=0;i<n;i++)
		visited[i]=false;

	int dist[n];
	int parent[n];
    int s=0;
	if(bellford(s,adj,visited,dist,parent,n,e))
	{
         for(i=0;i<n;i++)
         	cout<<dist[i]<<" ";
         cout<<endl;
	}
	else
		cout<<"there is a negative weight cycle"<<endl;
	
	return 0;
}
