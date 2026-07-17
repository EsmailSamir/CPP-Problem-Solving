#include <iostream>
using namespace std;
short readNumber()
{
    short number;
    cout << "Enter A Number: ";
    cin >> number;
    while (cin.fail() || number < 0 || cin.peek() != '\n' || number > 10)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value [0:10]: ";
        cin >> number;
    }
    return number;
}
void printPattern(const short number)
{
    cout << "=====================\n";
    for (short i = 1; i <= number; i++)
    {
        for (short j = i; j > 0; j--)
        {
            cout << i;
        }
        cout << '\n';
    }
}
int main()
{
    printInverted(readNumber());
    return 0;
}