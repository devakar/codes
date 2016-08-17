#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "math.h"

using namespace std;

double find(long int a[],int l,int r)
{
	double v1=1.0,side;
	int i;
	
	for(i=l;i<=r;i++)
		v1=v1*a[i];
    //cout<<v1<<endl;
	double len=r-l+1;
	double ilen=1/len;
	//cout<<ilen<<endl;
	side =pow(v1,ilen);
	//cout<<side<<endl;
   
	return side;

}

int main()
{
	
	ifstream infile;
	ofstream outfile;
	infile.open("B-small-attempt3.in");
    outfile.open("output2.txt",ios::app);
	int t;
	infile>>t;
	int te=1;
	while(t--)
	{
		int n,m,i;
		
		infile>>n>>m;
        long int a[n];
        for(i=0;i<n;i++)
        	infile>>a[i];

        //for(i=0;i<n;i++)
        //	cout<<a[i]<<endl;
        outfile<<"Case #"<<te<<":"<<endl;
        for(i=0;i<m;i++)
        {
        	int l,r;
        	infile>>l>>r;
        	//cout<<l<<" "<<r<<endl;
        	
        	outfile<<find(a,l,r)<<endl;
        }

       te++;
	}
}