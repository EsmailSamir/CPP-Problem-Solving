#include <iostream>
using namespace std;
void nested1()
{
    for (char i = 'A'; i <= 'Z'; i++)
    {
        cout << "letter: " << i << "\n";
        for (char j = 'A'; j <= 'Z'; j++)
        {
            cout << i << j << "\n";
        }
        cout << "*********\n\n";
    }
}
void stars()
{
    cout << "________________________________\n\n";
    for (short int i = 1; i <= 10; i++)
    {
        for (short int j = 10; j >= i; j--)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    cout << "________________________________\n\n";
}
void nums()
{
    cout << "________________________________\n\n";
    for (short int i = 1; i <= 10; i++)
    {
        for (short int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "________________________________\n\n";
}
void nums2()
{
    cout << "________________________________\n\n";
    for (short int i = 10; i >= 1; i--)
    {
        for (short int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "________________________________\n";
}
void abc()
{
    for (char i = 'A'; i <= 'F'; i++)
    {
        for (char j = 'A'; j <= i; j++)
        {
            cout << j << ' ';
        }
        cout << "\n";
    }
    cout << "________________________________\n";
}
void lastnum()
{
    for (short int i = 1; i <= 10; i++)
    {
        for (short int j = i; j <= 10; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
int main()
{
    nested1();
    stars();
    nums();
    nums2();
    abc();
    lastnum();
    return 0;
}