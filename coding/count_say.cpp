#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

string convert_itos(int n)
{
	stringstream ss;
    ss<<n;
    string s=ss.str();

    return s;
}

string countAndSay(int n) {
        string s;
        if(n==1)
          {
              s="1";
              return s;
          }
          
         if(n==2)
          {
              s="11";
              return s;
          }
        
        if(n>2)
        {
            s="11";
            int c=2;
            int l,i,p;
            string ns;
            
            while(c < n)
            {
                l=s.length();
                ns="";
                i=0;
                
                while(i<l)
                {
                    p=1;
                    
                    while((i+1)<l && s[i]==s[i+1])
                    {
                        p++;
                        i++;
                    }
                    
                    ns=ns+convert_itos(p) + s[i] ;
                    
                    i++;
                }
                
                s=ns;
                
                c++;
                
            }
            
            return s;
        }
    }

    int main()
    {
    	int n=5;

    	cout<<countAndSay(n)<<endl;
    }