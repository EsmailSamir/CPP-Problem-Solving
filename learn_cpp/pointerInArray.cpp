#include <iostream>
using namespace std;
int main()
{
    short array[] = {10, 20, 30, 40};
    short *pntr = &array[0];
    cout << &array << '\n'
         << pntr << '\n'
         << &array[0] << '\n'
         << *pntr << '\n'
         << *(pntr + 1) << '\n'
         << *(pntr + 2) << '\n'
         << *(pntr + 3) << '\n';
    return 0;
}