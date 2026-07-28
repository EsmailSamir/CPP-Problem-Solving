#include <iostream>
using namespace std;
int main()
{

    for (short i : {1, 2, 3, 4, 5, 6, 7, 8, 9})
        cout << i << '\n';

    short numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "{";
    for (short i : numbers)
    {
            cout  << numbers[i-1] << ", ";
    }
    return 0;
}