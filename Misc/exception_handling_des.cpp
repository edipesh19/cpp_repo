#include <iostream>

using namespace std;

class abc {
	public:
		abc() {
			//try {
			cout<<"Construction\n";
			//throw 2;
		}
		~abc(){
			try {
				cout<<"Decstructor\n";
				throw 2;
				cout<<"Last line of Decstructor\n";
			}
			catch (int a)
			{
				cout<<"desc catch\n";
			}
		}
		abc(const abc& obj) {
			cout<<"Copy Constructor\n";
		}
};



void fun()
{
	try{
		abc obj;
		abc obj1;
		cout<<"Throwing\n";
		throw 2;
	}catch(abc& obj)
	{
		cout<<"Exception Caught\n";
	}
	catch(int a){
		cout<<"Default catch\n";
	}
}

int main()
{
	fun();
	return 0;
}
