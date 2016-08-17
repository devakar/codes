#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include "stdio.h"

#define R 6
#define C 5
#define V 4
#define INF INT_MAX

using namespace std;

//Longest Increasing Subsequence
int lis(vector<int > &v)
{
	int l= v.size();
	vector <int > v2(l,1);
	

	for(int i=1;i<l;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(v[i]>v[j] && v2[i]<v2[j]+1)
				v2[i]=v2[j]+1;
		}
	}
	return *max_element(v2.begin(),v2.end());

}


//Longest Common Subsequence
int lcs(string s1,string s2)
{
	int l1=s1.size();
	int l2=s2.size();

	vector < vector <int> > v;
	v.resize(l1+1);
	for(int i=0;i<=l1;i++)
		v[i].resize(l2+1);

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0 || j==0)
				v[i][j]=0;

			else if(s1[i-1]==s2[j-1])
				v[i][j]=v[i-1][j-1]+1;

			else
				v[i][j]=max(v[i-1][j], v[i][j-1]);
		}
	}

	return v[l1][l2];

}


//Edit Distance
int editDistance(string s1,string s2)
{
	int l1=s1.size();
	int l2=s2.size();

	int left,top,corner;

	vector <vector <int> >v(l1+1, vector<int> (l2+1, -1));

	

	for(int i=0;i<=l1;i++)
		v[i][0]=i;

	for(int j=0;j<=l2;j++)
		v[0][j]=j;


	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			left=v[i][j-1];
			left+=1;

			top=v[i-1][j];
			top+=1;

			corner=v[i-1][j-1];
			corner+=(s1[i-1]!=s2[j-1]);

			v[i][j]=min(left,top);
			v[i][j]=min(v[i][j],corner);
		}
	}
	
	return v[l1][l2];
	//v.erase();

}


//Min Cost Path
int minCost(int c[R][C],int m,int n)
{
	int tc[R][C];

	tc[0][0]=c[0][0];

	for(int i=1;i<R;i++)
		tc[i][0]=tc[i-1][0]+c[i][0];

	for(int j=1;j<C;j++)
		tc[0][j]=tc[0][j-1]+c[0][j];

	for(int i=1;i<R;i++)
	{
		for(int j=1;j<C;j++)
		{
			tc[i][j]=min(tc[i][j-1],tc[i-1][j]);
			tc[i][j]=min(tc[i][j],tc[i-1][j-1]) + c[i][j];
		}
	}

	return tc[m][n];
}


//Coin Change
int coinChange(int s[],int l,int sum)
{
	int table[sum+1][l];

	for(int i=0;i<l;i++)
		table[0][i]=1;

	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<l;j++)
		{
			int x,y;

			x = (i-s[j])>=0 ? table[i-s[j]][j] : 0;
			y = (j>=1) ? table[i][j-1] : 0;

			table[i][j]=x+y; 
		}
	}

	return table[sum][l-1];
}


//matrix chain multiplication
int matrixChain(int p[], int n)
{
	int m[n][n];

	for(int i=1;i<n;i++)
		m[i][i]=0;

	int q,j;

	for(int l=2; l<n; l++)
	{
		for(int i=1; i<=n-l; i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(int k=i; k<j; k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];

				if(q< m[i][j])
					m[i][j]=q;
			}
		}
	}
	return m[1][n-1];


}

