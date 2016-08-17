#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
 {
       int i,j,n=nums.size(),p=0,q=n-1,start,end;
       bool bstart=false;
       vector<int> num2=nums;
       sort(num2.begin(),num2.end());
       while(p<q)
       {
           if(num2[p]+num2[q]==target)
              break;
           else if(num2[p]+num2[q]<target)
              p++;
           else
             q--;
       }
       
       for(i=0;i<n;i++)
       {
           if(num2[p]==nums[i] && !bstart)
           {
               start=i;
               bstart=true;
           }
                 
           if(num2[q]==nums[i] )
             end=i;
       }
       cout<<start+1<<" "<<end+1<<endl;
       vector<int> v;
       v.push_back(start+1);
       v.push_back(end+1);
       return v;
  }


int main()
{
  vector<int> v;
  v.push_back(0);
  v.push_back(3);
  v.push_back(2);
  v.push_back(0);
  vector<int> a=twoSum(v,0);
  cout<<a[0]<<" "<<a[1]<<endl;
}  