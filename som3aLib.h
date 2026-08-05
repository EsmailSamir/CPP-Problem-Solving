#pragma once
#include <iostream>
using namespace std;

short readNumber(const short from, const short to)
{
    short number;
    cout << "Enter Number: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < from || to < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "\nEnter A Positive Numeric Value["
             << from << ", " << to << "]:\n"
             << "Enter Number: ";
        cin >> number;
    }
    return number;
}

short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
}

void createRandomArray(short array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array[i] = limitsOfRandom(0, 100);
    }
}

void printArray(const short array[], const short length)
{
    cout << "{";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            cout << array[i] << ", ";
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
        else
            cout << array[i] << "}\n";
    }
}

bool testPrimeNumber(const int number)
{
    if (number < 2)
        return false;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

string readName()
{
    string name;
    cout << "Enter Name: ";
    getline(cin, name);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000000, '\n');
        cout << "Enter Name: ";
        getline(cin, name);
    }
    return name;
}

float myAbsFunction(float number)
{
    if (number < 0)
        number *= -1;
    return number;
}

short validation(short number, const short from, const short to)
{
    while (cin.fail() || cin.peek() != '\n' || number < from || to < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "\nEnter A Numeric Value["
             << from << ", " << to << "]:\n"
             << "Enter Number: ";
        cin >> number;
    }
    return number;
}

void readArray(short array[], const short length, const short from, const short to)
{
    cout << "\nEnter Array Elements:\n";
    for (short i = 0; i < length; i++)
    {
        cout << "Element [" << i + 1 << "]: ";
        readNumber(from, to);
    }
}

bool checkIdentityMatrix3_3(const short matrix[][3],
                         const short rows, const short columns)
{
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < columns; j++)
        {
            if (i == j && matrix[i][j] != 1)
                return false;
            else if (i != j && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}