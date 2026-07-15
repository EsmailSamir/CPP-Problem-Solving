#include <iostream>
using namespace std;
short int x = 200;
void func()
{
    short int x = 1;
    cout << "local  1 = " << x;
}
int main()
{
    short int x = 2;
    func();
    cout << "\n"
         << "local  2 = " << x << "\n"
         << "global x = " << ::x;
    return 0;
}