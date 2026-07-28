#include <iostream>
#include "../som3aLib.h"
using namespace std;
int main()
{
    int limit = readNumber(0,1000);
    cout << "=====================\nThe Prime Numbers Is:\n";
    for (int number = 2; number <= limit; number++)
    {
        if (testPrimeNumber(number))
            cout << number << '\n';
    }
    return 0;
}