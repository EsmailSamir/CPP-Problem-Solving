#include <iostream>
using namespace std;
int main()
{
    int length, num, sum = 0;
    cout << "\nEnter Length: ";
    cin >> length;
    cout << "\n---------------------------------\n";
    for (int i = 1; i <= length; i++)
    {
        cout << "Enter Num [" << i << "] = ";
        cin >> num;
        if (num >= 50)
        {
            continue;
        }
        sum += num;
    }
    cout << "\n--------------------------------\n";
    cout << "Sum All Nums Less Than < 50 = " << sum << "\n";
    return 0;
}