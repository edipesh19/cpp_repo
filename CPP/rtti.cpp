#include <iostream>
#include <typeinfo>
using namespace std;

class base {
	int i;
	public:
	int get_i()
	{
		return i;
	}
	void set_i(int a){
		i = a;
	}
	virtual void fun()
	{
	}
};

class derive:public base {
	int j;
	public:
	int get_j() {
		return j;
	}
	void set_j(int b){
		j = b;
	}
	virtual void fun()
	{
	}
};

int main()
{
	base *bptr = new derive();
	derive *dptr = new derive();
	cout<<"Type :"<<typeid(bptr).name()<<endl;
	cout<<"Type :"<<typeid(dptr).name()<<endl;
	cout<<"Type Content:"<<typeid(*bptr).name()<<endl;
	cout<<"Type Content:"<<typeid(*dptr).name()<<endl;
	return 0;
}
