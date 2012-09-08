#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

struct node {
	int data;
	node* left;
	node* right;
	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	node (int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
	~node()
	{
		if (left)
			delete left;
		if(right)
			delete right;
	}
};

#endif //__NODE_H__
