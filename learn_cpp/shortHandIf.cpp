#include <iostream>
using namespace std;
int main()
{
    short number;
    string result;
    cout << "Enter Number: ";
    cin >> number;
    result = (number > 0) ? "Positive" : "Negative";
    cout << result << '\n';

    (number == 0) ? cout << "zero" : (number > 0) ? cout << "Positive"
                                                          : cout << "Negative";

    return 0;
}