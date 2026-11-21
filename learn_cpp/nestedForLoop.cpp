#include <iostream>
using namespace std;
int main()
{
    for (short i = 1; i <= 10; i++)
    {
        for (short j = 1; j <= 10; j++)
        {
            cout << i << " X " << j
                 << " = " << i * j << '\n';
        }
        cout << '\n';
    }
    return 0;
}