//binomial coefficient in O(n*k) time and O(n*K) space
int binomCoeff(int n, int k)
{
	int c[n+1][k+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0; j<=min(i,k); j++)
		{
			if(j==0 || i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}

	return c[n][k];
}

// binomial coeffiecient in O(n*k) time and O(k) space
int binomCoeff2(int n, int k)
{
	int c[k+1]={0};
	c[0]=1;

	for(int i=0;i<=n;i++)
	{
		for(int j=min(i,k); j>0;j--)
			c[j]=c[j]+c[j-1];
	}
	return c[k];
}

//knapsack 0-1
int knapsack01(int v[], int w[], int wt, int n)
{
	int t[n+1][wt+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=wt;j++)
		{
			if(i==0 || j==0)
				t[i][j]=0;

			else if(w[i-1]<=wt)
				t[i][j]=max(v[i-1]+t[i-1][j-w[i-1]], t[i-1][j]);
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][wt];
}

//Egg Dropping Puzzle
int eggDrops(int n, int k)
{
	int ef[n+1][k+1];

	for(int i=1;i<=n;i++)
	{
		ef[i][0]=0;
		ef[i][1]=1;
	}

	for(int i=1;i<=k;i++)
		ef[1][i]=i;

	int res;

	for(int i=2; i<=n; i++)
	{
		for(int j=2; j<=k; j++)
		{
			ef[i][j]=INT_MAX;
			for(int x=1; x<=j; x++)
			{
				res=1+ max(ef[i-1][x-1], ef[i][j-x]);
				if(res<ef[i][j])
					ef[i][j]=res;
			}

		}
	}
	return ef[n][k];
}

//Cut rod
int cutrod(int p[], int n)
{
	int val[n+1];
	val[0]=0;
	

	for(int i=1;i<=n;i++)
	{
		int maxv=INT_MIN;
		for(int j=0;j<i;j++)
		{
			maxv=max(maxv, p[j]+cutrod(p,i-j-1));

		}
		val[i]=maxv;
	}
	return val[n];
}

//Longest Palindromic Subsequence (filling the table is similat=r to matrix chain multiplication)
int lps(string s)
{
	int n=s.length();
	int m[n][n],j;

	for(int i=0; i<n; i++)
		m[i][i]=1;

	for(int l=2; l<=n;l++)
	{
		for(int i=0; i<n-l+1;i++)
		{
			j=i+l-1;

			if(s[i]==s[j] && l==2)
				m[i][j]=2;
			else if(s[i]==s[j])
				m[i][j]=m[i+1][j-1]+2;
			else
				m[i][j]=max(m[i+1][j], m[i][j-1]);
		}
	}

	return m[0][n-1];
}


//Maximum Sum Increasing Subsequence
int maxSumInSub(int a[], int n)
{
	int ms[n];
	for(int i=0;i<n;i++)
		ms[i]=a[i];

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if( (a[i] > a[j]) && (ms[i] < ms[j] + a[i]) )
				ms[i]=ms[j]+a[i];
		}
	}

	return *max_element(ms,ms+n);
}

//Longest Bitonic Subsequence
int lBitonicSub(int a[], int n)
{
	int lis[n];
	int lds[n];
	int lbs[n];

	int i,j;
	
	for(i=0;i<n;++i)
	{
		lis[i]=1;
		lds[i]=1;
	}

	for(i=1;i<n;++i)
	{
		for(j=0;j<i;++j)
		{
			if(a[i]>a[j] && lis[i]<lis[j]+1)
				lis[i]=lis[j]+1;
		}
	}

	for(i=1;i<n;++i)
	{
		for(j=0;j<i;++j)
		{
			if(a[i]<a[j] && lds[i]<lds[j]+1)
				lds[i]=lds[j]+1;
		}
	}
    
    for(i=0;i<n;++i)
    	lbs[i]=lis[i]+lds[i]-1;

	return *max_element(lbs,lbs+n);
}

//Floyd Warshall Algorithm
void floyd_warshall(int g[V][V])
{
	int sd[V][V];
	int i,j,k;

	for(i=0;i<V;++i)
	{
		for(j=0;j<V;++j)
			sd[i][j]=g[i][j];
	}

	for(k=0;k<V;++k)
	{
		for(i=0;i<V;++i)
		{
			for(j=0;j<V;++j)
			{
				if( sd[i][k]!=INF && sd[k][j]!=INF && (sd[i][k] + sd[k][j]) < sd[i][j] )
					sd[i][j]=sd[i][k]+sd[k][j];
			}
		}
	}

	for(i=0;i<V;++i)
	{
		for(j=0;j<V;++j)
		{
			if(sd[i][j]==INF)
				cout<<"INF"<<" ";
			else
				cout<<sd[i][j]<<" ";
		}
			

		cout<<endl;
	}
}

//Palindrome Partitioning in O(n^3) time
int palindromePartition(string s)
{
	int n=s.length();

	int c[n][n];
	bool p[n][n];

	int i,j,k,l;

	for(i=0;i<n;++i)
	{
		c[i][i]=0;
		p[i][i]=true;
	}

	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;++i)
		{
			j=i+l-1;

			if(l==2)
				p[i][j]=(s[i]==s[j]);
			else
				p[i][j]=( (s[i]==s[j]) && p[i+1][j-1] );

			if(p[i][j])
				c[i][j]=0;
			else
			{
				c[i][j]=INT_MAX;
				for(k=i;k<j;k++)
				{
					c[i][j]=min(c[i][j], c[i][k]+c[k+1][j]+1);
				}
			}
		}
	}
	return c[0][n-1];
}

