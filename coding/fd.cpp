#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,m,c,r;
    cin>>t;
    
    
    for(int i=0;i<t;i++)
        {
        cin>>n;
        m=n;
        c=0;
        while(m)
        {
        r=m%10;
        if(r!=0 && n%r==0)
            c+=1;
        m=m/10;
    }
        cout<<c<<endl;
        
    }
    return 0;
}
