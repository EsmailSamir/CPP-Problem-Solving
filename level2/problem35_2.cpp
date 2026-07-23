#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "Enter length [1, 100]: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n' || length < 1 || 100 < length)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [1, 100]\n"
             << "Enter length: ";
        cin >> length;
    }
    return length;
}
short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
}
void createAnArray(short array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array[i] = limitsOfRandom(1, 100);
    }
}
short readNumberToSearch()
{
    short number;
    cout << "Enter Number To Search: ";
    cin >> number;
    while (cin.fail() || cin.peek() != '\n' || number < 1 || 100 < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value [1, 100]\n"
             << "Enter Number To Search: ";
        cin >> number;
    }
    return number;
}
short searchInArray(
    const short array[], const short length, const short number)
{
    for (short index = 0; index < length; index++)
    {
        if (array[index] == number)
            return index;
    }
    return -1;
}
void printArray(const short array[], const short length)
{
    cout << "[";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
        {
            cout << array[i] << ", ";
            if ((i + 1) % 10 == 0)
                cout << '\n';
        }
        else
            cout << array[i] << "]\n";
    }
}
void printFoundIndex(const short number, const short index)
{
    cout << "Number You Are Looking For Is: " << number << "\n\n";
    if (index > -1)
        cout << "Yes, The Number Is Found :-)\n";
    else
        cout << "No, The Number Is Not Found :-(\n";
}
int main()
{
    cout << "\n--Making A Random Array And Search In--\n\n";
    srand((unsigned)time(NULL));
    short length = readLength(), array[100];
    createAnArray(array, length);
    cout << "========================================\n"
         << "The Random Array:\n";
    printArray(array, length);
    cout << "========================================\n";
    short number = readNumberToSearch();
    cout << "========================================\n";
    printFoundIndex(number, searchInArray(array, length, number));
    return 0;
}