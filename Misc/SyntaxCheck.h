#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class SyntaxCheck
{
  public:
    SyntaxCheck(string test);
    ~SyntaxCheck();
    void addBracket();
    GenStack<char> *stack;
    int lineCTR;
    ifstream ImportedCodeFile;
    bool comp = false;

  private:
    string line; 
    string test;
    

};

