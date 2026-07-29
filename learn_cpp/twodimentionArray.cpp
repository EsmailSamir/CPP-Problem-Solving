#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    short x[10][10];
    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            x[i][j] = (i + 1) * (j + 1);
        }
    }
    for (short i = 0; i < 10; i++)
    {
        for (short j = 0; j < 10; j++)
        {
            printf("%0*d ", 2, x[i][j]);
        }
        cout << '\n';
    }
    return 0;
}