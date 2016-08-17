#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//#define EPSILON 0.000001

typedef long long int LLI;
typedef long double LD;

void solve()
{
	LLI  np,ne,nt;
	cin>>np>>ne>>nt;
	LLI i,j,k,e1,e2,ques;
	LLI p,q;
	LLI ap[np], ae[ne], at[nt];
	bool ans=false;

	for(i=0;i<np;i++)
		cin>>ap[i];

	for(i=0;i<ne;i++)
		cin>>ae[i];

	for(i=0;i<nt;i++)
		cin>>at[i];
    
    cin>>ques;
    for(i=0;i<ques;i++)
    {
    	cin>>p>>q;
    	for(j=0;j<np;j++)
    	{
            for(k=0;k<nt;k++)
            {
                for(e1=0;e1<ne;e1++)
                {
                    for(e2=0;e2<ne;e2++)
                    {
                        if(e1!=e2)
                        {
                            LD res=((LD)ap[j]/at[k])*((LD)ae[e1]/ae[e2]);
                            LD ratio=(LD)p/q;
                                //cout<<res<<" "<<ratio<<endl;
                            if(fabs(res-ratio)< 0.000001)
                                ans=true;
                        }
                    }
                }
            }
        }
            
    	

    	if(ans)
    		cout<<"Yes\n";
    	else
    		cout<<"No\n";
    }
 
}


int main()
{

	freopen("33.in","r",stdin);
	freopen("33.out","w",stdout);
	int T,t=0;
	cin>>T;

	while(T--)
	{
		t++;
		cout<<"Case #"<<t<<":\n";
		solve();
	}
}