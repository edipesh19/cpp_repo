#ifndef __TREE_H__
#define __TREE_H__
#include <string>
#include "Node.h"


class Binary_Tree {
	node* head;
public:
	Binary_Tree()
	{
		head = NULL;
	}
	virtual int insert(int item); 

	virtual void display_inorder();   // LMR
	virtual void display_preorder();  // MLR
	virtual void display_postorder(); // LRM

	virtual bool search(int item);
	virtual void print_tree();
	// TODO
	// Write copy constructor and assignment operator

private:
	void print(node* h, int i);
	void display_inorder(node *h);
	void display_preorder(node *h);
	void display_postorder(node *h);
	int validate_input_and_toupper(std::string& str);
	void search(node *h, int item, bool flag);
};

#endif

