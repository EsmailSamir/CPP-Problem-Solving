#include <iostream>
#include <iomanip>
using namespace std;
int readLength()
{
    double length;
    cout << "\nHow Many Marks: ";
    cin >> length;
    while (cin.fail() || length != (int)length || length < 2 || length > 100)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong Value, Pleas Enter An Integer Value 100 >= 2 :\n"
             << "How Many Marks: ";
        cin >> length;
    }
    return (int)length;
}
void readNumbers(double numbers[], int length)
{
    cout << "=============================\n\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Enter Value [" << i + 1 << "] = ";
        cin >> numbers[i];
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Wrong Value, Pleas Enter A Numiric Value.\n";
            cout << "Enter Value Mark[" << i + 1 << "] = ";
            cin >> numbers[i];
        }
    }
}
double testNumbers(double numbers[], int length)
{
    double maxNumber = numbers[0];
    for (int i = 1; i < length; i++)
    {
        if (numbers[i] > maxNumber)
        {
            maxNumber = numbers[i];
        }
    }
    return maxNumber;
}
void printResult(double maxNumber)
{
    cout << "\n===============================\n"
         << fixed << setprecision(10)
         << maxNumber << " is the biggest.\n";
}
int main()
{
    int length = readLength();
    double numbers[length];
    readNumbers(numbers, length);
    double maxNumber = testNumbers(numbers, length);
    printResult(maxNumber);
    return 0;
}