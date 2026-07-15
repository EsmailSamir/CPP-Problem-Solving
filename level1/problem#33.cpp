#include <iostream>
using namespace std;
float readGrade()
{
    float grade;
    cout << "Enter The Grade: ";
    cin >> grade;
    while (cin.fail() || grade < 0 || grade > 100)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter A Positive Numeric Value [0:100]\n"
             << "Enter The Grade: ";
        cin >> grade;
    }
    return grade;
}
char proccGrade(float grade)
{
    if (grade >= 90)
        return 'A';
    else if (grade >= 80)
        return 'B';
    else if (grade >= 70)
        return 'C';
    else if (grade >= 60)
        return 'D';
    else if (grade >= 50)
        return 'E';
    else
        return 'F';
}
void printRating(char rating)
{
    cout << "==============================\n"
         << "The Rating Of The Grade Is: " << rating;
}
int main()
{
    printRating(proccGrade(readGrade()));
    return 0;
}