#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string s;
	cin>>s;

	stack <int> st;


	int l=s.length();

	for(int i=0;i<l;i++)
	{
		if(isdigit(s[i]))
			st.push(s[i]-'0');

		else
		{
			int num1=st.top();
			st.pop();
			int num2=st.top();
			st.pop();
			switch(s[i])
			{
				case '+':st.push(num2+num1);
				         break;
				case '-':st.push(num2-num1);
				          break;
				case '*':st.push(num2*num1);
				          break;
				case '/':st.push(num2/num1);
				          break;
				case '^':st.push(num2^num1);
				          break;

			}
		}
	}

	cout<<"The value of the expression is "<<st.top()<<endl;
	st.pop();

	return 0;
}