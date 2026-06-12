#include <iostream>
using namespace std;
short int readArray(float numbers[])
{
    short int length;
    cout << "\nHow Many Marks: ";
    cin >> length;
    cout << "=============================\n";
    for (short int i = 0; i < length; i++)
    {
        cout << "Enter Value Mark[" << i + 1 << "] = ";
        cin >> numbers[i];
    }
    return length;
}
float avarageArray(float numbers[], short int length)
{
    float colect = 0;
    for (short int i = 0; i < length; i++)
    {
        colect += numbers[i];
    }
    float avarage = colect / (float)length;
    return avarage;
}
void printColectArray(float avarage)
{
    cout << "=============================\n"
         << "Avarage Of Marks = " << avarage
         << '\n';
}
int main()
{
    float numbers[10];
    short int length = readArray(numbers);
    float avarage = avarageArray(numbers, length);
    printColectArray(avarage);
    return 0;
}
