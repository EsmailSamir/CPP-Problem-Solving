#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
struct stClientInfo
{
    string name;
    string phone;
    string accountNum;
    string pinCode;
    float balance;
};
void printHeader()
{
    cout << "___________________________________________________________________________________________\n"
         << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(10) << "Pin Code"
         << "| " << left << setw(30) << "Client Name"
         << "| " << left << setw(15) << "Phone"
         << "| " << left << setw(10) << "Balance" << '|'
         << "\n|_________________________________________________________________________________________|\n";
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
void printVectorOfAccounts(const vector<stClientInfo> &vAccountsLine)
{
    for (size_t i = 0; i < vAccountsLine.size(); i++)
    {
        cout << "| " << left << setw(15) << vAccountsLine[i].accountNum
             << "| " << left << setw(10) << vAccountsLine[i].pinCode
             << "| " << left << setw(30) << vAccountsLine[i].name
             << "| " << left << setw(15) << vAccountsLine[i].phone
             << "| " << left << setw(10) << vAccountsLine[i].balance << "|\n";
    }
    cout << "|_________________________________________________________________________________________|\n";
}
int main()
{
    const string fileName = "clients.txt";
    const string separator = " , ";
    printHeader();
    printVectorOfAccounts(fillVectorFromFile(fileName, separator));
    return 0;
}