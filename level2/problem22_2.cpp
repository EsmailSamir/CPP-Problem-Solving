#include <iostream>
#include <string>
using namespace std;
short readLength()
{
    short length;
    cout << "\n--Make Array And Count repeated Value--\n\n"
         << "========================================\n"
         << "Enter length: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n' || length < 1 || 1000 < length)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value > 0\n"
             << "Enter length: ";
        cin >> length;
    }
    return length;
}
void createArray(short array[], const short length)
{
    cout << "========================================\n";
    for (short i = 0; i < length; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> array[i];
    }
}
short checkNumber()
{
    short numberToCheck;
    cout << "========================================\n"
         << "Enter Number You Want To Check: ";
    cin >> numberToCheck;
    while (cin.fail() || cin.peek() != '\n' 
           || numberToCheck < 0 || 1000 < numberToCheck)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numeric Value > 0\n"
             << "Enter Number To Check: ";
        cin >> numberToCheck;
    }
    return numberToCheck;
}
short countRepeated(const short array[],
                    const short numberToCheck, const short length)
{
    short repeated = 0;
    for (short i = 0; i < length; i++)
    {
        if (array[i] == numberToCheck)
            repeated++;
    }
    return repeated;
}
void printArrayAndRepeated(const short array[], const short length,
                           const short numberToCheck, const short repeated)
{
    cout << "========================================\n"
         << "Original Array : [";
    for (short i = 0; i < length; i++)
    {
        if (i < length - 1)
            cout << array[i] << ',';
        else

            cout << array[i] << "]";
    }
    string time = "Time";
    if (repeated > 1)
        time += 's';
    cout << "\n========================================\n"
         << numberToCheck << " Is repeated " << repeated
         << ' ' << time << '\n';
}
int main()
{
    short length = readLength(), array[length];
    createArray(array, length);
    short numberToCheck = checkNumber(),
          repeated = countRepeated(array, numberToCheck, length);
    printArrayAndRepeated(array, length, numberToCheck, repeated);
    return 0;
}