//Palindrome Partitioning in O(n^2) time
int palindromePartition2(string s)
{
	int n=s.length();

	int c[n];
	bool p[n][n];

	int i,j,k,l;

	for(i=0;i<n;++i)
		p[i][i]=true;

	for(l=2;l<=n;++l)
	{
		for(i=0;i<n-l+1;++i)
		{
			j=i+l-1;
			if(l==2)
			else
				p[i][j]=( (s[i]==s[j]) && p[i+1][j-1] );
		}
	}

	for(i=0;i<n;++i)
	{
		if(p[0][i])
			c[i]=0;
		else
		{
			c[i]=INT_MAX;
			for(j=0;j<i;++j)
			{
				if(p[j+1][i] && (c[i] > c[j]+1))
					c[i]=c[j]+1;
			}
		}
	}

	return c[n-1];
}

//Partition problem is to determine whether a given set can be partitioned into two subsets such that the sum of elements in both subsets is same. 
bool isPartitionSum_same(int a[], int n)
{
	int sum=0,i,j;
	for(i=0;i<n;i++)
		sum+=a[i];

	if(sum%2 != 0)
		return false;

	bool t[sum/2+1][n+1];

	for(i=0;i<=n;i++)
		t[0][i]=true;

	for(i=1;i<=sum/2;i++)
		t[i][0]=false;

	for(i=1;i<=sum/2;i++)
	{
		for(j=1;j<=n;j++)
		{
			t[i][j]=t[i][j-1];
			if(i>=a[j-1])
				t[i][j]=t[i][j] || t[i-a[j-1]][j-1];
		}
	}
	return t[sum/2][n];

}


//Word Wrap Problem
/*void wordWrap(int l[], int n, int m)
{
	int extra[n+1][n+1];
	int ls[n+1][n+1];
	int c[n+1];
	int p[n+1];

	int i,j;

	for(i=1;i<=n;++i)
	{
		extra[i][i]=
	}
}*/


//Maximum Length Chain of Pairs
int maxChainPair(multimap <int, int> m, int n)
{
	int i,j;
	int mcp[n];
	for(i=0;i<n;i++)
		mcp[i]=1;

	multimap <int, int> :: iterator it1,it2;

	it1=m.begin();
	it1++;

	for(it1, i=1;it1!=m.end() && i<n ;it1++, i++)
	{
		for(it2=m.begin(), j=0;it2!=it1 && j<i ;it2++, j++)
		{
			if( ( (it1->first) > (it2->second) ) && ( mcp[i] < mcp[j]+1 ) )
				mcp[i] = mcp[j]+1;
		}
	}
    
    return *max_element(mcp,mcp+n);

}

//fibonacci number in O(log n) time

void multiply(int F[2][2], int M[2][2])
{
	int p= F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int q= F[0][0]*M[0][1] + F[0][1]*M[1][1];
	int r= F[1][0]*M[0][0] + F[1][1]*M[1][0];
	int s= F[1][0]*M[0][1] + F[1][1]*M[1][1];

	F[0][0]=p;
	F[0][1]=q;
	F[1][0]=r;
	F[1][1]=s;
}

void power(int F[2][2], int n)
{
  if(n==0 || n==1)
  	return;

  int M[2][2]={{1,1}, {1,0}};

  power(F, n/2);
  multiply(F,F);

  if(n%2!=0)
  	multiply(F,M);
}

int fib(int n)
{
	int F[2][2]= {{1,1}, {1,0}};

	if(n==0)
		return 0;

	power(F, n-1);
	return F[0][0];
}


//minimum-number-of-jumps-to-reach-end-of-a-given-array
int minJumps(int a[], int n)
{
    if(n==0 || a[0]==0)
    	return INT_MAX;

	int jump[n];
	jump[0]=0;

	for(int i=1; i<n;++i)
	{
		jump[i]=INT_MAX;
		for(int j=0;j<i;++j)
		{
			if(i<=j+a[j] && jump[j]!=INT_MAX)
			{
				jump[i]=min(jump[i], jump[j]+1);
				break;
			}
		}
	}
	return jump[n-1];
}

//maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix
int minimum(int a, int b, int c)
{
	if(a <= b)
    {
      if(a <= c)
        return a;
      else
        return c;
    }
    if(b <= c)
      return b;
    else
      return c;
}

void maxSubmatrix(int m[R][C])
{
	int s[R][C];
	int i,j;

	for(i=0;i<R;++i)
		s[i][0]=m[i][0];

	for(j=0;j<C;++j)
		s[0][j]=m[0][j];

	for(i=1;i<R;++i)
	{
		for(j=1;j<C;++j)
		{
			if(m[i][j]==1)
			   s[i][j]=minimum(s[i-1][j], s[i][j-1], s[i-1][j-1]) +1;
			else
				s[i][j]=0;
		}
	}

    int max=0, maxi,maxj;
	for(i=0;i<R;++i)
	{
		for(j=0;j<C;++j)
		{
            if(s[i][j] > max)
            {
            	max=s[i][j];
            	maxi=i;
            	maxj=j;
            }
		}
	}
    cout<<maxi<<" "<<maxj<<endl;
    cout<<"The size of submatrix with all zero is "<<(R-maxi+1)<<"*"<<(C-maxj+1);
}

