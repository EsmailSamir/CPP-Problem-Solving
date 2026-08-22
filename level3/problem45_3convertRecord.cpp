#include <iostream>
#include <string>
#include <limits>
using namespace std;
struct stClientInfo
{
    string name;
    string phone;
    string accountNum;
    string pinCode;
    float balance;
};
stClientInfo readClientInformation()
{
    stClientInfo client;
    cout << "Enter Client Data:\n\n"
         << "Enter Your Account Num: ";
    getline(cin, client.accountNum);
    cout << "Enter Your PIN: ";
    getline(cin, client.pinCode);
    cout << "Enter Your Name: ";
    getline(cin, client.name);
    cout << "Enter Your Phone: ";
    getline(cin, client.phone);
    cout << "Enter Your Balance: ";
    cin >> client.balance;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Your Balance: ";
        cin >> client.balance;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return client;
}
string readDelimiter()
{
    string delimiter = "";
    cout << "\nEnter The Delimiter: \n";
    getline(cin, delimiter);
    return delimiter;
}
string recordDataOfClient(
    const stClientInfo &client,
    const string &delimiter)
{
    return client.accountNum + delimiter +
           client.pinCode + delimiter +
           client.name + delimiter +
           client.phone + delimiter +
           to_string(client.balance);
}
int main()
{
    stClientInfo client = readClientInformation();
    string delimiter = readDelimiter();
    cout << "\n\nClient Record For Saving Is:\n"
         << recordDataOfClient(client, delimiter);
    return 0;
}