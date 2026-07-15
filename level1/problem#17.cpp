#include <iostream>
using namespace std;
void readlength(float &height, float &base)
{
    cout << "Enter base : ";
    cin >> base;
    cout << "Enter Height: ";
    cin >> height;
    while (cin.fail() || height <= 0 || base <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter Height: ";
        cin >> height;
    }
}
float calculatetriangle(const float &height, const float &base)
{
    float triangle = height * base / 2;
    return triangle;
}
void printtriangle(float triangle)
{
    cout << "=======================\n"
         << "Triangle Area = " << triangle << '\n';
}
int main()
{
    float height, base;
    readlength(height, base);
    printtriangle(calculatetriangle(height, base));
    return 0;
}