#include <iostream>

using namespace std;

void show_bit(int val)
{
	for (int i = sizeof(int)*8-1; i >= 0; i--)
	{
		if((val >> i) & 1)
			cout<<"1";
		else
			cout<<"0";
		if (i%4 == 0)
			cout<<" ";
	}
	cout<<"\n";
}

void set_bit(unsigned int& val, int pos, int type)
{
	if (type)
	{
		val = val | (1 << pos);
	}
	else
	{
		val = val & (~(1 << pos));
	}
}

int check_bit(const unsigned int val, int pos)
{
	if ((val >> (pos-1)) & 1)
		return 1;
	else
		return 0;
}

int count_one(const unsigned int val)
{
	int count = 0;
	for (int i = sizeof(int)*8-1; i >=0; i--)
	{
		if ((val >> i) & 1)
			count++;
	}
	return count;
}
bool is_power_of_two(const unsigned int val)
{
	if (val & 1)
		return false;
	return true;
}


int main(int argc, char *argv[])
{
	if (argc != 2) {
		cout<<"Invalid argument"<<endl;
		return -1;
	}

	int a = 10;
	int b = atoi(argv[1]);
	int c;
	c = a >> b;
	cout<<"c = "<<c<<" : ";
	show_bit(c);
	c = a << b;
	cout<<"c = "<<c<<" : ";
	show_bit(c);
	return 0;
}
