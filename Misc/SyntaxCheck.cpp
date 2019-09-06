#include "SyntaxCheck.h"
#include <iostream>

// research template classes
using namespace std;

SyntaxCheck::SyntaxCheck(string test)
{
  stack = new GenStack<char>();
  ImportedCodeFile.open(test, ifstream::in);
}

SyntaxCheck::~SyntaxCheck()
{
  ImportedCodeFile.close();
  delete stack;
  cout << "The syntax checker was destroyed." << endl;
}
void SyntaxCheck::addBracket()
{
  try
  {
    if (ImportedCodeFile)
    {
      lineCTR = 0;
      while (getline(ImportedCodeFile, line))
      {
        lineCTR++;
        for (int m = 0; m < line.length(); m++)
        {
          if (line[m] == '{')
          {
            stack->push('{');
          }
          else if (line[m] == '[')
          {
            stack->push('[');
          }
          else if (line[m] == '(')
          {
            stack->push('(');
          }

          else if (line[m] == '}')
          {
            if (stack->peek() == '{')
            {
               stack->pop();
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ) or ]" << endl;
                comp = true;
                break;
            }
          }
          else if (line[m] == ']')
          {
            if (stack->peek() == '[')
            {
               stack->pop();
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ) or }" << endl;
                comp = true;
                break;
            }
          }
          else if (line[m] == ')')
          {
            if (stack->peek() == '(')
            {
               stack->pop();
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ] or }"  << endl;
                comp = true;
                break;
            }
          }
        } 
      }
    }
    else
    {
      cout << "Your file does not exist! " << endl;
    }
  }
  catch (exception& e)
  {
    cout << "Line " << lineCTR << ": Extra Bracket "<< endl;
  }

  if (comp == false)
  {
    if (stack->isEmpty())
    {
       cout <<"Your code is fine! Nice syntax checking! (-:" << endl;
    }
    else
    {
      cout << "You have reached the end of the file. You are missing a bracket." << endl;
    }
  }
}