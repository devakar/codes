#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int l=s.length();

	stack <char> st;

	for(int i=0;i<l;i++)
	{

		st.push(s[i]);
	}

	for(int i=0;i<l;i++)
	{

		s[i]=st.top();
		st.pop();
	}

	cout<<"Reverse is "<<s<<endl;

	return 0;
}