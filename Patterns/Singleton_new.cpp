#include <iostream>
using namespace std;

class Singleton {
public:
	static Singleton GetObject()
	{
		static Singleton obj;
		return obj;
	}
	void fun()
	{
		cout<<"Calling fun()"<<endl;
	}
};

int main()
{
	Singleton::GetObject().fun();
	return 0;
}