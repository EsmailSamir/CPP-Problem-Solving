#include <iostream>
using namespace std;
enum enColor
{
    red = 1,
    blue = 2,
    green = 3,
    yellow = 4
};
int main()
{
    cout << " choose the screen color from:\n"
         << " red    = 1\n"
         << " blue   = 2\n"
         << " green  = 3\n"
         << " yellow = 4\n"
         << " I choose number: ";
    short int c;
    enColor color;
    cin >> c;
    color = enColor(c);
    switch (color)
    {
    case (enColor::red):
        system("color 4F");
        cout << " you chose red.";
        break;
    case (enColor::blue):
        system("color 1F");
        cout << " you chose blue.";
        break;
    case (enColor::green):
        system("color 2F");
        cout << " you chose green.";
        break;
    case (enColor::yellow):
        system("color 6F");
        cout << " you chose yellow.";
        break;
    default:
        system("color 4F");
        break;
    }
    return 0;
}