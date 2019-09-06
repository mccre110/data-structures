#include <iostream>
#include "Syntax.h"

Syntax::Syntax(string file)
{
	out = new IO(file,"");
	myStack = new GenStack<char>();
}
Syntax::~Syntax()
{
	delete out;
	delete myStack;
}
//inverses close brackest to match the stack
char Syntax::inverse(char x)
{
	if (x==')')
		return '(';
	else if (x=='}')
		return '{';
	else if (x==']')
		return '[';
}

//Checks mismach and missing delimeters
bool Syntax::check()
{
	int num = 1;
	bool ck = false;
	string line;
	line = out->readLine();
	while (line!="")
	{
		for (char& x : line)
		{
			try
			{
				//if open delimeter push to stack
				if (x== '('||x=='{'||x=='[')
					myStack->push(x);
				//check close delimeter matches what is on the stack
				else if (x==')'|| x=='}'|| x==']')
				{
					if (this->inverse(x)==myStack->peak())
						myStack->pop();
					else
					{
						cout <<"Line " <<num<< ": Expected ) and found "<<x<<endl;
						ck = true;
						break;
					}
				}	
			}
			//if stack is empty and pop/peak is called then extra closing del.
			catch (std::invalid_argument& e)
			{
				cout <<"Line " <<num<< ": Found an extra: " <<x<<endl;
				ck = true;
				break;
			}			
		}
		line = out->readLine();
		num++;
	}
	if (ck==false)
	{
		//if stack is empty and no mismatch or extra then file is good
		if (myStack->isEmpty())
		{
			cout << "Looks good!" << endl;
		}
		//end of file and stack isnt empty, missing bracket
		else
		{
			cout << "End of file, missing bracket!"<<endl;
			ck = true;
		}		
	}
	return ck;
}


