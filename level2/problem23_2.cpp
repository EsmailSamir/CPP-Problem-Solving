#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../som3aLib.h"
using namespace std;
short readLength()
{
    short length;
    cout << "\n-------Making A Random Array-------\n\n"
         << "Enter length: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n' || length < 1 || 100 < length)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [1, 100]\n"
             << "Enter length: ";
        cin >> length;
    }
    return length;
}
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(), array[100];
    createRandomArray(array, length);
    cout << "========================================\n"
         << "Random Array : \n";
    printArray(array, length);
    return 0;
}