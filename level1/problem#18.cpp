#include <iostream>
#include <cmath>
using namespace std;
void readRadius(float &radius)
{
    cout << "\nEnter Radius: ";
    cin >> radius;
    while (cin.fail() || radius <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Radius: ";
        cin >> radius;
    }
}
float calculatecircleArea(const float radius)
{
    const float PI = acos(-1);
    float circleArea = PI * pow(radius, 2);
    return circleArea;
}
void printcircleArea(const float circleArea)
{
    cout << "=======================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float radius;
    readRadius(radius);
    printcircleArea(calculatecircleArea(radius));
    return 0;
}