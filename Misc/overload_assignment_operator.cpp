#include <iostream>
using namespace std;

class Base {
	public:
		Base(int initialValue = 0): x(initialValue) {}
		int get_x()
		{
			return x;
		}
	private:
		int x;
};

class Derived: public Base {
	public:
		Derived(int initialValue)
			: Base(initialValue), y(initialValue) {}
		Derived& operator=(const Derived& rhs);
		int get_y()
		{
			return y;
		}
	private:
		int y;
};


Derived& Derived::operator=(const Derived& rhs)
{
	if (this == &rhs) return *this; // see Item 17
	//static_cast<Base&>(*this) = rhs;
	Base::operator=(rhs);
	y = rhs.y; // assign to Derived's
	return *this; // see Item 15
}

int main()
{
	Derived d1(0); // d1.x = 0, d1.y = 0

	cout<<"d1.x = "<<d1.get_x()<<endl;
	Derived d2(1);
	cout<<"d2.x = "<<d2.get_x()<<endl;
	cout<<"d2.y = "<<d2.get_y()<<endl;
	d1 = d2;
	cout<<"d1.x = "<<d1.get_x()<<endl;
	return 0;
}
