#include "Registrar.h"
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1)
	{
		Registrar reg(argv[1]);
		reg.sim();
		reg.print();
	}

	return 0;
}