#include <iostream>

using namespace std;

class base
{
	public:
		virtual void fun() = 0;
};
// definition of pure virtual function -- NO Error
void base::fun()
{
	cout<<"Base\n";
}

class der1:public base
{
	void fun2()
	{
		cout<<"fun2"<<endl;
	}
	public:
		void fun()
		{
			cout<<"Der1\n";
			fun2();
		}
};
class der2:public der1
{
};

int main()
{
	base *bptr = new der2();
	bptr->fun();
	//This is the way to call
	bptr->base::fun();
	return 0;
}
