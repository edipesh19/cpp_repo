#include <iostream>
#include <iostream>
using namespace std;

class my_exception
{
	string name;
	public:
	my_exception(const char* n):name(n)
	{
	}
	my_exception(const my_exception& o)
	{

	}
	const string what() const
	{
		return name;
	}
		
};

bool is_digit(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

int my_atoi(const std::string& str)
{
	int result = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if (is_digit(str[i]))
		{
			result = result*10 + (str[i]-'0');
		}
		else{
			//my_exception obj("Bad Number formatting");
			//cout<<obj.what()<<endl;
			throw new my_exception("Bad Number formatting");
		}
			//break;
	}
	return result;
}



int main(int argc, char *argv[])
{

	std::string a = argv[1];
	try{
	cout<<my_atoi(a)<<endl;;
	}
	catch(const my_exception *o) {
		cout<<"Exception : "<<o->what()<<endl;
		delete o;
	}
	return 0;
}
