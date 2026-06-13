#include <iostream>
#include <cmath>
using namespace std;
void readSquareSide(float &squareSide)
{
    cout << "\nEnter SquareSide: ";
    cin >> squareSide;
    while (cin.fail() || squareSide <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n";
        cout << "Enter SquareSide: ";
        cin >> squareSide;
    }
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
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float squareSide;
    readSquareSide(squareSide);
    printCircleArea(calculateCircleArea(squareSide));
    return 0;
}