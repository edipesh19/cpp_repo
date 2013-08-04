#include <iostream>

using namespace std;

class Test
{
public:
	Test()
	{
		cout<<"Test Constructor"<<endl;
	}
	~Test()
	{
		cout<<"Test Destructor"<<endl;
	}
	Test(const Test& t)
	{
		cout<<"Test Copy Constructor"<<endl;
	}
	// This is more optimized way because no copy constructor is called.
	Test fun1()
	{
		return Test();
	}
	// Not optimized way because copy constructor is called.
	Test fun2()
	{
		Test tmp;
		return tmp;
	}
};

int main()
{
	Test t;
	cout<<"===== DONE T =============="<<endl;
	t.fun1();
	cout<<"===== DONE T.fun1() =============="<<endl;
	t.fun2();
	cout<<"===== DONE T.fun2() =============="<<endl;
	return 0;
}

/*
Output
Test Constructor
===== DONE T ==============
Test Constructor
Test Destructor
===== DONE T.fun1() ==============
Test Constructor
Test Copy Constructor
Test Destructor
Test Destructor
===== DONE T.fun2() ==============
Test Destructor
*/