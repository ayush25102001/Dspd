#include<iostream>
using namespace std;
class X{
	public:
		X() {
			//cout<<"Default constructor of base class!! \n";
		}
		virtual void print() {
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
 
	Y y1;   // Derived class object
	X* ptr; //Base class pointer holding the derived class object
	ptr=&y1;
	ptr->print();
}

// o/p : without virtual function : Base class
        // with  virtual function : Derived class
