#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;
const string fileName = "clients.txt", separator = " , ";
struct stClientInfo
{
    string name;
    string phone;
    string accountNum;
    string pinCode;
    float balance;
};
enum enmainChoise
{
    enPrintList = 1,
    enAddNewClient = 2,
    enDeleteClient = 3,
    enUpdateClientInfo = 4,
    enFindClient = 5,
    enTransactions = 6,
    enExit = 7
};
enum enTransactionsChoise
{
    enDeposit = 1,
    enWithdraw = 2,
    enTotalBalance = 3,
    enGoToMainMenu = 4
};

string readAccountNum()
{
    string accNum = "";
    cout << "\nEnter Account Number: ";
    getline(cin >> ws, accNum);
    return accNum;
}
bool searchInVector(const vector<stClientInfo> &vClients,
                    const string &accNum, size_t &posOfClient)
{
    for (size_t i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNum == accNum)
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
bool fillVectorFromFile(vector<stClientInfo> &vClients,
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
            vClients.push_back(convertVectorToStruct(vLineRecord));
        }
        myFile.close();
        return true;
    }
    return false;
}
void printList(const vector<stClientInfo> &vClients)
{
    string count = '(' + to_string(vClients.size()) + ") Client";
    if (vClients.size() != 1)
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
    for (const stClientInfo &client : vClients)
    {
        cout << "\n| " << left << setw(15) << client.accountNum
             << "| " << left << setw(10) << client.pinCode
             << "| " << left << setw(30) << client.name
             << "| " << left << setw(15) << client.phone
             << "| " << left << setw(10) << client.balance << '|';
    }
    cout << "\n|-----------------------------------------------------------------------------------------|\n";
}
void printResultOfSearch(const vector<stClientInfo> &vClients,
                         const size_t posOfClient)
{
    cout << "\nThe Following Are The Client Details :\n"
         << "\nAccount Num : " << vClients[posOfClient].accountNum
         << "\nPin Code    : " << vClients[posOfClient].pinCode
         << "\nClient Name : " << vClients[posOfClient].name
         << "\nPhone Num   : " << vClients[posOfClient].phone
         << "\nBalance     : " << vClients[posOfClient].balance;
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
void updateClient(const stClientInfo &client,
                  const size_t posOfClient,
                  vector<stClientInfo> &vClients)
{
    vClients[posOfClient].pinCode = client.pinCode;
    vClients[posOfClient].name = client.name;
    vClients[posOfClient].phone = client.phone;
    vClients[posOfClient].balance = client.balance;
}
void deleteClient(vector<stClientInfo> &vClients,
                  const size_t posOfClient)
{
    vClients.erase(vClients.begin() + posOfClient);
}
bool reFillFileFromNewVector(vector<stClientInfo> &vClients,
                             const string &fileName, const string &separator)
{
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (myFile.is_open())
    {
        for (const stClientInfo &client : vClients)
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
void addNewClients(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    size_t posOfClient = 0;
    cout << "\n===========================================\n"
         << "            Add New Clients Screen"
         << "\n===========================================\n";
    do
    {
        client.accountNum = readAccountNum();
        if (searchInVector(vClients, client.accountNum, posOfClient))
        {
            do
            {
                cout << "\nThis Account Is Already Here\n"
                     << "Choose Another Account Number\n";
                client.accountNum = readAccountNum();
            } while (searchInVector(vClients, client.accountNum, posOfClient));
        }
        client = readClientInfo(client.accountNum);
        vClients.push_back(client);
        if (reFillFileFromNewVector(vClients, fileName, separator))
            cout << "\nThis New Client Has Been Added Successfuly.";
        else
            cout << "\nThis File Can Not Open...";
        cout << "Do you Want To Add Another Client ?";
    } while (wantToDoThing());
}
void deleteClientInfo_main(vector<stClientInfo> &vClients)
{
    size_t posOfClient = 0;
    string accNum = readAccountNum();
    cout << "\n===========================================\n"
         << "               Delete Client Screen"
         << "\n===========================================\n";
    if (searchInVector(vClients, accNum, posOfClient))
    {
        printResultOfSearch(vClients, posOfClient);
        cout << "\n\nDo You Want To Delete This Client ?\n"
             << "(n)No, (y)Yes : ";
        if (wantToDoThing())
        {
            deleteClient(vClients, posOfClient);
            if (reFillFileFromNewVector(vClients, fileName, separator))
                cout << "\nThe Client Has Been Deleted Successfully.";
            else
                cout << "This File Can Not Open...";
        }
        else
            cout << "\nThis Client Is Still In File.";
    }
    else
        cout << "\nClient With Account Number ("
             << accNum << ") Is Not Found.\n";
}
void updateClientInfo_main(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    size_t posOfClient = 0;
    cout << "\n===========================================\n"
         << "            Update Client Info Screen"
         << "\n===========================================\n";
    string accNum = readAccountNum();
    if (searchInVector(vClients, accNum, posOfClient))
    {
        printResultOfSearch(vClients, posOfClient);
        cout << "\n\nDo You Want To Update This Client Information?\n"
             << "(n)No, (y)Yes : ";
        if (wantToDoThing())
        {
            client = readClientInfo(accNum);
            updateClient(client, posOfClient, vClients);
            if (reFillFileFromNewVector(vClients, fileName, separator))
                cout << "\nThis Client Has Been Updated Successfully.";
            else
                cout << "This File Can Not Open...";
        }
        else
            cout << "\nThis Client Is Still In File As Same.";
    }
    else
        cout << "\nClient With Account Number ("
             << accNum << ") Is Not Found.\n";
}
void findClient(vector<stClientInfo> &vClients)
{
    size_t posOfClient = 0;
    cout << "\n===========================================\n"
         << "               Find Client Screen"
         << "\n===========================================\n";
    string accNum = readAccountNum();
    if (searchInVector(vClients, accNum, posOfClient))
        printResultOfSearch(vClients, posOfClient);
    else
        cout << "\nClient With Account Number ("
             << accNum << ") Is Not Found.\n";
}
void deposit(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    size_t posOfClient = 0;
    float depositAmount = 0;
    client.accountNum = readAccountNum();
    if (searchInVector(vClients, client.accountNum, posOfClient))
    {
        printResultOfSearch(vClients, posOfClient);
        cout << "\n===========================================\n"
             << "              Deposit Screen"
             << "\n===========================================\n"
             << "Enter Deposit Amount: ";
        cin >> depositAmount;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nEnter A Numeric Value For Deposit Amount Amount: ";
            cin >> depositAmount;
        }
        cout << "Are You Sure You Want Perform This Transaction (y,n) ? ";
        if (wantToDoThing())
        {
            vClients[posOfClient].balance += depositAmount;
            if (reFillFileFromNewVector(vClients, fileName, separator))
                cout << "\nThis Transaction Is Done.\n"
                     << "And Your New Balance Is: "
                     << vClients[posOfClient].balance;
            else
                cout << "This File Can Not Open.";
        }
        else
            cout << "This Transaction Is Fail.\n"
                 << "And Your Balance Is Same: "
                 << vClients[posOfClient].balance;
    }
    else
        cout << "\nClient With Account Number ("
             << client.accountNum << ") Is Not Found.\n"
             << "Please Enter Again";
}
void withdraw(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    size_t posOfClient = 0;
    float withdrawAmount = 0;
    client.accountNum = readAccountNum();
    if (searchInVector(vClients, client.accountNum, posOfClient))
    {
        cout << "\n===========================================\n"
             << "              Withdraw Screen"
             << "\n===========================================\n";
        printResultOfSearch(vClients, posOfClient);
        cout << "\n\nEnter Withdraw Amount: ";
        cin >> withdrawAmount;
        while (cin.fail() || (withdrawAmount > vClients[posOfClient].balance))
        {
            if (!(cin.fail()) && (withdrawAmount > vClients[posOfClient].balance))
            {
                cout << "\nWrong...Can Not Perform This Transaction\n"
                     << "Your Balance(" << vClients[posOfClient].balance
                     << ") Is Less Than This Amount(" << withdrawAmount
                     << ")\nEnter Value <= " << vClients[posOfClient].balance
                     << "\n\nEnter Withdraw Amount: ";
                cin >> withdrawAmount;
            }
            else
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nEnter A Numeric Value For Withdraw Amount : ";
                cin >> withdrawAmount;
            }
        }
        cout << "\nAre You Sure You Want Perform This Transaction (y,n) ? ";
        if (wantToDoThing())
        {
            vClients[posOfClient].balance -= withdrawAmount;
            if (reFillFileFromNewVector(vClients, fileName, separator))
                cout << "\n\nThis Transaction Is Done.\n"
                     << "And Your New Balance Is: "
                     << vClients[posOfClient].balance;
            else
                cout << "This File Can Not Open.";
        }
        else
            cout << "This Transaction Is Fail.\n"
                 << "And Your Balance Is Same: "
                 << vClients[posOfClient].balance;
    }
    else
        cout << "\nClient With Account Number ("
             << client.accountNum << ") Is Not Found.\n"
             << "Please Enter Again";
}
double countTotalBalances(const vector<stClientInfo> &vClients)
{
    double totalBalances = 0;
    for (const stClientInfo &client : vClients)
    {
        totalBalances += client.balance;
    }
    return totalBalances;
}
void proccTransactions(vector<stClientInfo> &vClients, const enTransactionsChoise TransactionChoise)
{
    switch (TransactionChoise)
    {
    case enDeposit:
        deposit(vClients);
        break;
    case enWithdraw:
        withdraw(vClients);
        break;
    case enTotalBalance:
        printList(vClients);
        cout << "\t\t\t\tTotal balalnces = "
             << countTotalBalances(vClients);
        break;
    case enGoToMainMenu:
        return;
    }
}
enTransactionsChoise getChoiseFromTransactionsMenu()
{
    short transactionChoise = 0;
    cout << "Choose What Do You Want To Do? [1, 4]? ";
    cin >> transactionChoise;
    while (cin.fail() || cin.peek() != '\n' || transactionChoise < enDeposit || enGoToMainMenu < transactionChoise)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nEnter A Numeric Value From [1 To 4]:\n"
             << "Enter transactionChoise: ";
        cin >> transactionChoise;
    }
    return enTransactionsChoise(transactionChoise);
}
void printTransactionsMenu()
{
    cout << "\n===========================================\n"
         << "          Transactions Menu Screen"
         << "\n===========================================\n"
         << "\t[1] Deposit.\n"
         << "\t[2] Withdraw.\n"
         << "\t[3] Total Balance.\n"
         << "\t[4] Go To Main Menu.\n"
         << "===========================================\n";
}
void proccMainChoise(vector<stClientInfo> &vClients, const enmainChoise mainChoise)
{
    string accNum = "";
    enTransactionsChoise transactionChoise;
    switch ((mainChoise))
    {
    case enPrintList:
        printList(vClients);
        break;
    case enAddNewClient:
        addNewClients(vClients);
        break;
    case enDeleteClient:
        deleteClientInfo_main(vClients);
        break;
    case enUpdateClientInfo:
        updateClientInfo_main(vClients);
        break;
    case enFindClient:
        findClient(vClients);
        break;
    case enTransactions:
        do
        {
            system("cls");
            printTransactionsMenu();
            transactionChoise = getChoiseFromTransactionsMenu();
            proccTransactions(vClients, transactionChoise);
            if (transactionChoise != enGoToMainMenu)
            {
                cout << "\n\nPress Any Key To Go Back To Transaction Menu";
                system("pause>0");
            }
        } while (transactionChoise != enGoToMainMenu);
        break;
    case enExit:
        cout << "\nThank You For Using Our Bank.\n";
        break;
    }
}
enmainChoise getChoiseFromMainMenu()
{
    short mainChoise = 0;
    cout << "Choose What Do You Want To Do? [1, 7]? ";
    cin >> mainChoise;
    while (cin.fail() || cin.peek() != '\n' || mainChoise < enPrintList || enExit < mainChoise)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nEnter A Numeric Value From [1 To 7]:\n"
             << "Enter mainChoise: ";
        cin >> mainChoise;
    }
    return enmainChoise(mainChoise);
}
void printMainMenu()
{
    cout << "===========================================\n"
         << "              Main Menu Screen\n"
         << "===========================================\n"
         << "\t[1] Show Client List.\n"
         << "\t[2] Add New Client.\n"
         << "\t[3] Delete Client.\n"
         << "\t[4] Update Client Info.\n"
         << "\t[5] Find  Client .\n"
         << "\t[6] Transactions .\n"
         << "\t[7] Exit.\n"
         << "===========================================\n";
}
int main()
{
    vector<stClientInfo> vClients;
    enmainChoise mainChoise;
    if (fillVectorFromFile(vClients, fileName, separator))
    {
        do
        {
            system("cls");
            printMainMenu();
            mainChoise = getChoiseFromMainMenu();
            proccMainChoise(vClients, mainChoise);
            if (mainChoise != enTransactions && mainChoise != enExit)
            {
                cout << "\nEnter Any Key To Go To Main Menu";
                system("pause>0");
            }
        } while (mainChoise != enExit);
    }
    else
        cout << "\nThis File Can Not Open...\n";
    return 0;
}