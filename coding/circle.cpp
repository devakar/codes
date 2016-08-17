#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        {
        int d,k;
        cin>>d>>k;
        int c=4,l=0;
        for(int x=1;x<sqrt(d);x++)
            {
            for(int y=1;y<sqrt(d);y++)
                {
                    l++;
                
                    

                if(x*x + y*y ==d )
                {
                    c=c+4;
                    break;
                }
                    
                if(x*x + y*y>d)
                    break;
                
            }
        }

        cout<<l<<"times entered in the loop"<<endl;
        if(k<c)
            cout<<"impossible"<<endl;
        else
            cout<<"possible"<<endl;
    }
    return 0;
}
