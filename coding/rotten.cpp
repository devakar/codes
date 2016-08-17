#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <limits>
#include <queue>
#define MAX 50
using namespace std;

int m[MAX][MAX];

typedef struct loc 
{
	int x;
	int y;
}index;

bool isdelim(index i)
{
	return (i.x==-1 && i.y==-1);
}

bool isvalid(int m[MAX][MAX],int r, int c, int i, int j)
{
	return (i>=0 && i<r && j>=0 && j<c && m[i][j]==1);
}

bool isone(int m[MAX][MAX], int r, int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			if(m[i][j]==1)
				return true;
	}
	return false;
}

int main() {
	// your code goes here
	int r,c;
	cin>>r>>c;
	int i,j,k;
	queue<index> q;
	index temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			{
				cin>>m[i][j];
				if(m[i][j]==2)
					{
						temp.x=i;
						temp.y=j;
						q.push(temp);
					}
			}
	}
	
	temp.x=-1;
	temp.y=-1;
	q.push(temp);
	
	int row[]={0,-1,0,1};
	int col[]={-1,0,1,0};
	
	bool flag;
	int count=0;
	
	while(!q.empty())
	{
		flag=false;
		while(!isdelim(q.front()))
		{
			temp=q.front();
			q.pop();
			i=temp.x;
			j=temp.y;
			for(k=0;k<4;k++)
			{
				if(isvalid(m,r,c,i+row[k],j+col[k]))
				{
					if(!flag)
						{
							count++;
							flag=true;
						}
					m[i+row[k]][j+col[k]]=2;
					index temp2;
					temp2.x=i+row[k];
					temp2.y=j+col[k];
					q.push(temp2);
				}
			}
		}
		q.pop();
		if(!q.empty())
		{
			temp.x=-1;
			temp.y=-1;
			q.push(temp);
		}
	}
  
    if(isone(m,r,c))
    	cout<<"-1"<<endl;
    else
    	cout<<count<<endl;
	
	
	return 0;
}

