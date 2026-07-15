#include <iostream>
#include <string>
using namespace std;
int main()
{
    string st1 = "43.22";
    int n1 = 20;
    double n2 = 33.5;
    float n3 = 55.23;
    // switching:
    int s1 = stoi(st1);
    float s2 = stof(st1);
    double s3 = stod(st1);

    string d1 = to_string(n1);

    string r1 = to_string(n2);

    string a1 = to_string(n3);
    int a2 = int(n3);
    cout << "(" << s1 << ")" << "__" << s2 << "__" << s3 << "\n"
         << d1 << "\n"
         << r1 << "\n"
         << a1 << "__" << a2 << "\n";
    return 0;
}