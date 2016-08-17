#include <iostream>
#include <string>

using namespace std;

void print(string line[])
{
	int p=0;
	for(int j=0;j<2;j++)
    {

    	for(int k=0;k<3;k++)
    		if(p==0 && line[j][k]=='*')
    			cout<<"* is present at"<<j<<","<<k<<endl;

    }
}


int main()
{
	int n;
	cin>>n;
	string line[n];
	for(int i=0;i<n;i++)
	{
		getline(cin,line[i]);
	}

	int l;
	cin>>l;
    for(int j=0;j<2;j++)
    {
    	for(int k=0;k<3;k++)
    		cout<<line[j][k]<<endl;
    }
    cout<<l<<endl;
   print(line);
}
 
// n must be passed before the 2D array
