#include<iostream>
using namespace std;
class X{
	public:
		X() {
			//cout<<"Default constructor of base class!! \n";
		}
		void print() {
			cout<<"Base class \n";
		}
};
class Y:public X{
	public:
		Y() {
			//cout<<"Default constructor of base class!! \n";
		}
		void print() {
			cout<<"Derived class \n";
		}
};

int main() {
	X x1;
	Y y1;
	y1.print();
}
