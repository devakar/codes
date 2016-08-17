#include <string>
#include <iostream>
using namespace std;
int main() {
string s1("12345");
// Set the iterator indicate the first element
string::iterator it = s1.begin();
// This may copy the first to the second or
// use reference counting to simulate a copy
string s2 = s1;
// Either way, this statement may ONLY modify first
*it = '0';
cout << "s1 = " << s1 << endl;
cout << "s2 = " << s2 << endl;


string imBlank;
string heyMom("Where are my socks?");
string standardReply = "Beamed into deep "
"space on wide angle dispersion?";
string useThisOneAgain(standardReply);

cout<<heyMom<<endl;
cout<<standardReply<<endl;
cout<<useThisOneAgain<<endl;


string s3("I saw Elvis in a UFO.");
string s6(s3, 6, 10);
cout<<s3<<endl;
cout<<s6<<endl;
cout<<s3.substr(5, 3)<<endl;
}