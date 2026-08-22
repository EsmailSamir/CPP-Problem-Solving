#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stClientInfo
{
    string name;
    string phone;
    string accountNum;
    string pinCode;
    float balance;
};
string readLineRecord()
{
    string lineRecord = "";
    cout << "Enter The Line Record: \n";
    getline(cin, lineRecord);
    return lineRecord;
}
string readSeparator()
{
    string separator = "";
    cout << "\nEnter The Separator: \n";
    getline(cin, separator);
    return separator;
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
stClientInfo readClientInformationFromVector(
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

void printDataOfClient(const stClientInfo &client)
{
    cout << "Account Num : " << client.accountNum
         << "\nPIN Code    : " << client.pinCode
         << "\nClient Name : " << client.name
         << "\nPhone Num   : " << client.phone
         << "\nAcc Balance : "
         << to_string(client.balance) << '\n';
}
int main()
{
    vector<string> vLineRecord;
    string lineRecord = readLineRecord(),
           separator = readSeparator();
    splitLineToVector(vLineRecord, lineRecord, separator);
    stClientInfo client =
        readClientInformationFromVector(vLineRecord);
    cout << "\n\nThe Following Is The Extracted Client Record:\n\n";
    printDataOfClient(client);
    return 0;
}