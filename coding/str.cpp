
#include "stdlib.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s1="Hello",s2 ,s3,s5 ,s6="e",s7="ae",s8;

	string s9="10010";

	char *n="10001";
	char m[]="100101";


	int a,b,c,d;

	double db=10001;
	
	s2=s1;
	s3.assign(s1);
	string s4 (s1);

	

	cout<<"S1 : "<<s1<<endl;
	cout<<"S2 : "<<s2<<endl;
	cout<<"S3 : "<<s3<<endl;
	cout<<"S4 : "<<s4<<endl;

    cout<<"S1 at 2nd position :"<<s1.at(1)<<endl;
    cout<<"S2 at 2nd position :"<<s2[1]<<endl;


    s5=s1 + " World";

    cout<<"S5 : "<<s5<<endl;

    s2.append("!!!!");

    cout<<"S2 : "<<s2<<endl;

    s3.append(s5, 5, s5.size());

    cout<<"S3 : "<<s3<<endl;

    s4[4]=' ';

    cout<<"S4 : "<<s4<<endl;

    s4[4]='o';
    cout<<"S4 : "<<s4<<endl;

    cout<<"value of comparision between s1 and s4 :"<<s1.compare(s4)<<endl;
    cout<<"value of comparision between s1 and s2 :"<<s1.compare(s2)<<endl;
    cout<<"value of comparision between s2 and s1 :"<<s2.compare(s1)<<endl;
    cout<<"value of comparision between s1 and s5 :"<<s1.compare(0,s1.size(),s5,0,5)<<endl;
    cout<<"value of comparision between s6 and s7 :"<<s6.compare(s7)<<endl;

    s8=s5.substr(6,s5.size()-6);
    cout<<"S8 : "<<s8<<endl;

    s4.swap(s2);
    cout<<"S4 : "<<s4<<endl;
    
    b=atoi("100101");
    cout<<b<<endl;
    c=atoi(n);
    cout<<c<<endl;
    a=atoi(m);
    cout<<a<<endl;

    cout<<(int)db<<endl;

}