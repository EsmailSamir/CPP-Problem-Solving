#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n---Making Two Random Arrays And Sum Them---\n\n"
         << "Enter length: ";
    cin >> length;
    while (cin.fail() || cin.peek() != '\n' 
        || length < 1 || 100 < length)
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
void createArray(short array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array[i] = limitsOfRandom(1, 100);
    }
}
void sumTwoArrays(const short array1[], const short length,
                  const short array2[], short sumArrays[])
{
    for (short i = 0; i < length; i++)
    {
        sumArrays[i] = array1[i] + array2[i];
    }
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
int main()
{
    srand((unsigned)time(NULL));
    short length = readLength(), array1[100],
          array2[100], sumArrays[100];
    createArray(array1, length);
    cout << "=================================================\n"
         << "Random Array (1): \n";
    printArray(array1, length);
    createArray(array2, length);
    cout << "=================================================\n"
         << "Random Array (2): \n";
    printArray(array2, length);
    sumTwoArrays(array1, length, array2, sumArrays);
    cout << "=================================================\n"
         << "Sum Of Two Arrays (3): \n";
    printArray(sumArrays, length);
    return 0;
}