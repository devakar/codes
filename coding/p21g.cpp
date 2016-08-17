#include<bits/stdc++.h>
#include<iostream>
using namespace std;

typedef pair<int, vector<int> > PIV;
typedef pair<int,int> PII;

int solve(int s, int d, int st, vector<PIV> *adj,int dist[],int n)
{
  int i=0;
  for(i=0;i<=n;i++)
  	dist[i]=-1;
  dist[s]=0;

  priority_queue<PII,vector<PII>, greater<PII> > pq;
  PII p;

  pq.push(make_pair(0,s));

  int x,y,c,t=st;

  while(!pq.empty())
  {
  	p=pq.top();
  	pq.pop();
  	x=p.second;
    t=p.first;
  	for(i=0;i<adj[x].size();i++)
  	{
  		y=adj[x][i].first;
  		c=adj[x][i].second[t];
  		d=dist[x]+c;

  		if(dist[y]==-1 || dist[y]>d)
  		{
  			dist[y]=d;
  			pq.push(make_pair(d,y));
  		}
  	}
  	
  }
  return dist[d];
}

int main()
{
	//freopen("0.in","r",stdin);
	//freopen("0.out","w",stdout);

	int T,test = 0;
	cin>>T;

	while(T--){
		test++;
		
        int n,m,k;
        cin>>n>>m>>k;

        vector<PIV> adj[n+1];
        vector<int> tc;
        pair<int,int> p[k];

        int x,y,w,i,j,d,t;

        for(i=0;i<m;i++)
        {
        	cin>>x>>y;
        	for(j=0;j<24;j++)
        	{
        		cin>>w;
        		tc.push_back(w);        	
        	}
        	adj[x].push_back(make_pair(y,tc));
        	adj[y].push_back(make_pair(x,tc));
        }

        int dist[n+1];
        cout<<"Case #"<<test<<": ";
        for(i=0;i<k;i++)
        {
           cin>>d>>t;
          
           cout<<solve(1,d,t,adj,dist,n)<<" ";
        }
        cout<<endl;
		
	}
    
    return 0;
}