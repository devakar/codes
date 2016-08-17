#include <bits/stdc++.h>
//#include <unordered_map>
using namespace std;
//unordered_map< string, int> m;
void dist_pal_substr(string s)
{
	int n=s.size();
	int i,j,k,count=0;

	map<string,int> m;
	 
	for(i=0;i<n;i++)
	{
		string s3(s,i,1);
		m[s3]=1;

		j=i-1;
		k=i+1;

		while(j>=0 && k<n && s[j]==s[k])
		{
			string s2(s,j,k-j+1);
			m[s2]=1;
			count++;
			j--;
			k++;
		}

		j=i;
		k=i+1;

		while(j>=0 && k<n && s[j]==s[k])
		{
			string s2(s,j,k-j+1);
			m[s2]=1;
			count++;
			j--;
			k++;
		}
	}

	cout<<"the number of all palindrome substring is :"<<count+n<<endl;
	cout<<"the number of unique palindrome substring is:"<<m.size()<<endl;
	cout<<"the unique palindrome substrings are :"<<endl;

	map<string,int>::iterator pos;
	for(pos=m.begin();pos!=m.end();pos++)
		cout<<pos->first<<endl;
}

int main()
{
	string s="abaaa";
	dist_pal_substr(s);
}
