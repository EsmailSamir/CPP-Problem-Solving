#include <iostream>
using namespace std;
/*struct numbers
{
    float number1;
    float number2;
    float number3;
};
numbers ReadNum()
{
    numbers stAllNumber;
    cout << "enter three numbers\n"
         << "enter first number: ";
    cin >> stAllNumber.number1;
    cout << "enter second number: ";
    cin >> stAllNumber.number2;
    cout << "enter third number: ";
    cin >> stAllNumber.number3;
    return stAllNumber;
}
float sumNum(const numbers &stAllNumber)
{
    float sum = stAllNumber.number1 + stAllNumber.number2 + stAllNumber.number3;
    return sum;
}
void printSum(const numbers &stAllNumber)
{
    cout << "================================="
         << "sum numbers = " << sumNum(stAllNumber);
}*/
short int readArray(short int numbers[])
{
    short int length;
    cout << "\nHow Many Numbers: ";
    cin >> length;
    cout << '\n';
    for (short int i = 0; i < length; i++)
    {
        cout << "Enter Value Number[" << i + 1 << "] = ";
        cin >> numbers[i];
    }
    return length;
}
short int totalArray(short int numbers[], short int length)
{
    short int colect = 0;
    for (short int i = 0; i < length; i++)
    {
        colect += numbers[i];
    }
    return colect;
}
void printColectArray(short int colect)
{
    cout << "=============================\n"
         << "Total The Numbers = " << colect
         << '\n';
}
int main()
{
    /*printSum(ReadNum());*/
    short int numbers[10];
    short int length = readArray(numbers);
    short int colect = totalArray(numbers, length);
    printColectArray(colect);
    return 0;
}
