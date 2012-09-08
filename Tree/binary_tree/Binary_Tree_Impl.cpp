#include <iostream>
#include "Binary_Tree.h"

using namespace std;

int Binary_Tree::validate_input_and_toupper(string& str)
{
	string::iterator i = str.begin();
	string::iterator end = str.end();
	while(i != end) {
		if (*i == 'L' || *i == 'l' || *i == 'R' || *i == 'r')
		{
			*i = toupper((unsigned char)*i);
		}
		else 
		{
			return -1;
		}
		i++;
	}
	return 0;
}

void Binary_Tree::print(node* h, int i)
{
	int j;
	cout<<"\n";
	if (h != NULL)
	{
		print(h->right,i+1);
		for(j=1;j<=i;j++)
		{
			cout<<"\t";
		}
		cout<<h->data;
		print(h->left,i+1);
	}
}

void Binary_Tree::display_inorder(node* h)
{
	if (h != NULL)
	{
		display_inorder(h->left);
		cout<<h->data<<"\t";
		display_inorder(h->right);
	}
}

void Binary_Tree::display_postorder(node* h)
{
	if (h != NULL)
	{
		display_inorder(h->left);
		display_inorder(h->right);
		cout<<h->data<<"\t";
	}
}

void Binary_Tree::display_preorder(node* h)
{
	if (h != NULL)
	{
		cout<<h->data<<"\t";
		display_inorder(h->left);
		display_inorder(h->right);
	}
}

void Binary_Tree::search(node *h, int item, bool flag)
{
	search(h->left,item, flag);
	if (item == h->data)
	{
		flag = true;
		return;
	}
	search(h->right,item, flag);
}
// Public Functions

int Binary_Tree::insert(int item)
{
	if (head == NULL)
	{
		node* n= new node(item);
		head = n;
		return 0;
	}
	node* prev;
	node* cur = head;

	string direction;
	cout<<"Enter Direction ( L for Letf and R for Right ) : ";
	cin >> direction;
	//getline(cin,direction);
	if (validate_input_and_toupper(direction))
	{
		cout<<"Invalid input please enter L or l for left and R or r for Right"<<endl;
		return -1;
	}

	node* n = new node(item);

	int i;

	for(i = 0; i <= direction.length() && cur != NULL; i++)
	{
		prev = cur;
		if(direction[i] == 'L')
			cur = cur->left;
		else
			cur = cur->right;
	}

	if (cur != NULL || i != direction.length())
	{
		cout<<"Invalid location :: cannot insert"<<endl;
		return -1;
	}

	if(direction[i-1] == 'L')
		prev->left = n;
	else
		prev->right = n;
	return 0;

}

void Binary_Tree::print_tree()
{
	print(head,0);
}
void Binary_Tree::display_inorder()
{
	display_inorder(head);
}

void Binary_Tree::display_postorder()
{
	display_postorder(head);
}

void Binary_Tree::display_preorder()
{
	display_preorder(head);
}


bool Binary_Tree::search(int item)
{
	bool flag = false;
	search(head, item, flag);
	return flag;
}

