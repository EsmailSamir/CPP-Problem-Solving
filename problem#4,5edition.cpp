#include <iostream>
using namespace std;
struct stInfo
{
    short int age;
    bool license;
    bool recommendation;
};
stInfo readUserInfo()
{
    stInfo stUserInfo;
    cout << "(1)Enter your age: ";
    cin >> stUserInfo.age;
    cout << "\n(2)Do You Have A Driver license?\n"
         << "          (1)YES, (0)NO : ";
    cin >> stUserInfo.license;
    cout << "\n(3)Do You Have A Recommendation?\n"
         << "          (1)YES, (0)NO : ";
    cin >> stUserInfo.recommendation;
    return stUserInfo;
}
bool decision(stInfo stUserInfo)
{
    return (stUserInfo.recommendation || (stUserInfo.age > 21 && stUserInfo.license));
}
void printInfo(stInfo stUserInfo)
{
    cout << "=================================\n";
    if (decision(stUserInfo))
    {
        cout << "----- Hired";
    }
    else
        cout << "-- Rejected";
}
int main()
{
    printInfo(readUserInfo());
    return 0;
}