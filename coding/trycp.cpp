#include <iostream>

using namespace std;

/*int T;
int main()
{
	cout<<sizeof('a')<<endl;
	struct T { double x; }; 
	cout<<sizeof(T)<<endl;
	return 0;
}*/



class Empty
{};
 
class Derived1 : public Empty
{};
 
class Derived2 : virtual public Empty
{};
 
class Derived3 : public Empty
{    
    char c;
};
 
class Derived4 : virtual public Empty
{
    char c;
};
 
class Dummy
{
    char c;
};
 
int main()
{
    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;    
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
 
    return 0;
}