#include <iostream>
using namespace std;
void readlength(float &height, float &width)
{
    cout << "\nEnter Height: ";
    cin >> height;
    cout << "Enter Width : ";
    cin >> width;
    while (cin.fail() || height <= 0 || width <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Enter Height: ";
        cin >> height;
        cout << "Enter Width: ";
        cin >> width;
    }
}
float calculaterectangle(const float &height, const float &width)
{
    float rectangle = height * width;
    return rectangle;
}
void printrectangle(float rectangle)
{
    cout << "=======================\n"
         << "Rectangle = " << rectangle << '\n';
}
int main()
{
    float height, width;
    readlength(height, width);
    printrectangle(calculaterectangle(height, width));
    return 0;
}