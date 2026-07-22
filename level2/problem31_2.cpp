#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readLength()
{
    short length;
    cout << "\n-----Making An Array And Random It----\n\n"
         << "Enter length: ";
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
void createOrgnizedArray(short array1[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        array1[i] = i + 1;
    }
}
void shuffleTheArray(const short array1[], const short length, short array2[])
{
    for (short i = 0; i < length; i++)
    {
        bool isDuplicate;
        do
        {
            isDuplicate = false;                   // نفترض إن الرقم سليم
            array2[i] = limitsOfRandom(1, length); // نخمن رقم
            // نفحص الأرقام السابقة فقط
            for (short j = 0; j < i; j++)
            {
                if (array2[i] == array2[j])
                {
                    isDuplicate = true; // اكتشفنا إنه متكرر!
                    break;              // نوقف حلقة الفحص فوراً
                }
            }
        } while (isDuplicate); // لو متكرر، الدورة هتعيد التخمين لنفس الخانة
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
    short length = readLength(), array1[100], array2[100];
    createOrgnizedArray(array1, length);
    cout << "========================================\n"
         << "Orgnized Array:\n[";
    printArray(array1, length);
    shuffleTheArray(array1, length, array2);
    cout << "========================================\n"
         << "Shuffle Same Array:\n[";
    printArray(array2, length);
    return 0;
}