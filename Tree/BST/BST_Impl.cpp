#include <iostream>
#include <queue>
#include "BST.h"

using namespace std;


void BST::print(node* h, int i)
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

void BST::display_inorder(node* h)
{
	if (h != NULL)
	{
		display_inorder(h->left);
		cout<<h->data<<"\t";
		display_inorder(h->right);
	}
}

void BST::display_postorder(node* h)
{
	if (h != NULL)
	{
		display_inorder(h->left);
		display_inorder(h->right);
		cout<<h->data<<"\t";
	}
}

void BST::display_preorder(node* h)
{
	if (h != NULL)
	{
		cout<<h->data<<"\t";
		display_inorder(h->left);
		display_inorder(h->right);
	}
}

node* BST::search(int item, node *h)
{
	if( NULL == h || h->data == item )
		return h;
	if ( h->data >item )
		search(item, h->left);
	search(item, h->right);
}
// Public Functions
/*
 * Insert : Duplicate is allowed and on the right side
 * */
int BST::insert_with_duplicate(int item)
{
	if (head == NULL)
	{
		node* n= new node(item);
		head = n;
		return 0;
	}
	node* prev;
	node* cur = head;
	node* n = new node(item);

	while(cur)
	{
		prev = cur;
		cur = (item < cur->data)? cur->left : cur->right;
	}
	if(item < prev->data)
	{
		prev->left = n;
	}
	else
	{
		prev->right = n;
	}

	return 0;

}

/*
 * Insert : No duplicate is allowed and on the right side
 * */
int BST::insert_with_no_duplicate(int item)
{
	if (head == NULL)
	{
		node* n= new node(item);
		head = n;
		return 0;
	}
	node* prev;
	node* cur = head;
	node* n = new node(item);

	while(cur)
	{
		prev = cur;
		if (item = cur->data)
		{
			return -2;
			delete n;
		}
		cur = (item < cur->data)? cur->left : cur->right;
	}
	if(item < prev->data)
	{
		prev->left = n;
	}
	else
	{
		prev->right = n;
	}

	return 0;

}
void BST::print_tree()
{
	print(head,0);
}
void BST::display_inorder()
{
	display_inorder(head);
}

void BST::display_postorder()
{
	display_postorder(head);
}

void BST::display_preorder()
{
	display_preorder(head);
}


node* BST::search(int item)
{
	return search(item,head);
}

node* BST::search_iter(int item)
{
	node* tmp = head;
	while(tmp != NULL && tmp->data != item)
	{
		tmp = (tmp->data > item ) ? tmp->left : tmp->right;
	}
	return tmp;
}

void BST::display_bfs()
{
	queue<node*> q;
	node* tmp = head;
	if (head)
	{
		q.push(head);
	}
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		std::cout<<"\t"<<tmp->data<<"\t";
		if(tmp->left)
			q.push(tmp->left);
		if (tmp->right)
			q.push(tmp->right);
	}

}
