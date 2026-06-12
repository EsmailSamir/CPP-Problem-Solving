#include <iostream>
#include <string>
using namespace std;
short int readNumber()
{
    short int number;
    cout << "\nEnter The Number: ";
    cin >> number;
    return number;
}
void testNumber(short int num)
{
    cout << "=============================\n";
    if (num % 2 == 0)
    {
        cout << "Number " << num << " Is EVEN\n";
    }
    else
        cout << "Number " << num << " Is ODD\n";
}
int main()
{
    short int userNum = readNumber();
    testNumber(userNum);
    return 0;
}