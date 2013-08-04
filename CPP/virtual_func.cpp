#include <iostream>
using namespace std;

class base
{
protected:
	int i;
public:
	base(int x = 0):i(x){cout<<"Base class constructor"<<endl;}
	virtual void func();
};

void base::func()
{
	cout<<"Base Func i = "<<i<<endl;
}
//When virtual function is not overriden in derive class the vtable of derive class will hold the addess of
//base class virtual function.
class derive1:public base
{
	int j;
public:
	derive1(int y = 0)//:base(y)
	{
		cout<<"Derive1 class constructor"<<endl;
		j = y;
	}

};

class derive2:public base
{
	int j;
public:
	derive2(int y = 0)//:base(y)
	{
		cout<<"Derive2 class constructor"<<endl;
		j = y;
	}
	void func();

};
void derive2::func()
{
	cout<<"Derive2 Func i = "<<i<<" j = "<<j<<endl;
}

int main()
{
	base *bptr1 = new derive1(10);
	base *bptr2 = new derive2(20);

	bptr1->func();
	bptr2->func();

	return 0;

}

/*
output
Base class constructor
Derive1 class constructor
Base class constructor
Derive2 class constructor
Base Func i = 10
Derive2 Func i = 20 j = 20
*/
// When the base constructor call is commented in derive classes
//output will be
/*
Base class constructor
Derive1 class constructor
Base class constructor
Derive2 class constructor
Base Func i = 0
Derive2 Func i = 0 j = 20
*/