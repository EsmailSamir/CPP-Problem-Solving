#include <iostream>
#include <vector>
using namespace std;
void readNumber(vector<short> &vNumbers, const short from, const short to)
{
    short number;
    bool more;
    do
    {
        cout << "Enter Number: ";
        cin >> number;
        while (cin.fail() || cin.peek() != '\n' || number < from || to < number)
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "\nEnter A Positive Numeric Value["
                 << from << ", " << to << "]:\n"
                 << "Enter Number: ";
            cin >> number;
        }
        vNumbers.push_back(number);
        cout << "Do You Want To Add More?\n"
             << "(Y)Yes, (N)No : ";
        cin >> more;
        while (cin.fail() || cin.peek() != '\n' || more < 0 || 1 < more)
        {
            cin.clear();
            cin.ignore(100000000, '\n');
            cout << "\nEnter A Positive Numeric Value[0, 1]:\n"
                 << "(Y)Yes, (N)No : ";
            cin >> more;
        }
    } while (more);
}
void printVector(vector<short> &vNumbers)
{
    cout << "{";
    for (short &number : vNumbers)
    {
        cout << number << "  ";
    }
    cout << " }";
}
int main()
{
    vector<short> vNumbers;
    readNumber(vNumbers, 1, 1000);
    printVector(vNumbers);
    return 0;
}