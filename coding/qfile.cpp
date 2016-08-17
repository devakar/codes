#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test,t;
	cin>>test;

	for(t=1;t<=test;t++)
	{
		int n;
		cin>>n;

		map<int,int> m;

		int i,per,fil;

		for(i=0;i<n;i++)
		{
			cin>>per>>fil;
			m[per]=fil;
		}

		if(m.find(100)!=m.end())
		{
			cout<<"Case #"<<t<<": "<<m[100]<<endl;
			continue;
		}
			
		map<int,int> :: iterator pos;
		for(pos=m.begin();pos!=m.end();pos++)
		{
			if(m.find(100-pos->first)!=m.end())
			{
				cout<<"Case #"<<t<<": "<<m[pos->first]+m[100-pos->first]<<endl;
				break;
			}
		}

		if(pos==m.end())
			cout<<"Case #"<<t<<": -1"<<endl;


	}
}