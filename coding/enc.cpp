#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	string s="chillout";
	string t;
	//cin>>S;
	int n=s.length();
	int rows=floor(sqrt(n));
	int columns=ceil(sqrt(n));

	if(rows*columns<n)
		rows+=1;
	

	char c[rows][columns];

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
			c[i][j]=' ';

	}
	int k=0;

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			c[i][j]=s[k];
			k+=1;
		}
	}

    for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
			cout<<c[i][j];
		cout<<endl;

	}
   cout<<endl;
   
   int l=0;

   for(int i=0;i<columns;i++)
   {
   	for(int j=0;j<rows;j++)
   	{
   		t[l]=c[j][i];
   		l+=1;
   	}

        t[l]=' ';
        l+=1;
   	
   }

   for(int i=0;i<l;i++)
   	cout<<t[i];
}