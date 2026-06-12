#include <iostream>
using namespace std;
int main()
{
    int array[] = {13, 26, 38, 44, 52, 69, 74, 87, 98};
    int length = sizeof(array) / sizeof(array[0]);
    int number;
    cout << "\n --------------------------------------------------\n"
            "array[9] = {13, 26, 38, 44, 52, 69, 74, 87, 98}\n\n"
         << "enter any number from array: ";
    cin >> number;
    cout << "----------------------------------------------------\n";
    bool is_found = false;
    for (int i = 0; i < length; i++)
    {
        if (number == array[i])
        {
            cout << "\n"
                 << "found " << array[i] << " in index number: " << i
                 << "\n";
            is_found = true;
            break;
        }
    }
    if (is_found == false)
    {
        cout << "your number " << number << " is not in array.\n";
    }
    return 0;
}