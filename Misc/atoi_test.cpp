#include <iostream>
#include <string>
using namespace std;


int main()
{
	int x;
	string str("12345");
	for (int i = 0; i < str.length(); i++) {
		x = str[i] - '0';
		cout<<"X = "<<x<<endl;
	}
	return 0;
}
