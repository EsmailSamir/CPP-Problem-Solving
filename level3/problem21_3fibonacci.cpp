#include <iostream>
#include "../som3aLib.h"
using namespace std;
void shifttingNumber(unsigned int &lastNum,
                     unsigned int &currentNum,
                     unsigned int &newNum)
{
    newNum = lastNum + currentNum;
    currentNum = lastNum;
    lastNum = newNum;
}
void printfibonaccy(const int length)
{
    unsigned int lastNum = 0, currentNum = 1, newNum;
    for (short i = 0; i < length; i++)
    {
        shifttingNumber(lastNum, currentNum, newNum);
        cout << newNum << "\t";
    }
}
int main()
{
    short length = readNumber(1, 47);
    printfibonaccy(length);
    return 0;
}