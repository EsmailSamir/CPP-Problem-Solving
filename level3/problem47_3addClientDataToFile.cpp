#include <iostream>
#include <string>
#include <limits>
#include <fstream>
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
    cout << "Enter New Client Data:\n\n"
         << "Enter Account Num: ";
    getline(cin >> ws, client.accountNum);
    cout << "Enter PIN: ";
    getline(cin, client.pinCode);
    cout << "Enter Name: ";
    getline(cin, client.name);
    cout << "Enter Phone: ";
    getline(cin, client.phone);
    cout << "Enter Balance: ";
    cin >> client.balance;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\"Wrong\", Invalid Value...\n"
             << "Enter Balance: ";
        cin >> client.balance;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return client;
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
bool getMore()
{
    char more = ' ';
    cout << "\ndo you want to add more clients\n"
         << "(n)No, (y)Yes : ";
    cin >> more;
    while (cin.fail() || (tolower(more) != 'y' && tolower(more) != 'n'))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\ndo you want to add more clients\n"
             << "(n)No, (y)Yes : ";
        cin >> more;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return tolower(more) == 'y';
}
bool RecordDataToFile(const string &delimiter, fstream &clientsFile)
{
    if (clientsFile.is_open())
    {
        stClientInfo client = readClientInformation();
        clientsFile << recordDataOfClient(client, delimiter)
                    << '\n';
        return true;
    }
    return false;
}
int main()
{
    string delimiter = " , ";
    size_t i = 1;
    fstream clientsFile;
    clientsFile.open("clients.txt", ios::out | ios::app);
    do
    {
        if (!RecordDataToFile(delimiter, clientsFile))
        {
            cout << "Can Not Record To File";
            break;
        }
        cout << "\nClient Number (" << i << ") Added Successfully\n";
        i++;
    } while (getMore());
    clientsFile.close();
    return 0;
}