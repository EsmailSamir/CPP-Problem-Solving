#include <iostream>
#include <cmath>
using namespace std;
void readTriangle(float &a, float &b, float &c)
{
    cout << " Enter Sideangle Length (A) = ";
    cin >> a;
    cout << " Enter Sideangle Length (B) = ";
    cin >> b;
    cout << " Enter Sideangle Length (C) = ";
    cin >> c;
    while (cin.fail() || a <= 0 || b <= 0 || c <= 0 
           || (a + b) <= c || (a + c) <= b || (b + c) <= a)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value\n"
             << "Any Two Triangleside Should Be " 
             << "Bigger Than Third Trangle Side";
        cout << " Enter Sideangle (A) = ";
        cin >> a;
        cout << " Enter Sideangle (B) = ";
        cin >> b;
        cout << " Enter Sideangle (C) = ";
        cin >> c;
    }
}
float calculateCircleArea(const float a, const float b, const float c)
{
    const float PI = acos(-1);
    float semiPrimeter = (a + b + c) / 2;
    float p = semiPrimeter;
    float circleArea = PI * pow(((a * b * c)
     / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
    return circleArea;
}
void printCircleArea(const float &circleArea)
{
    cout << "=============================\n"
         << "Circle Area = " << circleArea << '\n';
}
int main()
{
    float a, b, c;
    readTriangle(a, b, c);
    printCircleArea(calculateCircleArea(a, b, c));
    return 0;
}