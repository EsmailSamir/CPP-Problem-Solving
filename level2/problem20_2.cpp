#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void printRandomBetween(char from, char to)
{
    cout << char(rand() % (to - from + 1) + from) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    printRandomBetween('a', 'z');
    printRandomBetween('A', 'Z');
    printRandomBetween('!', '/');
    printRandomBetween('0', '9');
    return 0;
}