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
void printfibonaccy(const short length)
{
    unsigned int lastNum = 0, currentNum = 1, newNum = 0;
    for (short i = 0; i < length; i++)
    {
        shifttingNumber(lastNum, currentNum, newNum);
        cout << newNum << "\t";
    }
}
int main()
{
    printfibonaccy(readNumber(1, 47));
    return 0;
}