#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
short readKeys()
{
    short limitsKey;
    cout << "\n--Generate Array For Random Keys --\n\n"
         << "Enter How Many Keys [0, 100]: ";
    cin >> limitsKey;
    while (cin.fail() || cin.peek() != '\n' || limitsKey < 0 || 100 < limitsKey)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Positive Numiric Value\n"
             << "Enter How Many Keys [0, 100]: ";
        cin >> limitsKey;
    }
    return limitsKey;
}
short limitsOfRandom(const short from, const short to)
{
    return rand() % (to - from + 1) + from;
}
string generatekey()
{
    string key = "";
    for (short j = 1; j <= 16; j++)
    {
        key += limitsOfRandom('A', 'Z');
        if (j % 4 == 0 && j != 16)
            key += '-';
    }
    return key;
}
void creatArrayForKeys(const short keys, string arrayKeys[])
{
    for (short i = 0; i < keys; i++)
    {
        arrayKeys[i] = generatekey();
    }
}
void printArray(const string array[], const short length)
{
    for (short i = 0; i < length; i++)
    {
        cout << "Array_Key[" << i << "]: "
             << array[i] << '\n';
    }
}
int main()
{
    srand((unsigned)time(NULL));
    string arrayKeys[100];
    short keys = readKeys();
    creatArrayForKeys(keys, arrayKeys);
    cout << "===================================\n";
    printArray(arrayKeys, keys);
    return 0;
}