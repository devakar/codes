#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int r,i,j;
	cin>>r;

	vector<vector <int> > v;
	v.resize(r);

	for(i=0;i<r;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(j==0 ||j==i)
				v[i].push_back(1);
			else
				v[i].push_back(v[i-1][j-1]+v[i-1][j]);
		}
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<v[i].size();j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}