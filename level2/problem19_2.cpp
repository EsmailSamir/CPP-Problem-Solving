#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void readLimits(int &from, int &to)
{
    cout << "\nEnter Limits To Create (3) Random Numbers\n\n"
         << "Enter \"FROM\": ";
    cin >> from;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "\nEnter An Integer Numeric Value.\n"
             << "Enter \"FROM\": ";
        cin >> from;
    }
    cout << "\nEnter \"TO\": ";
    cin >> to;
    while (cin.fail() || cin.peek() != '\n' || from > to)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "\nEnter An Integer Numeric Value >= " << from
             << "\nEnter \"TO\": ";
        cin >> to;
    }
}
void printRandomNumber(const int from, const int to)
{
    cout << "\n======================";
    for (short i = 1; i < 4; i++)
    {
        cout << "\nRandom Number(" << i << "): "
             << rand() % (to - from + 1) + from;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int from, to;
    readLimits(from, to);
    printRandomNumber(from, to);
    return 0;
}