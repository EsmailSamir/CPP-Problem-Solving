#include <iostream>
#include "../som3aLib.h"
using namespace std;
void printfibonaccy(short length, unsigned int &lastNum,
                    unsigned int &currentNum,
                    unsigned int &newNum)
{
    if (length > 0)
    {
        newNum = lastNum + currentNum;
        currentNum = lastNum;
        lastNum = newNum;
        cout << newNum << "\t";
        printfibonaccy(length - 1, lastNum,
                       currentNum, newNum);
    }
}
int main()
{
    unsigned int lastNum = 0, currentNum = 1, newNum = 0;
    printfibonaccy(readNumber(1, 47), lastNum, currentNum, newNum);
    return 0;
}