//ugly number
int ugly(int n)
{
	int u[n];
	u[0]=1;

	int u2=2, u3=3, u5=5, i2=0, i3=0, i5=0, next=1,i;

	for(i=1;i<n;++i)
	{
		next=minimum(u2,u3,u5);
		u[i]=next;
        
		if(next==u2)
		{
			i2+=1;
			u2=u[i2]*2;
		}

		if(next==u3)
		{
			i3+=1;
			u3=u[i3]*3;
		}

		if(next==u5)
		{
			i5+=1;
			u5=u[i5]*5;
		}

	}

   return next;
}

//largest-sum-contiguous-subarray
int sumlargeConti(int a[], int n)
{
	int curmax=a[0], maxsofar=a[0], i;

	for(i=1;i<n;i++)
	{
		curmax=max(a[i], curmax+a[i]);
		maxsofar=max(curmax, maxsofar);
	}
	return maxsofar;
}

//longest-palindrome-substring

void printstring(string s, int low, int high)
{
	for(int i=low;i<=high;i++)
		cout<<s[i];
	cout<<endl;
}

int longestPalinSubstring(string s)
{
	int l=s.length();
	bool table[l][l];
	//memset(table,0,sizeof(table));
    int maxlength=1,i,start,len,j;

    for(i=0;i<l;i++)
    	for(j=0;j<l;j++)
    		table[i][j]=false;

    for(i=0;i<l;i++)
    	table[i][i]=true;

    for(i=0;i<l-1;i++)
    {
    	if(s[i]==s[i+1])
    	{
    		table[i][i+1]=true;
    		start=i;
            maxlength=2;
    	}
    }

    for(len=3;len<=l;len++)
    {
    	for(i=0;i<l-len+1;i++)
    	{
    		j=i+len-1;
    		if(table[i+1][j-1] && s[i]==s[j])
    		{
    			table[i][j]=true;

    			if(len>maxlength)
    			{
    				start=i;
    				maxlength=len;
    			}
    		}
    	}
    }

    printstring(s,start,start+maxlength-1);
    return maxlength;

}

//optimal binary search tree

int sumElement(int a[], int low, int high)
{
	int sum=0;
	for(int i=low;i<=high;i++)
		sum+=a[i];
	return sum;
}

int optimalBST(int a[], int f[], int n)
{
	int cost[n][n],i,l,j,r,c;

	for(i=0;i<n;i++)
		cost[i][i]=f[i];

	for(l=2;l<=n;l++)
	{
		for(i=0;i<n-l+1;i++)
		{
			j=i+l-1;
			cost[i][j]=INT_MAX;
			for(r=i;r<=j;r++)
			{
				c=(r>i ? cost[i][r-1] : 0) + (r<j ? cost[r+1][j] : 0) + sumElement(f,i,j);
				if(c<cost[i][j])
					cost[i][j]=c;
			}
		}
	}
	return cost[0][n-1];
}

//subset sum
bool subsetSum(int  set[], int n, int sum)
{
	bool table[sum+1][n+1];
	int i,j;

	for(i=0;i<=n;i++)
		table[0][i]=true;

	for(i=1;i<=sum;i++)
		table[i][0]=false;

	for(i=1;i<=sum;i++)
	{
		for(j=0;j<=n;j++)
		{
			table[i][j]=table[i][j-1];

			if(i>=set[j-1])
			{
				table[i][j]=table[i][j] || table[i-set[j-1]][j-1];
			}
		}
	}
	return table[sum][n];
}

