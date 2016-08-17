#include <iostream>
#include <string>
#include "stdlib.h" 

using namespace std;

int main()
{
	int N,M;
	//int num=0*0000;
   cin>>N;
   cin>>M;
   char s[N][M];
   int a[N];
   cout<<"enter the elements"<<endl;
   for(int i=0;i<N;i++)
   {
   	for(int j=0;j<M;j++)
   		cin>>s[i][j];
   }
      
   
   cout<<"elements are"<<endl;
   for(int i=0;i<N;i++)
   {
   	for(int j=0;j<M;j++)
   		cout<<s[i][j];
   	    cout<<endl;
   }
   	
cout<<"mtrix"<<endl;

  // 	for(int i=0;i<2;i++)
   //{
   	
   	//	a[i]=atoi(&s);
        // cout<<a[i]<<endl;
   //}
   		
   		
   //	for(int i=0;i<N;i++)
   //{
   	
   	//	cout<<a[i];
   		//cout<<endl;
   //}
   	//cout<<a;
  

   

   
   	cout<<atoi(&s[0][0]);
   	cout<<endl;
  

   
    //cout<<"sum"<<num<<endl;
	return 0;
}