#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../som3aLib.h"

using std::cout;

int main()
{
     srand((unsigned)time(NULL));

     short Number1 = limitsOfRandom(1, 5) * 2,
           Number2 = limitsOfRandom(1, 10);

     cout << "Think of a number between 1 and 10\n\n";
     Sleep(5000);

     cout << "Multiply(x2) the number by 2\n\n";
     Sleep(5000);

     cout << "Add(+) " << Number1 << " to the result\n\n";
     Sleep(5000);

     cout << "Throw half(/2) of them in the sea!\n\n";
     Sleep(5000);

     cout << "Subtract(-) " << Number2 << " from it\n\n";
     Sleep(5000);

     cout << "Subtract(-) the original number you thought of\n\n";
     Sleep(7000);

     cout << "\n\n\n\n========================\n\n";
     cout << "You are left with: " << (0.5 * Number1) - Number2 << "\n\n";

     return 0;
}