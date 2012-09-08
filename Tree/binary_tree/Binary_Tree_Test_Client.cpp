#include <iostream>
#include "Binary_Tree.h"
using namespace std;

void display_menu()
{
	cout<<"1. Insert"<<endl;
	cout<<"2. Display in Inorder"<<endl;
	cout<<"3. Display in Preorder"<<endl;
	cout<<"4. Display in Postorder"<<endl;
	cout<<"5. Search"<<endl;
	cout<<"6. Print"<<endl;
	cout<<"7. Exit"<<endl;
	cout<<"Enter your Choice";
}
int main()
{
	int choice, item;
	Binary_Tree t1;
	while(1)
	{
		display_menu();
		cin>>choice;

		switch(choice){
			case 1:
				cout<<"Enter the item to insert : ";
				cin>>item;
				t1.insert(item);
				break;
			case 2:
				t1.display_inorder();
				break;
			case 3:
				t1.display_preorder();
				break;
			case 4:
				t1.display_postorder();
				break;
			case 5:
				int item;
				cout<<"Enter the integer want to search: ";
				cin>>item;
				if(t1.search(item))
				{
					cout<<item<<" : Present in tree"<<endl;
				}
				else
				{
					cout<<item<<" : Not present in tree"<<endl;
				}
				break;
			case 6:
				t1.print_tree();
				break;
			case 7:
				exit(0);
			default:
				cout<<"Invalid Choice"<<endl;
				display_menu();
				break;
		}
	}
	return 0;
}

