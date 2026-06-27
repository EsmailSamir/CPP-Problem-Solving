#include <iostream>
using namespace std;
void readNumbers(float &firstNum, float &secondNum, char &operation)
{
    cout << "Enter First Number: ";
    cin >> firstNum;
   
    }
    cout << "Enter Operation (+,-,*,/): ";
    cin >> operation;
    while (cin.fail() || (operation != '+' && operation != '-' && operation != '*' && operation != '/'))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter Operation Only From (+,-,*,/): ";
        cin >> operation;
    }
    cout << "Enter Second Number: ";
    cin >> secondNum;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Numeric Value\n"
             << "Enter Second Number: ";
        cin >> secondNum;
    }
}
float calculate(const float &firstNum, float &secondNum, const char operation)
{
    if (operation == '+')
        return firstNum + secondNum;
    else if (operation == '-')
        return firstNum - secondNum;
    else if (operation == '*')
        return firstNum * secondNum;
    else
    {
        while (secondNum == 0)
        {
            cout << "Wrong Value, Can Not Divsion On Zero\n"
                 << "Enter Second Number: ";
            cin >> secondNum;
        }
        return firstNum / secondNum;
    }
}
void printResult(float result)
{
    cout << "================================\n"
         << "Result Is = " << result;
}
int main()
{
    float firstNum, secondNum;
    char operation;
    readNumbers(firstNum, secondNum, operation);
    printResult(calculate(firstNum, secondNum, operation));
    return 0;
}