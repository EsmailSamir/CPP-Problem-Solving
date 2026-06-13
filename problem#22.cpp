#include <iostream>
#include <cmath>
using namespace std;
void readTriangle(float &triangleSide, float &base)
{
    cout << "Enter TriangleSide: ";
    cin >> triangleSide;
    cout << "Enter Base : ";
    cin >> base;
    while (cin.fail() || triangleSide <= 0 || base <= 0 
    || (2 * triangleSide <= base))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter TriangleSide: ";
        cin >> triangleSide;
        cout << "Enter Base: ";
        cin >> base;
    }
}
float calculateCircleArea(const float &triangleSide, const float &base)
{
    const float PI = acos(-1);
    float circleArea = ((PI * pow(base, 2)) / 4) 
    * (((2 * triangleSide) - base) / ((2 * triangleSide) + base));
    return circleArea;
}
void printCircleArea(float circleArea)
{
    cout << "=======================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float triangleSide, base;
    readTriangle(triangleSide, base);
    printCircleArea(calculateCircleArea(triangleSide, base));
    return 0;
}