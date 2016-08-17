#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int checkprime(int num)
    {

    if(num==2)
       return 0;

    for(int i=2;i<num;i++)
        {
        if(num%i==0)
            return 0;
    }
    return 1;
        
}

int main() {
    int t,n;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>t;
    for(int i=0;i<t;i++)
        {
        cin>>n;
        int a[n]={0};
            for(int j=0;j<n;j++)
                cin>>a[j];
        
        for(int p=0;p<n;p++)
            {
            if(checkprime(a[p])==1)
                {
                cout<<"YES"<<endl;
                return 0;
            }
            
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
