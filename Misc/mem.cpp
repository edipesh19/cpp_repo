#include <iostream>
using namespace std;

struct big {
	int a;
	char *b;
	int c;
	char *d;
	int e;
	char *f;
};
struct small {
	int a;
	char *b;
	int c;
};


int main()
{
	char src1[4] = "bbb";
	char src2[5] = "dddd";
	char src3[6] = "fffff";
	big *BIG = new big();
	big *BIG2 = new big();
	small *SMALL = new small();

	// initializing BIG
	BIG->a = 10;
	BIG->b = new char[4];
	memcpy(BIG->b, src1, 4);
	BIG->c = 20;
	BIG->d = new char[5];
	memcpy(BIG->d, src2, 5);
	BIG->e = 30;
	BIG->f = new char[6];
	memcpy(BIG->f, src3, 6);


	//memcpy(BIG2, BIG, sizeof(*BIG));
	memcpy(SMALL, BIG, sizeof(*BIG));
	//memcpy(BIG1, BIG, sizeof(BIG));
	cout<<"Size of class "<<sizeof(big)<<endl;
	cout<<"Size of object "<<sizeof(*BIG)<<endl;
	cout<<"BIG : "<<"a = "<<BIG->a<<"\t"<<"b = "<<BIG->b<<"\t"<<"c = "<<BIG->c<<"\t"<< "d = " << BIG->d<< "e = " << BIG->e << "f = " << BIG->f << endl;
	//cout<<"BIG2 : "<<"a = "<<BIG2->a<<"\t"<<"b = "<<BIG2->b<<"\t"<<"c = "<<BIG2->c<<"\t"<< "d = " << BIG2->d<< "e = " << BIG2->e << "f = " << BIG2->f << endl;
	cout<<"SMALL : "<<"a = "<<SMALL->a<<"\t"<<"b = "<<SMALL->b<<"\t"<<"c = "<<SMALL->c<<endl;
	return 0;
}
