#include <iostream>
using namespace std;

void swap (char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char *a, int i, int n) 
{
	int j; 
	if (i == n)
		cout<<a<<endl;
	else
	{
		for (j = i; j <= n; j++)
		{
			swap((a+i), (a+j));
			permute(a, i+1, n);
			swap((a+i), (a+j)); //backtrack
		}
	}
} 

/* Driver program to test above functions */
int main()
{
	char a[] = "ABC";  
	permute(a, 0, 2);
	//getchar();
	return 0;
}
