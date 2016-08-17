#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "math.h"

using namespace std;



int main()
{
  int a[]={1,2,3};
  double v1=1.0,side;
	int i;
	int l=0,r=1;
	for(i=l;i<=r;i++)
		v1=v1*a[i];
  cout<<v1<<endl;
  
  double len=r-l+1;
  double ilen=1/len;
  cout<<len<<endl;
  cout<<1/len<<" "<<ilen<<endl;
  cout<<pow(v1,ilen)<<endl;
  cout<<pow(2.0,0.5);
   return 0;
}
   
