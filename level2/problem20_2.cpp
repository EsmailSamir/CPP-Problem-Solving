#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void printRandom(char from, char to)
{
    cout << char(rand() % (to - from + 1) + from) << '\n';
}
int main()
{
    srand((unsigned)time(NULL));
    printRandom('a', 'z');
    printRandom('A', 'Z');
    printRandom('!', '/');
    printRandom('0', '9');
    return 0;
}