#include <iostream>
#include <cmath>
using namespace std;
float readSquareSide()
{
    float squareSide;
    cout << "Enter The SquareSide: ";
    cin >> squareSide;
    while (cin.fail() || squareSide <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Enter The SquareSide: ";
        cin >> squareSide;
    }
    return squareSide;
}
float calculateCircleArea(const float squareSide)
{
    const float PI = acos(-1);
    float circleArea = PI * pow(squareSide, 2) / 4;
    return circleArea;
}
void printCircleArea(const float circleArea)
{
    cout << "=======================\n"
         << "Circle Area = " << circleArea;
}
int main()
{
    printCircleArea(calculateCircleArea(readSquareSide()));
    return 0;
}