#include <iostream>
using namespace std;

class base {
	base();
	public:
	static base* create()
	{
		return new base();
	}
};

class der : public base
{
};

int main()
{
	der d;
	return 0;
}
