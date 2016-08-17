#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> adj[10];
bool visited[10];

 /*void dfs(int s ,bool visited[], vector <int> (&adj)[])
 {
 	visited[s]=true;
 	cout<<s<<" ";

 	for(int i=0;i<adj[s].size();i++)
 	{
 		if(!visited[adj[s][i]])
 			dfs(adj[s][i],&visited,adj);
 	}
    
 }*/


//dfs using recursion
void dfs(int s)
{
	visited[s]=true;
	cout<<s<<" ";

	for(int i=0;i<adj[s].size();++i)
	{
		if(!visited[adj[s][i]])
			dfs(adj[s][i]);
	}
}

//dfs without using recursion and using stack
dfs_stack(int s)
{
	stack <int> st;
	st.push(s);
	visited[s]=true;

	while(!st.empty())
	{
		int v=st.top();
		st.pop();

		cout<<v<<" ";

		for(int i=0;i<adj[v].size();i++)
		{
			if(!visited[adj[v][i]])
			{
				st.push(adj[v][i]);
			    visited[adj[v][i]]=true;
			}
			
		}
	}
}


//bfs using queue
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	visited[s]=true;

	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		cout<<v<<" ";

		for(int i=0;i<adj[v].size();++i)
		{
			if(!visited[adj[v][i]])
			{
				q.push(adj[v][i]);
				visited[adj[v][i]]=true;
			}
		}
	}
}


int main()
{
	int nodes,edges;
	cout<<"enter the no. of verices"<<endl;
	cin>>nodes;
	cout<<"enter the no. of edges"<<endl;
	cin>>edges;

	//vector <int> adj[nodes+1];

	for(int i=0;i<edges;i++)
	{
		int x,y;
		cout<<"enter the edge"<<endl;
		cin>>x;
		cin>>y;

		adj[x].push_back(y);
	}
    
    int s;
	cout<<"enter the source "<<endl;
	cin>>s;
    
    //bool visited[nodes+1];

    for(int i=0;i<10;i++)
    	visited[nodes]=false;

    //dfs(s);
    //cout<<endl;
    //dfs_stack(s);
    cout<<endl;

    /*int connectedComponents=0;

    for(int i=1;i<=nodes;++i)
    {
    	if(!visited[i])
    	{
    		dfs(i);
    	    connectedComponents++;
    	}
    		
    }

    cout<<endl<<"The number of connected components are "<<connectedComponents<<endl;*/

    bfs(s);

}