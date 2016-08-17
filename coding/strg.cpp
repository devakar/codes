#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string switchs(string s)
{
	for(long int i=0;i<s.size();++i)
	{
		if(s[i]=='1')
			s[i]='0';
		else if(s[i]=='0')
			s[i]='1';
	}
	return s;
}

int main()
{
	
	ifstream infile;
	ofstream outfile;
	infile.open("A-large-practice.in");
    outfile.open("output.txt",ios::app);
	int t;
	infile>>t;
	//cout<<t<<endl;
	int te=1;
	while(t--)
	{
		long int k;
		
		infile>>k;
		//cout<<k<<endl;
		string s="0";
		//long int i=2;
		//cout<<s<<" "<<s.size()<<endl;
        while(s.size() < k)
        {
        	string s1=s;
            //cout<<s1<<endl;
        	reverse(s.begin(),s.end());
        	//cout<<s<<endl;
        	s=s1+"0"+switchs(s);
        	//cout<<s<<endl;
        }
        //cout<<s[k-1]<<endl;
		outfile<<"Case #"<<te<<": "<<s[k-1]<<endl;
		te++;
	}
}