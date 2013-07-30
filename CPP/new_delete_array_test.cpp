#include <iostream>
using namespace std;

class ABC {
	public:
		ABC()
		{
			cout<<"Constructor\n";
		}
		~ABC()
		{
			cout<<"Destructor\n";
		}
};


int main()
{
	ABC *ob = new ABC[10];
	delete ob;
	return 0;
}
