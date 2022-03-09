#include<iostream>
using namespace std;
class X{
	public:
		X(X& x) {
			cout<<"copy constructor called!! \n";
		}
		X() {
			cout<<"Default constructor called!! \n";
		}
};


// x=x1 (copy constructor called)
void func(X x) {
	int a=0;
}

int main() {
	X x1;
	func(x1);
}
