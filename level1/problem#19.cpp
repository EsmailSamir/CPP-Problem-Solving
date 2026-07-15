#include <iostream>
#include <cmath>
using namespace std;
void readDiameter(float &diameter)
{
    cout << "\nEnter Diameter: ";
    cin >> diameter;
    while (cin.fail() || diameter <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter Diameter: ";
        cin >> diameter;
    }
}
float calculateCircleArea(const float diameter)
{
    const float PI = acos(-1);
    float circleArea = PI * pow(diameter, 2) / 4;
    return circleArea;
}
void printCircleArea(const float circleArea)
{
    cout << "=======================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float diameter;
    readDiameter(diameter);
    printCircleArea(calculateCircleArea(diameter));
    return 0;
}