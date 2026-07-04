#include <iostream>
using namespace std;
int readNumbers()
{
    float number;
    cout << "Enter An Integer Number: ";
    cin >> number;
    while (cin.fail() || number != int(number))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter An Integer Numeric Value: ";
        cin >> number;
    }
    return number;
}
string proccNumber(int number)
{
    for (short int i = 2; i < number; i++)
    {
        if (number % i != 0)
            return "NOT PRIME"; 
        else
            return "PRIME";
    }
}
void printResult(string result)
{
    cout << result;
}
int main()
{
    printResult(proccNumber(readNumbers()));
    return 0;
}