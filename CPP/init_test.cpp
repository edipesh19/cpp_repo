#include <iostream.h>
//using namespace std;
class GamePlayer {
	public:
	GamePlayer()
	{
		for (int i = 0; i < NUM_TURNS; i++)
			scores[i] = i;
	}
	void print()
	{
		for (int i = 0; i < NUM_TURNS; i++)
			cout<<"scores["<<i<<"] = "<<scores[i]<<endl;
		//cout<<"X = "<<x<<endl;
	}
	private:
		static const int NUM_TURNS = 5; // constant declaration
		int scores[NUM_TURNS]; // use of constant
		// int x = 0; // This will be error
};

int main()
{
	GamePlayer obj;
	obj.print();
	return 0;
}
