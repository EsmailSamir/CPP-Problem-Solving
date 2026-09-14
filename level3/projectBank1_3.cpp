#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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
short menu()
{
    short choise = 0;
    cout << "===========================================\n"
         << "              Main Menu Screen            \n"
         << "===========================================\n"
         << "\t[1] Show Client List.\n"
         << "\t[2] Add New Client.\n"
         << "\t[3] Delete Client.\n"
         << "\t[4] Update Client Info.\n"
         << "\t[5] Find  Client .\n"
         << "\t[6] Exit.\n"
         << "===========================================\n"
         << "Choose What Do You Want To Do? [1, 6]? ";
    cin >> choise;
    while (cin.fail() || cin.peek() != '\n' || choise < 1 || 6 < choise)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nEnter A Numeric Value[1, 6]:\n"
             << "Enter choise: ";
        cin >> choise;
    }
    cout << "\n===========================================\n";
    return choise;
}
string readAccountNum()
{
    string accNum = "";
    cout << "\nEnter Account Number: ";
    getline(cin >> ws, accNum);
    return accNum;
}
bool searchInVector(const vector<stClientInfo> &vAllClients,
                    const string &accNum, size_t &posOfClient)
{
    for (size_t i = 0; i < vAllClients.size(); i++)
    {
        if (vAllClients[i].accountNum == accNum)
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
bool fillVectorFromFile(vector<stClientInfo> &vAllClients,
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
            vAllClients.push_back(convertVectorToStruct(vLineRecord));
        }
        myFile.close();
        return true;
    }
    return false;
}
void printList(const vector<stClientInfo> &vAllClients, const size_t TotalClients)
{
    string count = '(' + to_string(TotalClients) + ") Client";
    if (TotalClients != 1)
        count += 's';
    cout << '\n'
         << right << setw(50) << count
         << "\n-------------------------------------------------------------------------------------------\n"
         << "| " << left << setw(15) << "Account Number"
         << "| " << left << setw(10) << "Pin Code"
         << "| " << left << setw(30) << "Client Name"
         << "| " << left << setw(15) << "Phone"
         << "| " << left << setw(10) << "Balance" << '|'
         << "\n|-----------------------------------------------------------------------------------------|";
    for (const stClientInfo &client : vAllClients)
    {
        cout << "\n| " << left << setw(15) << client.accountNum
             << "| " << left << setw(10) << client.pinCode
             << "| " << left << setw(30) << client.name
             << "| " << left << setw(15) << client.phone
             << "| " << left << setw(10) << client.balance << '|';
    }
    cout << "\n|-----------------------------------------------------------------------------------------|\n";
}

