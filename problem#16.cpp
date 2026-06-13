#include <iostream>
#include <cmath>
using namespace std;
void readlength(float &height, float &diagonal)
{
    cout << "\nEnter Height: ";
    cin >> height;
    cout << "Enter diagonal : ";
    cin >> diagonal;
    while (cin.fail() || height <= 0 || diagonal <= 0 || diagonal <= height)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Enter Height: ";
        cin >> height;
        cout << "Enter diagonal: ";
        cin >> diagonal;
    }
}
float calculaterectangle(const float &height, const float &diagonal)
{
    float rectangle = height * sqrt(pow(diagonal, 2) - pow(height, 2));
    return rectangle;
}
void printrectangle(float rectangle)
{
    cout << "=======================\n"
         << "Rectangle = " << rectangle << '\n';
}
int main()
{
    float height, diagonal;
    readlength(height, diagonal);
    printrectangle(calculaterectangle(height, diagonal));
    return 0;
}