#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

 bool isValid(string s) {
        
        if(s.length() % 2 !=0)
          return false;
          
        stack <char> st;

        if(s[0]==')' || s[0]=='}' || s[0]==']')
        	return false;
        
        for(int i=0; i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
                
            }
            
            else
            {
                if(s[i]==')' && st.top()!='(')
                   return false;
                   
                if(s[i]=='}' && st.top()!='{')
                   return false;
                   
                if(s[i]==']' && st.top()!='[')
                   return false;
                   
                st.pop();
            }
              
              
        }
        
        
        return st.empty();
    }

    int main()
    {
    	string s="([)]";
    	cout<<isValid(s)<<endl;
    }