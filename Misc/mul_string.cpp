#include<iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

string mul(const string& str_up, const string& str_down)
{
	string ret;	
	int length_up = str_up.length();
	int length_down = str_down.length();

	int carry_fwd = 0;
	int down = 0, up = 0, result = 0, first = 0, second = 0;

	queue<int> *q = new queue<int>[length_down];
	stack<int> final;

	for (int i = length_down; i > 0; i--)
	{
		for (int k = length_down-i; k>0; k--)
		{
			q[length_down-i].push(0);
		}
		down = str_down[i-1] - '0';
		for(int j = length_up; j > 0; j--)
		{
			up = str_up[j-1] - '0';
			result = (up * down) + carry_fwd;
			first = result%10;
			carry_fwd = result/10;
			q[length_down-i].push(first);
			if (j == 1) {
				q[length_down-i].push(carry_fwd);
				carry_fwd =0;
			}
		}
	}

	carry_fwd = 0;
	result = 0;
	while(!q[length_down-1].empty())
	{
		result = carry_fwd;
		for (int i = 0; i < length_down ; i++)
		{
			if(!q[i].empty())
			{
				result = result + q[i].front();
				q[i].pop();
			}
		}
		first = result%10;
		final.push(first);
		carry_fwd = result/10;
	}
	// convert stack to string
	char ch;
	while(!final.empty())
	{
		ch = final.top() + '0';
		ret.push_back(ch);
		final.pop();
	}
	delete[] q;
	return ret;
}

int main()
{
	string a;
	string b;

	cout<<"Enter 1st number = ";
	cin>>a;
	cout<<"Enter 2nd number = ";
	cin>>b;

	string result;
	result = mul(a,b);

	cout<<"\t"<<a<<endl;
	cout<<"\t"<<b<<endl;
	cout<<"\tx\n";
	cout<<"---------------------------------------------------------------------\n";
	cout<<"\t"<<result<<endl;
	return 0;
}
