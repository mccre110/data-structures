#include "Board.h"

using namespace std;

class Game
{
public:
	Game(int h, int l, double density, int mode);
	Game(string fileName, int mode);
	~Game();
	void print();
	bool check();
	void simulate();
	int count=0;
	Board *board;

	
};