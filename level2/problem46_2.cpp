#include <iostream>
#include "../som3aLib.h"
using namespace std;
void printResult(float numberAbs, float number)
{
    cout << "\n=============================\n"
         << "My abs Result : " << numberAbs << '\n'
         << "C++ abs Result: " << abs(number) << '\n';
}
int main()
{
    float number = readNumber(-100,100);
    printResult(myAbsFunction(number), number);
    return 0;
}