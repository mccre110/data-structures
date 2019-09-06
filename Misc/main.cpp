#include <iostream>
#include "SyntaxCheck.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    SyntaxCheck str(argv[1]);

    str.addBracket();

  }
  return 0;  
}