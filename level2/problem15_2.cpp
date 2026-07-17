#include <iostream>
using namespace std;
short readNumber()
{
    short number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 1 || 26 < number)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [1:26]: ";
        cin >> number;
    }
    return number;
}
void printPatternLetter(short number)
{
    cout << "===========================";
    for (short i = 1; i <= number; i++)
    {
        cout << '\n';
        for (short j = i; j > 0; j--)
        {
            cout << char(i + 'A' - 1);
        }
    }
}
int main()
{
    printPatternLetter(readNumber());
    return 0;
}