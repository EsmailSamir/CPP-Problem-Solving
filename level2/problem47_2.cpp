#include <iostream>
#include <cmath>
using namespace std;
float readNumber()
{
    float number;
    cout << "\n-Function For Round-\n\n"
         << "Enter A Float Number: ";
    cin >> number;
    while (cin.fail() || number < -10000 || 10000 < number)
    {
        cin.clear();
        cin.ignore(100000000, '\n');
        cout << "Enter A Numeric Value [-10,000, 10,000]\n"
             << "Enter A Float Number: ";
        cin >> number;
    }
    return number;
}
int myRoundFunction(float number)
{
    number *= 10;
    int numberRound = int(number);
    if (numberRound % 10 > 4)
        numberRound = numberRound / 10 + 1;
    else if (numberRound % 10 < -4)
        numberRound = numberRound / 10 - 1;
    else
        numberRound /= 10;
    return numberRound;
}
void printResult(float numberRound, float number)
{
    cout << "\n=============================\n"
         << "My Round Result : " << numberRound << '\n'
         << "C++ Round Result: " << round(number) << '\n';
}
int main()
{
    float number = readNumber();
    printResult(myRoundFunction(number), number);
    return 0;
}