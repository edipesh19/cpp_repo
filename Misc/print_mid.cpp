#include <iostream>

using namespace std;

void print_mid(int *a, int start , int end)
{
	if (start ==  end)
		cout<<a[start]<<"\t";
	else if (start > end)
		return;
	else
	{
		int mid = (start+end)/2;
		cout<<a[mid]<<"\t";
		int left_end = mid-1;
		int right_start = mid+1;
		print_mid(a, start, left_end);
		print_mid(a, right_start, end);
	}
}

int main()
{
	int array[] = {1,2,3,4,5,6,7};
	print_mid(array, 0, 6);
	cout<<endl;
	return 0;
}
