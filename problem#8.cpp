#include <iostream>
using namespace std;
float readDegree()
{
    float degree;
    cout << "\nEnter your degree: ";
    cin >> degree;
    return degree;
}
bool proccDegree(float degree)
{
    return (degree >= 50);
}
void printResult(float degree)
{
    cout << "#########################\n";
    if (proccDegree(degree))
    {
        cout << "--------- PASS\n";
    }
    else
        cout << "--------- Fail\n";
}
int main()
{
    printResult(readDegree());
    return 0;
}