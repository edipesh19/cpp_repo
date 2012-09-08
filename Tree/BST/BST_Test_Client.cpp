#include <iostream>
#include "BST.h"
using namespace std;

void display_menu()
{
	cout<<"0. Exit"<<endl;
	cout<<"1. Insert with duplicates"<<endl;
	cout<<"2. Insert with no duplicates"<<endl;
	cout<<"3. Display in Inorder"<<endl;
	cout<<"4. Display in Preorder"<<endl;
	cout<<"5. Display in Postorder"<<endl;
	cout<<"6. Search"<<endl;
	cout<<"7. Print"<<endl;
	cout<<"8. BFS Search"<<endl;
	cout<<"Enter your Choice";
}
int main()
{
	int choice, item;
	BST t1;
	bool exitVar = false;
	while(!exitVar)
	{
		display_menu();
		cin>>choice;

		switch(choice){
			case 0:
				exitVar = true;
				break;
			case 1:
				cout<<"Enter the item to insert : ";
				cin>>item;
				t1.insert_with_duplicate(item);
				break;
			case 2:
				cout<<"Enter the item to insert : ";
				cin>>item;
				if ( -2 == t1.insert_with_no_duplicate(item))
				{
					cout<<"Duplicate is not allowed\n";
				}
				break;
			case 3:
				t1.display_inorder();
				break;
			case 4:
				t1.display_preorder();
				break;
			case 5:
				t1.display_postorder();
				break;
			case 6:
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
			case 7:
				t1.print_tree();
				break;
			case 8:
				t1.display_bfs();
				break;
			default:
				cout<<"Invalid Choice"<<endl;
				display_menu();
				break;
		}
	}
	return 0;
}

