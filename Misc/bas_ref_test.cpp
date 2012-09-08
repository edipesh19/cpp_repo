#include <iostream>
using namespace std;

class Base {
	public:
		Base(){}
		Base(const Base & b)
		{
			cout<<"Base\n";
		}
};

class Derive:public Base{
};


int main()
{
	const Base &b = const_cast<Derive&>(Derive());
	return 0;
}
