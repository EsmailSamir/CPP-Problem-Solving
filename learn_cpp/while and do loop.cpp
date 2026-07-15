#include <iostream>
using namespace std;
short int num_in_range(short int from, short int to)
{
    short int number;
    cout << "enter your number: ";
    cin >> number;
    while (number <= from || to <= number)
    {
        cout << "__\"Wrong number\"__" << "\n"
             << "Just enter number between "
             << from << " and " << to << "\n"
             << "Try another number: ";
        cin >> number;
    }
    return number;
}
short int num_not_in_range(short int from, short int to)
{
    short int number;
    do
    {
        cout << "Enter your number: ";
        cin >> number;
    } while (from <= number && number <= to);
    return number;
}
int main()
{
    short int from, to;
    cout << "range start from : ";
    cin >> from;
    cout << "range will end to: ";
    cin >> to;
    cout << "----------------------\n";
    /*short int accepted_number = num_in_range(from, to);
    cout << "---------------------------\n";
    cout << "Number: " << accepted_number
    << " is accepted.";*/
    short int not_accepted_number = num_not_in_range(from, to);
    cout << "Number: " << not_accepted_number << " is not in range.";
    return 0;
}