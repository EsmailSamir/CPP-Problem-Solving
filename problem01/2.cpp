#include <iostream>
using namespace std;
void headerMulti()
{
    cout << "\n\t\t\tMULTIPLCATION TABLE FROM 1 TO 10\n";
    for (short int i = 1; i <= 10; i++)
    {
        cout << "\t" << i;
    }
    cout << "\n-----------------------------------------------------------------------------------";
}
void multiblicateNum()
{
    for (short int i = 1; i <= 10; i++)
    {
        cout << "\n"
             << i << "\t|";
        for (short int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
    }
}
int main()
{
    headerMulti();
    multiblicateNum();
    return 0;
}