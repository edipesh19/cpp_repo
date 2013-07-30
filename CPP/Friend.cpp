#include <iostream>
#include <string>
using namespace std;

class X;

class Y
{
public:
	void funy(X&);
};

class X
{
	string i;
public:
	friend void Y::funy(X& x); // Another class fuction is friend to this
	friend void globalFunc(X& x); // Global function is friend to this.
	friend class Z;                      // Another class is friend to this.
	string geti(){return i;}
	X(){i = "Class X";}
	
};

void Y::funy(X& x)
{
	x.i = "Class Y";
}

void globalFunc(X& x)
{
	x.i = "Global";
}

class Z
{
	string str;
public:
	Z(){str = "class Z";}
	void fun(X& x);
};

void Z::fun(X& x)
{
	x.i = str;
}

int main()
{
	X obj;
	Y objy;
	Z objz;

	cout<<"After Calling Constructor = "<< obj.geti() <<endl;
	objy.funy(obj);
	cout<<"After Calling Y Friend = "<< obj.geti() <<endl;
	globalFunc(obj);
	cout<<"After Calling Global Friend = "<< obj.geti() <<endl;
	objz.fun(obj);
	cout<<"After Calling Friend Class function = "<< obj.geti() <<endl;

	return 0;
}