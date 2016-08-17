#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//vector<int> v;

void compute(int lps[],int m,string pat)
{
    int len=0,i=1;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            lps[i]=++len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
                len=lps[len-1];
        }
    }
}

void match(string pat, string txt, vector<int> &v)
{
    int m=pat.size();
    int n=txt.size();
    int lps[m];
    compute(lps,m,pat);
    int i=0,j=0,count=0;
    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<i-1<<endl;
            v.push_back(i-1);
            j=lps[j-1];
            
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }
    
    /*int count=0,index=0;
    while(1)
    {
        index=find(txt.begin()+index,txt.end(),pat);
        if(index==string::npos)
            return count;
        
            count+=index;
            cout<<index<<endl;
        
    }*/
    //return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n1=s1.size();
    int n2=s2.size();
    if(!n1 || !n2)
        {
            cout<<"0";
            return 0;
        }
    vector<int> v;
    vector<string> prefix;
    int i;
    
    for(i=n1;i>0;--i)
    {
        string s3=string(s1.begin(),s1.begin()+i);
        cout<<s3<<endl;
        prefix.push_back(s3);
    }
    cout<<endl;
    for(i=0;i<prefix.size();++i)
    {
        cout<<prefix[i]<<endl;
        match(prefix[i],s2,v);
        //v.push_back(c);
    }
    cout<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end());
    int count=v[0];
    cout<<v[0]<<" ";
    for(i=1;i<v.size();i++)
    {
        cout<<v[i]<<" ";
        if(v[i]!=v[i-1])
            count+=v[i];
    }
     cout<<count;
    }
    return 0;
}
