#include <iostream>
using namespace std;

class A {
    public:
        void func()
        {
            cout<<"A::func()\n";
        }
};

class B:public A {
    public:
        void func()
        {
            cout<<"B::func\n";
        }
};

int main()
{
    A *aptr, a;
    B *bptr, b;

    a.func();
    b.func();

    aptr = &a;
    aptr->func();

    aptr = &b;
    aptr->func();

    bptr = &b;
    bptr->func();

    return 0;
}
