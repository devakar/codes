#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int ROW=100;
const int COL=100;

int isWave_K(int n,int m,string a[],int k, int x1,int y1)
    {
    int c=0;
    if(k==0 && a[x1][y1]=='*')
        return 1;
    
    if(a[x1][y1]=='X')
        return 0;
    
    if((x1>=0 || x1<n) && (y1>=0 || y1<m))
        {
        if(a[x1][y1-1]=='.')
        c++;
       if(a[x1][y1+1]=='.')
        c++;
       if(a[x1-1][y1]=='.')
        c++;
       if(a[x1+1][y1]=='.')
        c++;
        
       if(c>1)
        k--;
        
    return(isWave_K(n,m,a,k,x1,y1-1) || isWave_K(n,m,a,k,x1,y1+1) || isWave_K(n,m,a,k,x1-1,y1) || isWave_K(n,m,a,k,x1+1,y1));
        
    }
    return 0;
    
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
        {
        int n,m,k;
        cin>>n;
        cin>>m;
        cin>>k;
        //char a[ROW][COL]={{'*','.','M'},{'.','X','.'}};
        /*for(int j=0;j<n;j++)
            {
            for(int q=0;q<m;q++)
                {
                cout<<"enter the element a["<<j<<","<<q<<"]"<<endl;   
                cin>>a[j][q];
            }
        }*/

            string a[n];
            for(int j=0;j<n;j++)
            {
                getline(cin, a[j]);
            }
            
        
        int x1,y1,x2,y2;
        for(int p=0;p<n;p++)
            {
            for(int q=0;q<m;q++)
                {
                if(a[p][q]=='M')
                    {
                    x1=p;
                    y1=q;
                }
                   
            }
        }
        
        if(isWave_K(n,m,a,k,x1,y1))
            cout<<"Impressed";
        else 
            cout<<"Oops!";
        
    }
    return 0;
}
