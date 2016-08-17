#include <iostream>
#include <algorithm>
#include <string>

#define N 4

using namespace std;


//print all permutation of string
void permute(string s, int l, int r)
{
	if(l==r)
		cout<<s<<endl;
	else
	{
		for(int i=l;i<=r;i++)
	  {
		swap(s[l],s[i]);
		permute(s, l+1, r);
		swap(s[l],s[i]);
	  }
	}
	
}

//Rat in a Maze

bool isSafe(int m[N][N],int x, int y)
{
	if(x>=0 && x<N && y>=0 && y<N && m[x][y]==1)
		return true;
	return false;
}

bool solvemazeUtil(int m[N][N], int sol[N][N], int x, int y)
{
	if(x==N-1 && y==N-1)
	{
		sol[x][y]=1;
		return true;
	}

	if(isSafe(m,x,y))
	{
		sol[x][y]=1;

		if(solvemazeUtil(m,sol,x+1,y))
			return true;
		if(solvemazeUtil(m,sol,x,y+1))
			return true;

		sol[x][y]=0;
		return false;
	}

}

void printsol(int sol[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<sol[i][j]<<" ";
		cout<<endl;
	}
}

bool solvemaze(int m[N][N])
{
	int sol[N][N]={0};
	
	if(!solvemazeUtil(m,sol,0,0))
		{
			cout<<"solution doesn't exist "<<endl;
			return false;
		}

    printsol(sol);
	return true;

}


//N-queen problem

bool isSafe_queen(int sol[N][N], int row, int col)
{
	int i,j;

	//check in the left side of the column
	for(i=0;i<col;i++)
	{
		if(sol[row][i])
			return false;
	}

	//check upper diagonal in left side of the column
	for(i=row,j=col ; i>=0 && j>=0 ; i--,j--)
	{
	    if(sol[i][j])
	       return false; 

	}

	//check lower diagonal in the left side of the column
	for(i=row,j=col ; i<N && j>=0; i++,j--)
	{
		if(sol[i][j])
			return false;
	}
	return true;
}

bool nqueenUtil(int sol[N][N], int col)
{
	if(col>=N)
		return true;

	for(int i=0;i<N;i++)
	{
		if(isSafe_queen(sol,i,col))
		{
			sol[i][col]=1;

			if(nqueenUtil(sol,col+1))
				return true;

			sol[i][col]=0;

		}
	}
	return false;
}

bool nqueen()
{
  int sol[N][N]={0};

  if(!nqueenUtil(sol,0))
  {
  	cout<<"solution doesn't exist "<<endl;
  	return false;
  }

  printsol(sol);
  return true;
}


int main()
{
	//string s="abc";
	//int r=s.length()-1;
	//permute(s,0,r);

    int maze[N][N]  =  { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
 
    //solvemaze(maze);
    
    nqueen();	

	return 0;
}