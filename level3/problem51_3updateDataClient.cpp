#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
string readAccountNum()
{
    string accNum = "";
    cout << "Enter Account Number: ";
    getline(cin >> ws, accNum);
    return accNum;
}
bool searchInVector(const vector<stClientInfo> &vAccountsLine,
                    const string &accNum, size_t &posOfClient)
{
    for (size_t i = 0; i < vAccountsLine.size(); i++)
    {
        if (vAccountsLine[i].accountNum == accNum)
        {
            posOfClient = i;
            return true;
        }
    }
    return false;
}
void splitLineToVector(vector<string> &vLineRecord,
                       const string &lineRecord,
                       const string &separator)
{
    string temp = "";
    for (size_t i = 0; i < lineRecord.length();)
    {
        if (lineRecord[i] != separator[0])
        {
            temp += lineRecord[i];
            i++;
        }
        else if (lineRecord[i] == separator[0])
        {
            bool same = true;
            size_t m = i;
            for (size_t k = 0; k < separator.length(); k++)
            {
                if (lineRecord[m] != separator[k])
                    same = false;
                else
                    m++;
            }
            if (same)
            {
                i += separator.length();
                vLineRecord.push_back(temp);
                temp.clear();
            }
            else
            {
                temp += lineRecord[i];
                i++;
            }
        }
    }
    vLineRecord.push_back(temp);
}
stClientInfo convertVectorToStruct(
    const vector<string> &vLineRecord)
{
    stClientInfo client;
    if (vLineRecord.size() > 4)
    {
        client.accountNum = vLineRecord[0];
        client.pinCode = vLineRecord[1];
        client.name = vLineRecord[2];
        client.phone = vLineRecord[3];
        try
        {
            client.balance = stof(vLineRecord[4]);
        }
        catch (...)
        {
            client.balance = 0;
        }
    }
    else
    {
        client.accountNum = client.pinCode =
            client.name = client.phone = "";
        client.balance = 0;
    }
    return client;
}
bool fillVectorFromFile(vector<stClientInfo> &vAccountsLine,
                        const string &fileName, const string &separator)
{
    vector<string> vLineRecord;
    string lineRecord;
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        while (getline(myFile, lineRecord))
        {
            if (lineRecord.empty())
                continue;
            vLineRecord.clear();
            splitLineToVector(vLineRecord, lineRecord, separator);
            vAccountsLine.push_back(convertVectorToStruct(vLineRecord));
        }
        myFile.close();
        return true;
    }
    return false;
}
void printResultOfSearch(const vector<stClientInfo> &vAccountsLine,
                         const size_t posOfClient)
{
    cout << "\n==================================="
         << "\nThe Following Are The Client Details :"
         << "\nAccount Num : " << vAccountsLine[posOfClient].accountNum
         << "\nPin Code    : " << vAccountsLine[posOfClient].pinCode
         << "\nClient Name : " << vAccountsLine[posOfClient].name
         << "\nPhone Num   : " << vAccountsLine[posOfClient].phone
         << "\nBalance     : " << vAccountsLine[posOfClient].balance;
}
bool wantToUpdate()
{
    char want = ' ';
    cout << "\nDo You Want To Update This Client ?\n"
         << "(n)No, (y)Yes : ";
    cin >> want;
    while (cin.fail() || (tolower(want) != 'y' && tolower(want) != 'n'))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Do You Want To Update This Client ?\n"
             << "(n)No, (y)Yes : ";
        cin >> want;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (tolower(want) == 'y')
        return true;
    return false;
}
stClientInfo readClientInformation()
{
    stClientInfo client;
    cout << "\n============================\n"
         << "Enter Client Data For Update:\n"
         << "Enter Updated PIN: ";
    getline(cin, client.pinCode);
    cout << "Enter Updated Name: ";
    getline(cin, client.name);
    cout << "Enter Updated Phone: ";
    getline(cin, client.phone);
    cout << "Enter Updated Balance: ";
    cin >> client.balance;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Updated Balance: ";
        cin >> client.balance;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return client;
}
void UpdateClient(const stClientInfo &client,
                  const size_t posOfClient,
                  vector<stClientInfo> &vAccountsLine)
{
    vAccountsLine[posOfClient].pinCode = client.pinCode;
    vAccountsLine[posOfClient].name = client.name;
    vAccountsLine[posOfClient].phone = client.phone;
    vAccountsLine[posOfClient].balance = client.balance;
}
bool reFillFileFromNewVector(vector<stClientInfo> &vAccountsLine,
                             const string &fileName, const string &separator)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {
        for (const stClientInfo &client : vAccountsLine)
        {
            myFile << client.accountNum + separator +
                          client.pinCode + separator +
                          client.name + separator +
                          client.phone + separator +
                          to_string(client.balance) + '\n';
        }
        myFile.close();
        return true;
    }
    return false;
}
int main()
{
    const string fileName = "clients.txt",
                 separator = " , ",
                 accNum = readAccountNum();
    size_t posOfClient;
    vector<stClientInfo> vAccountsLine;
    if (fillVectorFromFile(vAccountsLine, fileName, separator))
    {
        if (searchInVector(vAccountsLine, accNum, posOfClient))
        {
            printResultOfSearch(vAccountsLine, posOfClient);
            if (wantToUpdate())
            {
                stClientInfo updateClient = readClientInformation();
                UpdateClient(updateClient, posOfClient, vAccountsLine);
                if (reFillFileFromNewVector(vAccountsLine, fileName, separator))
                    cout << "\nThe Client Has Been Updated Successfully.";
                else
                    cout << "This File Can Not Open...";
            }
            else
                cout << "\nThe Client Is Still In Vector";
        }
        else
            cout << "\nClient With Account Number ("
                 << accNum << ") Is Not Found.\n";
    }
    else
        cout << "This File Can Not Open";
    return 0;
}