//count-number-binary-strings-without-consecutive-1s
int countStrings(int n)
{
	int a[n],b[n];
	a[0]=1;
	b[0]=1;

	for(int i=0;i<n;i++)
	{
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	return a[n-1]+b[n-1];
}

//boolean-parenthesization-problem
int countParenthesis(string s, string op)
{
	int n=s.length();
	int t[n][n], f[n][n], i, j, gap, g, k, tik, tkj;

	for(i=0;i<n;i++)
	{
		t[i][i]=(s[i]=='T') ? 1 : 0;
		f[i][i]=(s[i]=='F') ? 1 : 0;
	}

	for(gap=2;gap<=n;gap++)
	{
		for(i=0;i<n-gap+1;i++)
		{
			j=i+gap-1;
			t[i][j]=0;
			f[i][j]=0;
			for(k=i;k<j;k++)
			{
				tik=t[i][k]+f[i][k];
				tkj=t[k+1][j]+f[k+1][j];


				if(op[k]=='&')
				{
					t[i][j]+=(t[i][k]*t[k+1][j]);
					f[i][j]+=(tik*tkj-t[i][k]*t[k+1][j]);
				}

				if(op[k]=='|')
				{
					f[i][j]+=(f[i][k]*f[k+1][j]);
					t[i][j]+=(tik*tkj-f[i][k]*f[k+1][j]);

				}

				if(op[k]='^')
				{
					t[i][j]+=(f[i][k]*t[k+1][j] + t[i][k]*f[k+1][j]);
					f[i][j]+=(t[i][k]*t[k+1][j] + f[i][k]*f[k+1][j]);
				}

			}

		}
		
	}
	return t[0][n-1];
}

int main()
{
	/*int n,num;
	cout<<"How many elements do you want to process"<<endl;
	cin>>n;
	cout<<"Enter the elements "<<endl;
	vector <int> v(n);

	string s1="AGGTAB";
	string s2="GXTXAYB";


	for(int i=0;i<n;i++)
	    cin>>v[i];
	<<"The longest increasing subsequence is "<<lis(v)<<endl;

	
	cout<<"The length of longest common subsequence is "<<lcs(s1,s2)<<endl;
    */
    
    //string s1="SUNDAY", s2="SATURDAY";
    //cout<<"Minimum edits required to convert "<<s1<<" into "<<s2<<" is "<<editDistance(s1,s2);
    
    /*int cost[R][C] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };

    cout<<" minmim cost to reach (2,2) is "<<minCost(cost,2,2)<<endl;*/

    //int a[] = {1,2,3,4};
    //int l = sizeof(a)/sizeof(a[0]);
    //int sum = 4;
    //cout<<"The number of ways are "<<coinChange(a,l,sum);

    //cout<<"Min no. of operation is "<<matrixChain(a,l);

    //cout<<binomCoeff(4,2)<<endl;
    //cout<<binomCoeff2(4,2)<<endl;

    /*int v[] = {60, 100, 120};
    int w[] = {10, 20, 30};
    int  wt = 50;
    int n = sizeof(v)/sizeof(v[0]);

    cout<<knapsack01(v,w,wt,n)<<endl;*/

    //cout<<eggDrops(2,100)<<endl;

    //string s= "GEEKS FOR GEEKS";
    //cout<<lps(s)<<endl;

    //int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
    //int size = sizeof(arr)/sizeof(arr[0]);
    //cout<<cutrod(arr,size);
    //cout<<maxSumInSub(arr,size);
    //cout<<lBitonicSub(arr,size);

    /*int g[V][V] = { {0,   5,  INF, 10},
                    {INF, 0,   3, INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0}
                   };
 
    floyd_warshall(g);*/

    //string s="ababbbabbababa";
    //cout<<palindromePartition(s)<<endl;
    //cout<<palindromePartition2(s);

    /*int arr[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<isPartitionSum_same(arr,n);*/

    /*int n,i,x,y;
    cout<<"enter the number of pairs :"<<endl;
    cin>>n;
    multimap <int, int> m;
    for(i=0;i<n;++i)
    {
    	cin>>x>>y;
    	m.insert(make_pair(x,y));

    }
    cout<<maxChainPair( m, n);*/

   // cout<<fib(6);
   /*int a[]={1, 3, 6, 1, 0, 3};
   int n=sizeof(a)/sizeof(a[0]);
   cout<<minJumps(a,n);*/

   /*int a[R][C]={ {0, 1, 1, 0, 1},
                 {1, 1, 0, 1, 0},
                 {0, 1, 1, 1, 0},
                 {1, 1, 1, 1, 0},
                 {1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 0}

                };
    maxSubmatrix(a);*/

    //cout<<ugly(11);

   /*int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   cout<<sumlargeConti(a,n);*/

   //string s= "forgeeksskeegfor";
   //cout<<longestPalinSubstring(s);
    
   /*int keys[] = {10, 12, 20};
   int freq[] = {34, 8, 50};
   int n = sizeof(keys)/sizeof(keys[0]);
   cout<<optimalBST(keys,freq,n);*/

   /*int set[] = {3, 34, 4, 12, 5, 2};
   int sum = 9;
   int n = sizeof(set)/sizeof(set[0]);
   cout<<subsetSum(set,n,sum);*/

   //cout<<countStrings(3);

    string s = "TTFT";
    string op = "|&^";
    cout<<countParenthesis(s,op);
    return 0;
}



