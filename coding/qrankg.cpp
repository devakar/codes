#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long int LLI;


int main()
{
	int t,test;
	cin>>t;
	for(test=1;test<=t;test++)
	{
		int p;
		cin>>p;
		int s[p],i,j;
		for(i=0;i<p;i++)
			cin>>s[i];
		int n;
		cin>>n;
		
		map<string, priority_queue<int> > mq;
		map<int,string> mp;

		for(i=0;i<n;i++)
		{
			int w;
			cin>>w;
			for(j=0;j<p;j++)
			{	
				string name;
				cin>>name;
				mq[name].push(w*s[j]);
			}
		}

		int m,count;
		cin>>m;

		map<string, priority_queue<int> > :: iterator pos;

		for(pos=mq.begin();pos!=mq.end();pos++)
		{
			count=0;
			for(i=0;i<m;i++)
			{
				count+=(pos->second).top();
				(pos->second).pop();
			}
			mp[count]=pos->first;

		}


		map<int,string>:: reverse_iterator loc;
		int c=1;

		cout<<"Case #"<<test<<":"<<endl;
		for(loc=mp.rbegin();loc!=mp.rend();loc++)
		{
			cout<<c<<": "<<loc->second<<endl;
			c++;
		}


	}
}