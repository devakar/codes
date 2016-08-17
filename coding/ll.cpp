#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    string s;
    cin>>t;
    for(int i=0;i<t;i++)
        {
        cin>>s;
        int n=s.size();

        //cout<<n<<endl;
        int op=0;
        
        if(n==1)
            {
            op=0;
            cout<<op<<endl;
        }
        
       else if(n==2)
            {
            if(s[0]==s[1])
                {
                op=0;
                cout<<op<<endl;
            }
            else
                {
                if(int(s[0]) > int(s[1]))
                    {
                    op=int(s[0]) - int(s[1]);
                    cout<<op<<endl;
                }
                else
                    {
                    op=int(s[1]) - int(s[0]);
                    cout<<op<<endl;
                }
                    
            }
        }
        
       else
           { 
            //cout<<"the"<<endl;
            //cout<<(int)ceil((float)n/2)<<endl;
           for(int i=0;i<(n/2);i++)
               {
                
               if(int(s[i]) > int(s[n-1-i]))
                   op+= (int(s[i]) - int(s[n-1-i]));
               else
                   op+=(int(s[n-1-i]) - int(s[i]));
           }
           cout<<op<<endl;
       }
        
    }
    
    return 0;
}
