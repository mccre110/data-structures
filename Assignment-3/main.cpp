#include "Syntax.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	Syntax *s;	//command line input exists
	if (argc>1)
	{
		s = new Syntax(argv[1]);

		//loop if file is good
		while(!s->check())
		{
			string str;
			cout << "Another File?[Y/N]"<< endl;
			getline(cin, str);
			if (str == "y"||str == "Y")
			{
				delete s;
				//new syntax checker based on input
				cout << "File Name : "<< endl;
				getline(cin, str);
				s =new Syntax(str);
			}
			else
				break;
		}
	}
	//bad command line input
	else
		cout << " Enter a vaild file name."<<endl;

	return 0;
}