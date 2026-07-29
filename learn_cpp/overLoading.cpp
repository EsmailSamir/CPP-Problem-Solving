#include <iostream>
using namespace std;

short sum(short a, short b)
{
    return (a + b);
}
short sum(double a, double b, double c)
{
    return (a + b + c);
}
short sum(int a, int b, int c)
{
    return (a + b + c);
}
short sum(double a, double b, double c, double d)
{
    return (a + b + c + d);
    sum(5, 6, 8);
}

int main()
{

    cout << sum(10, 20) << '\n'
         << sum(10.77, 20.57, 30.67) << '\n'
         << sum(5, 6, 9) << '\n'
         << sum(10.6, 20.9, 30.7, 40.5);
    return 0;
}