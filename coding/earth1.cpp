#include <iostream>
//#define ROW 1000
using namespace std;



int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;++i)
    	cin>>a[i];
    	
    	int sum[n][n], mark[n][n];
    	
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		  mark[i][j]=0;
    	}
    	
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
                if(a[i]!=a[j])
    		        sum[i][j]=a[i]+a[j];
                else 
                    sum[i][j]=0;
    	}


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              cout<<sum[i][j]<<" ";
            cout<<endl;
        }
    	
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		 {
    		 	if(sum[i][j]%2==0 && sum[i][j]!=0)
    		 	{
    		 		if(i==j )
    		 		  mark[i][j]=0;
    		 		else
    		 		{
    		 			if(mark[j][i]==1)
    		 			   mark[i][j]=0;
    		 			   
    		 			else
    		 			   mark[i][j]=1;
    		 		}
    		 	}
    		 }
    	}

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
              cout<<mark[i][j]<<" ";
            cout<<endl;
        }
    	
    	int total=0;
    	
    	for(int i=0;i<n;i++)
    	{
    		for(int j=0;j<n;j++)
    		    total+=mark[i][j];
    	}
    	
    	cout<<total<<endl;
    	
    }
    return 0;
}
