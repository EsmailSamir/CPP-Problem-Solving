#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    short a = 3, b = 6;
    printf("sum %d + %d = %d\n", a, b, a + b);
    printf("sum %1*d + %1*d = %1*d\n", a, b, a + b);

    return 0;
}