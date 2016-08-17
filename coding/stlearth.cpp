#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    long int t;
    cin>>t;
    while(t--)
    {
        long int n,m;
        cin>>n;
        cin>>m;
        
        set <long long int> mp;
        for(long int i=0;i<n;i++)
        {
            long long int x;
            cin>>x;
            mp.insert(x);
        }
        
        for(long int i=n;i<n+m;i++)
        {
            long long int x;
            cin>>x;
            if(mp.find(x)!=mp.end())
              cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
        
        
        
    }
    return 0;
}