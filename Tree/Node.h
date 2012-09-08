#ifndef __NODE_H__
#define __NODE_H__

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
};

#endif //__NODE_H__
