#include <iostream>
using namespace std;

short sum(short a, short b, short c = 0, short d = 0)
{
    return (a + b + c + d);
}
int main()
{

    cout << sum(10, 20) << '\n'
         << sum(10, 20, 30) << '\n'
         << sum(10, 20, 30, 40);
    return 0;
}