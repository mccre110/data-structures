#include "IO.h"
#include "GenStack.h"
using namespace std;

class Syntax
{
public:
	Syntax(string file);
	~Syntax();
	bool check();
	char inverse(char x);
	IO *out;
	GenStack<char> *myStack;
};