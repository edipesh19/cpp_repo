#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() = 0;
};

class legacyRectangle{
	int coordinate[4];
public:
	legacyRectangle(int coordinate1, int coordinate2, int coordinate3, int coordinate4)
	{
		cout<<"legacyRectangle created"<<endl;
		coordinate[0] = coordinate1;
		coordinate[1] = coordinate2;
		coordinate[2] = coordinate3;
		coordinate[3] = coordinate4;
	}
	void olddraw()
	{
		cout<<"Legacy Old Draw"<<endl;
	}
};


// Adapter Wrapper which implement the interace and it privately inherite the
// legacyRectangle class to get the implementation of olddraw function

class adapter:public Shape, private legacyRectangle {
public:
	adapter(int coordinate1, int coordinate2, int coordinate3, int coordinate4)
		:legacyRectangle(coordinate1, coordinate2, coordinate3, coordinate4){
			cout<<"Adapter class created"<<endl;
	}
	void draw()
	{
		cout<<"Adapter Draw"<<endl;
		olddraw();
	}
};

int main()
{
	adapter a(1,2,3,4);
	a.draw();
	return 0;
}