#include <iostream>
using namespace std;
void readArray(short int x[3])
{
    cout << "enter first num : ";
    cin >> x[0];
    cout << "enter second num: ";
    cin >> x[1];
    cout << "enter third num : ";
    cin >> x[2];
}
void avarageArray(short int x[3])
{
    cout << "***********************\n"
         << "the avarage is  = "
         << (x[0] + x[1] + x[2]) / 3;
}
int main()
{
    short int x[3];
    readArray(x);
    avarageArray(x);
    return 0;
}