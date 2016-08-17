#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    long n1,n2,c;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    cin>>t;
    for(int i=0;i<t;i++)
        {
        cin>>n1>>n2;
        c=0;
        for(long j=n1;j<=n2;j++)
            {
            if((sqrt(j)-(double)(long)sqrt(j))==0)
                c+=1;
        }
        cout<<c<<endl;
    }
    return 0;
}
