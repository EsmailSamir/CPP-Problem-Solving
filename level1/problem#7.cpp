#include <iostream>
using namespace std;
float originNum()
{
    float numBefor;
    cout << "Enter The Number: ";
    cin >> numBefor;
    return numBefor;
}
void halfNum(float numBefor)
{
    float half_num = numBefor / 2.0;
    cout << "==========================\n"
         << "Half Of Number = " << half_num;
}
int main()
{
    halfNum(originNum());
    return 0;
}