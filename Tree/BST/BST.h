#ifndef __TREE_H__
#define __TREE_H__
#include <string>
#include "Node.h"


class BST {
	node* head;
public:
	BST()
	{
		head = NULL;
	}
	virtual ~BST()
	{
		if(head)
		{
			delete head;
		}
	}
	int insert_with_duplicate(int item); 
	int insert_with_no_duplicate(int item); 

	virtual void display_inorder();   // LMR
	virtual void display_preorder();  // MLR
	virtual void display_postorder(); // LRM
	virtual void display_bfs();

	virtual node* search(int item);
	virtual node* search_iter(int item);
	virtual void print_tree();
	// TODO
	// Write copy constructor and assignment operator

private:
	void print(node* h, int i);
	void display_inorder(node *h);
	void display_preorder(node *h);
	void display_postorder(node *h);
	//int validate_input_and_toupper(std::string& str);
	node*  search(int item, node* h);
};

#endif

