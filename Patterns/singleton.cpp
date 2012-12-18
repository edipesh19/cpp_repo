#include <iostream>
using namespace std;

class singleton{
	static singleton *ptr;
	static int count;
	singleton()//:count(1)
	{
		count++;
	}
	public:
	static singleton* create_object()
	{
		if (0 == count)
		{
			ptr = new singleton();
		}
		return ptr;
	}

	void no_of_object()
	{
		cout<<"count = "<<count<<endl;
	}
};

int singleton::count = 0;
singleton* singleton::ptr = NULL;

class derived : public singleton
{
	public:
		derived(){}
};

int main()
{
	singleton* ptr1 = singleton::create_object();
	ptr1->no_of_object();
	singleton* ptr2 = singleton::create_object();
	ptr2->no_of_object();
	singleton* ptr3 = singleton::create_object();
	ptr3->no_of_object();
	derived d;
	return 0;
}
