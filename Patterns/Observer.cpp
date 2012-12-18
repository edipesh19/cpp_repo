#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class observer {
public:
	virtual void notify()=0;
};

class subject {
	vector<observer*> vec;
public:
	void subscribe(observer * ptr);
	void unsubscribe(observer * ptr);
	void update();
};

void subject::subscribe(observer* obj)
{
	vec.push_back(obj);
}

void subject::unsubscribe(observer* obj)
{
	for (vector<observer*>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (typeid(*(*it)) == typeid(*obj))
		{
			vec.erase(it);
			return;
		}
	}
}

void subject::update()
{
	for (vector<observer*>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		(*it)->notify();
	}
}

class view1:public observer {
public:
	void notify();
};
class view2:public observer {
public:
	void notify();
};
class view3:public observer {
public:
	void notify();
};

void view1::notify()
{
	cout<<"view1 notified"<<endl;
}

void view2::notify()
{
	cout<<"view2 notified"<<endl;
}

void view3::notify()
{
	cout<<"view3 notified"<<endl;
}

int main()
{
	subject sub;
	view1 v1;
	view2 v2;
	view3 v3;

	sub.subscribe(&v1);
	sub.subscribe(&v2);
	sub.subscribe(&v3);
	sub.update();

	cout<<"==============================================="<<endl;
	sub.unsubscribe(&v2);
	sub.update();

	sub.subscribe(&v2);
	sub.update();

	return 0;

}