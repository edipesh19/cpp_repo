#include <iostream>
#include<fstream>
#include <string>
#include <deque>
using namespace std;


int main()
{
	ifstream in;
	in.open("Print_last_n_line.cpp", ios::in);
	string str;
	int count = 0;
	deque<string> dq;
	while( !in.eof() )
	{
		getline(in,str);
		dq.push_back(str);
		count++;
		if(count > 10) {
			dq.pop_front();
		}
	}

	for (deque<string>::iterator it = dq.begin(); it != dq.end(); it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}