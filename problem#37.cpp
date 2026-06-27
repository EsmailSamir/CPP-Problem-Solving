#include <iostream>
using namespace std;
float readNumbers()
{
    float number, total = 0;
    while (true)
    {
        cout << "Enter Number: ";
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter A Numeric Value\n"
                 << "Enter Number: ";
            cin >> number;
        }
        if (number == -99)
            break;
        total += number;
    }
    return total;
}
void printTotal(const float total)
{
    cout << "=======================\n"
         << "Total - 99 = " << total;
}
int main()
{
    printTotal(readNumbers());
    return 0;
}