#include <iostream>
#include <string>
#include <vector>
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
string readAccountNum()
{
    string accNum = "";
    cout << "Enter Account Number: ";
    getline(cin >> ws, accNum);
    return accNum;
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
vector<stClientInfo> fillVectorFromFile(
    const string &fileName, const string &separator)
{
    vector<string> vLineRecord;
    vector<stClientInfo> vAccountsLine;
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
    }
    return vAccountsLine;
}
bool searchInVector(const vector<stClientInfo> &vAccountsLine,
                    const string &accNum, stClientInfo &result)
{
    for (const stClientInfo &client : vAccountsLine)
    {
        if (client.accountNum == accNum)
        {
            result = client;
            return true;
        }
    }
    return false;
}
void printResultOfSearch(const vector<stClientInfo> &vAccountsLine,
                         const string &accNum)
{
    stClientInfo result;
    cout << "\n====================================================\n";
    if (searchInVector(vAccountsLine, accNum, result))
    {
        cout << "The Following Are The Client Details:\n"
             << "Account Num : " << result.accountNum << '\n'
             << "Pin Code    : " << result.pinCode << '\n'
             << "Client Name : " << result.name << '\n'
             << "Phone Num   : " << result.phone << '\n'
             << "Balance     : " << result.balance << endl;
        return;
    }
    cout << "Client With Account Number ("
         << accNum << ") Is Not Found.\n";
}
int main()
{
    const string fileName = "clients.txt",
                 separator = " , ",
                 accNum = readAccountNum();
    vector<stClientInfo> vAccountsLine =
        fillVectorFromFile(fileName, separator);
    printResultOfSearch(vAccountsLine, accNum);
    return 0;
}