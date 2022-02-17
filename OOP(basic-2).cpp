// THIS WORKS FINE BOTH check AND setK would be invoked wrt object c

#include<iostream>
using namespace std;
class check
{
	public:
		int k;
		void setK(int x) {
			k=x;
		}
		check(int x) {
			setK(x);
		}
};
int main()
{
	check c(10);
	cout<<c.k<<endl;
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Object c passed by reference


#include<iostream>
using namespace std;
class check
{
	public:
		int k;
		void setK(int x) {
			k=x;
		}
		check(int x,check& ayush) {
			//x++;
			ayush.setK(x);
		}
};
int main()
{
	check c(10,c);
	cout<<c.k<<endl;
	return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Object c passed by reference

#include<iostream>
using namespace std;
class check
{
	public:
		int k;
		void setK(int x) {
			k=x;
		}
		check(int x,check ayush) {
			//x++;
			ayush.setK(x);
		}
};
int main()
{
	check c(10,c);
	cout<<c.k<<endl;
	return 0;
}

//ayush.k would be 10 but since ayush is just the copy of c c.k would not be 10 it would be 0

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
