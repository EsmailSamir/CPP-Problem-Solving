#include <iostream>
using namespace std;
int main()
{
    short *point;
    point = new short;
    *point = 10;
    cout << &point << '\n'
         << *point << '\n';
    delete point;// delet 
    point = nullptr;// in space without value
    cout << &point << '\n'
         << *point << '\n';
    return 0;
}