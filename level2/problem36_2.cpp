#include <iostream>
using namespace std;
short readNumbersForArray(short array[], const short maxLength)
{
    short i = 0;
    bool more;
    do
    {
        cout << "\nPlease Enter A Number [1, 100]: ";
        cin >> array[i];
        while (cin.fail() || cin.peek() != '\n' || array[i] < 1 || 100 < array[i])
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "Enter A Positive Numeric Value [1, 100]\n"
                 << "Enter Number [1, 100]: ";
            cin >> array[i];
        }
        cout << "Do You Want To Add More Numbers?\n(0)No, (1)Yes:  ";
        cin >> more;
        while (cin.fail() || cin.peek() != '\n' || more < 0 || 1 < more)
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "Enter Only (0)No, (1)Yes: ";
            cin >> more;
        }
        i++;
    } while (more && i < maxLength);
    return i;
}
void printLengthAndArray(const short array[], const short length)
{
    cout << "====================================\n"
         << "Array Length = " << length
         << "\nArray Elements: \n[";
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
int main()
{
    short array[100], maxLength = 100;
    printLengthAndArray(
        array, readNumbersForArray(array, maxLength));
    return 0;
}