#include <iostream>
using namespace std;
void readNumbers(float numbers[], short int length)
{
    for (short int i = 0; i < length; i++)
    {
        cout << "enter value number [" << i + 1 << "] = ";
        cin >> numbers[i];
    }
}
void testNumbers(float numbers[])
{
    cout << "===============================\n";
    if (numbers[0] > numbers[1])
    {
        cout << numbers[0] << " Is Bigger Than.";
    }
    else if (numbers[0] < numbers[1])
    {
        cout << numbers[1] << " Is Bigger Than.";
    }
    else
        cout << "All Is Equal";
}
int main()
{
    short int length = 2;
    float numbers[length];
    readNumbers(numbers, length);
    testNumbers(numbers);
    return 0;
}
