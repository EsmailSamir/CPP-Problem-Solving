 #include <iostream>
using namespace std;
short int readLength()
{
    float length;
    cout << "\nHow Many Marks: ";
    cin >> length;
    while (cin.fail() || length != (short int)length || length <= 0 || length > 10)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Wrong Value, Pleas Enter score between [1,10]:\n"
             << "How Many Marks: ";
        cin >> length;
    }
    return (short int)length;
}
short int readArray(float numbers[], short int length)
{
    cout << "=============================\n";
    for (short int i = 0; i < length; i++)
    {
        cout << "Enter Value Mark[" << i + 1 << "] = ";
        cin >> numbers[i];
        while (cin.fail() || numbers[i] < 0 || numbers[i] > 100)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Wrong Value, Mark Should between [0,100]\n";
            cout << "Enter Value Mark[" << i + 1 << "] = ";
            cin >> numbers[i];
        }
    }
    return length;
}
float totalArray(float numbers[], short int length)
{
    float total = 0;
    for (short int i = 0; i < length; i++)
    {
        total += numbers[i];
    }
    return total;
}
float calculateAvarage(float total, short int length)
{
    float avarage = total / (float)length;
    return avarage;
}
void printAvarage(float avarage)
{
    cout << "=============================\n"
         << "Avarage Of Marks = " << avarage
         << "%\n";
}
void testPassing(float avarage)
{
    if (avarage >= 50)
    {
        cout << "_______________PASS\n";
    }
    else
        cout << "_______________FAIL\n";
}
int main()
{
    short int length = readLength();
    float numbers[length];
    readArray(numbers, length);
    float total = totalArray(numbers, length);
    float avarage = calculateAvarage(total, length);
    printAvarage(avarage);
    testPassing(avarage);
    return 0;
}