void printResultOfSearch(const vector<stClientInfo> &vAllClients,
                         const size_t posOfClient)
{
    cout << "\n======================================="
         << "\nThe Following Are The Client Details :"
         << "\nAccount Num : " << vAllClients[posOfClient].accountNum
         << "\nPin Code    : " << vAllClients[posOfClient].pinCode
         << "\nClient Name : " << vAllClients[posOfClient].name
         << "\nPhone Num   : " << vAllClients[posOfClient].phone
         << "\nBalance     : " << vAllClients[posOfClient].balance;
}
bool wantToDoThing()
{
    char want = ' ';
    cin >> want;
    while (cin.fail() || (tolower(want) != 'y' && tolower(want) != 'n'))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "(n)No, (y)Yes : ";
        cin >> want;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (tolower(want) == 'y')
        return true;
    return false;
}
stClientInfo readClientInfo(const string &accNum)
{
    stClientInfo client;
    client.accountNum = accNum;
    do
    {
        cout << "Enter PIN     : ";
        getline(cin, client.pinCode);
    } while (client.pinCode.empty());
    do
    {
        cout << "Enter Name    : ";
        getline(cin, client.name);
    } while (client.name.empty());
    do
    {
        cout << "Enter Phone   : ";
        getline(cin, client.phone);
    } while (client.phone.empty());
    cout << "Enter Balance : ";
    cin >> client.balance;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Balance: ";
        cin >> client.balance;
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return client;
}
void UpdateClient(const stClientInfo &client,
                  const size_t posOfClient,
                  vector<stClientInfo> &vAllClients)
{
    vAllClients[posOfClient].pinCode = client.pinCode;
    vAllClients[posOfClient].name = client.name;
    vAllClients[posOfClient].phone = client.phone;
    vAllClients[posOfClient].balance = client.balance;
}
void deleteClient(vector<stClientInfo> &vAllClients,
                  const size_t posOfClient)
{
    vAllClients.erase(vAllClients.begin() + posOfClient);
}
bool reFillFileFromNewVector(vector<stClientInfo> &vAllClients,
                             const string &fileName, const string &separator)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {
        for (const stClientInfo &client : vAllClients)
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
    const string fileName = "clients.txt", separator = " , ";
    string accNum = "", toContinue = "";
    size_t posOfClient = 0;
    short choise = 0;
    stClientInfo client;
    vector<stClientInfo> vAllClients;
    if (fillVectorFromFile(vAllClients, fileName, separator))
        do
        {
            system("cls");
            choise = menu();
            switch (choise)
            {
            case 1:
                printList(vAllClients, vAllClients.size());
                break;
            case 2:
                client.accountNum = readAccountNum();
                if (searchInVector(vAllClients, client.accountNum, posOfClient))
                {
                    cout << "\nThis Account Is Already Here\n"
                         << "Choose Another Account Number\n";
                    while (searchInVector(vAllClients, client.accountNum, posOfClient))
                    {
                        client.accountNum = readAccountNum();
                    }
                }
                client = readClientInfo(client.accountNum);
                vAllClients.push_back(client);
                if (reFillFileFromNewVector(vAllClients, fileName, separator))
                    cout << "\nThis New Client Has Been Added Successfuly.";
                else
                    cout << "\nThis File Can Not Open...";
                break;
            case 3:
                accNum = readAccountNum();
                if (searchInVector(vAllClients, accNum, posOfClient))
                {
                    printResultOfSearch(vAllClients, posOfClient);
                    cout << "\n\nDo You Want To Delete This Client ?\n"
                         << "(n)No, (y)Yes : ";
                    if (wantToDoThing())
                    {
                        deleteClient(vAllClients, posOfClient);
                        if (reFillFileFromNewVector(vAllClients, fileName, separator))
                            cout << "\nThe Client Has Been Deleted Successfully.";
                        else
                            cout << "This File Can Not Open...";
                    }
                    else
                        cout << "\nThe Client Is Still In File.";
                }
                else
                    cout << "\nClient With Account Number ("
                         << accNum << ") Is Not Found.\n";
                break;
            case 4:
                accNum = readAccountNum();
                if (searchInVector(vAllClients, accNum, posOfClient))
                {
                    client = readClientInfo(accNum);
                    UpdateClient(client, posOfClient, vAllClients);
                    if (reFillFileFromNewVector(vAllClients, fileName, separator))
                        cout << "\nThis Client Has Been Updated Successfully.";
                    else
                        cout << "This File Can Not Open...";
                }
                else
                    cout << "\nClient With Account Number ("
                         << accNum << ") Is Not Found.\n";
                break;
            case 5:
                accNum = readAccountNum();
                if (searchInVector(vAllClients, accNum, posOfClient))
                    printResultOfSearch(vAllClients, posOfClient);
                else
                    cout << "\nClient With Account Number ("
                         << accNum << ") Is Not Found.\n";
                break;
            default:
                cout << "Thank You For Using Our Bank\n";
                break;
            }
            if (choise != 6)
            {
                cout << "\n\nPress Any Key To Continue: ";
                system("pause>0");
            }
        } while (choise != 6);
    else
        cout << "\nThis File Can Not Open...\n";
    return 0;
}