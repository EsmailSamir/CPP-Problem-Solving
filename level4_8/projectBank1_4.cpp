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
    double balance;
    short permission;
};
enum enmainChoice
{
    enPrintList = 1,
    enAddNewClient = 2,
    enDeleteClient = 3,
    enUpdateClientInfo = 4,
    enFindClient = 5,
    enTransactions = 6,
    enManageUsers = 7,
    enLogout = 8
};
enum enTransactionsChoice
{
    enDeposit = 1,
    enWithdraw = 2,
    enTotalBalance = 3,
    enGoToMainMenu = 4
};
enum enPermissions
{
    pAll = -1,
    pPrintList = 1,
    pAddNewClient = 2,
    pDeleteClient = 4,
    pUpdateClient = 8,
    pFindClient = 16,
    pTransactions = 32,
    pManageUsers = 64
};
string readAccountNum()
{
    string accNum = "";
    cout << "Enter Account Number: ";
    getline(cin >> ws, accNum);
    return accNum;
}
string readUserName()
{
    string userName = "";
    cout << "Enter User Name: ";
    getline(cin >> ws, userName);
    return userName;
}
string readPinCode()
{
    string pinCode = "";
    cout << "Enter Pin Code Number: ";
    getline(cin >> ws, pinCode);
    return pinCode;
}
void printCurrentScreen(const string &supject)
{
    cout << "\n===========================================\n"
         << "               " << supject
         << "\n===========================================\n";
}
bool searchInVectorByUserName(const vector<stClientInfo> &vClients,
                              const string &userName, size_t &posOfClient)
{
    for (size_t i = 0; i < vClients.size(); i++)
    {
        if (vClients[i].accountNum == userName)
        {
            posOfClient = i;
            return true;
        }
    }
    return false;
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
                if ((m < lineRecord.length()) && (lineRecord[m] != separator[k]))
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
            if (client.balance < 0)
                client.balance = 0;
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
        client.balance = client.permission = 0;
    }
    return client;
}
void seedDefaultUserIfFileEmpty(const string &fileName, const string &separator)
{
    ifstream checkFile(fileName);
    if (!checkFile.is_open() || checkFile.peek() == ifstream::traits_type::eof())
    {
        checkFile.close();
        ofstream outFile(fileName);
        if (outFile.is_open())
        {
            outFile << "Admin" << separator
                    << "1234" << separator
                    << "System Administrator" << separator
                    << "01000000000" << separator
                    << "5000" << separator
                    << "-1" << '\n';
            outFile.close();
        }
    }
}
bool fillVectorFromFile(vector<stClientInfo> &vClients,
                        const string &fileName, const string &separator)
{
    seedDefaultUserIfFileEmpty(fileName, separator);
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
short ReadUserPermissions()
{
    short Permissions = 0;

    cout << "\nDo you want to give full access? (y/n)? ";
    if (wantToDoThing())
        return enPermissions::pAll;

    cout << "\nDo you want to give access to:\n";

    cout << "\nShow Client List (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pPrintList;

    cout << "\nAdd New Client (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pAddNewClient;

    cout << "\nDelete Client (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pDeleteClient;

    cout << "\nUpdate Client Info (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pUpdateClient;

    cout << "\nFind Client (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pFindClient;

    cout << "\nTransactions (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pTransactions;

    cout << "\nManage Users (y/n)? ";
    if (wantToDoThing())
        Permissions = Permissions | enPermissions::pManageUsers;

    return Permissions;
}
bool CheckAccessPermission(short UserPermission, enPermissions RequiredPermission)
{
    if (UserPermission == enPermissions::pAll)
        return true;

    if ((UserPermission & RequiredPermission) == RequiredPermission)
        return true;
    else
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
    while (cin.fail() || cin.peek() != '\n' || client.balance < 0)
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
bool reFillFileFromNewVector(const vector<stClientInfo> &vClients,
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
    do
    {
        if (searchInVector(vClients, readAccountNum(), posOfClient))
        {
            do
            {
                cout << "\nThis Account Is Already Here\n"
                     << "Choose Another Account Number\n";
            } while (searchInVector(vClients, readAccountNum(), posOfClient));
        }
        client = readClientInfo(client.accountNum);
        vClients.push_back(client);
        if (reFillFileFromNewVector(vClients, fileName, separator))
            cout << "\nThis New Client Has Been Added Successfully."
                 << "Do you Want To Add Another Client (n)No, y(Yes) ?";
        else
            cout << "\nThis File Can Not Open...\n";
    } while (wantToDoThing());
}
void deleteClientInfo_main(vector<stClientInfo> &vClients)
{
    size_t posOfClient = 0;
    string accNum = readAccountNum();
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
    double depositAmount = 0;
    client.accountNum = readAccountNum();
    if (searchInVector(vClients, client.accountNum, posOfClient))
    {
        printResultOfSearch(vClients, posOfClient);
        cout << "\n\nEnter Deposit Amount: ";
        cin >> depositAmount;
        while (cin.fail() || cin.peek() != '\n' || depositAmount < 1)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "\nEnter A Numeric Value For Deposit Amount > 0: ";
            cin >> depositAmount;
        }
        cout << "Are You Sure You Want Perform This Transaction (n)No, y(Yes) ? ";
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
            cout << "This Transaction Has Been Canceled.\n"
                 << "And Your Balance Is Same: "
                 << vClients[posOfClient].balance;
    }
    else
        cout << "\nClient With Account Number ("
             << client.accountNum << ") Is Not Found.\n";
}
void withdraw(vector<stClientInfo> &vClients)
{
    stClientInfo client;
    size_t posOfClient = 0;
    double withdrawAmount = 0;
    client.accountNum = readAccountNum();
    if (searchInVector(vClients, client.accountNum, posOfClient))
    {
        printResultOfSearch(vClients, posOfClient);
        cout << "\n\nEnter Withdraw Amount: ";
        cin >> withdrawAmount;
        while (cin.fail() || cin.peek() != '\n' || (withdrawAmount > vClients[posOfClient].balance) || withdrawAmount < 1)
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
        cout << "\nAre You Sure You Want Perform This Transaction (n)No, y(Yes) ? ";
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
            cout << "This Transaction Has Been Canceled.\n"
                 << "And Your Balance Is Same: "
                 << vClients[posOfClient].balance;
    }
    else
        cout << "\nClient With Account Number ("
             << client.accountNum << ") Is Not Found.\n";
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
void proccTransactions(vector<stClientInfo> &vClients,
                       const enTransactionsChoice(TransactionChoice))
{
    switch (TransactionChoice)
    {
    case enDeposit:
        printCurrentScreen("Deposit Screen");
        deposit(vClients);
        break;
    case enWithdraw:
        printCurrentScreen("Withdraw Screen");
        withdraw(vClients);
        break;
    case enTotalBalance:
        printCurrentScreen("Total Balance Screen");
        printList(vClients);
        cout << "\t\t\t\tTotal balances = "
             << countTotalBalances(vClients);
        break;
    case enGoToMainMenu:
        return;
    }
}
void printTransactionsMenu()
{
    cout << "\t[1] Deposit.\n"
         << "\t[2] Withdraw.\n"
         << "\t[3] Total Balance.\n"
         << "\t[4] Go To Main Menu.\n";
}
short getChoiceFromUser(const short(firstChoise), const short(lastChoise))
{
    short userChoice = 0;
    cout << "Choose What Do You Want To Do? [" << firstChoise << " To " << lastChoise << "]? ";
    cin >> userChoice;
    while (cin.fail() || cin.peek() != '\n' || userChoice < firstChoise || lastChoise < userChoice)
    {
        if (cin.fail() || cin.peek() != '\n')
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            cout << "\nEnter A Numeric Value From [" << firstChoise
                 << " To " << lastChoise << "]:\n";
        cout << "Enter User Choice: ";
        cin >> userChoice;
    }
    return userChoice;
}
void transactions(vector<stClientInfo> &vClients)
{
    enTransactionsChoice transactionChoice;
    do
    {
        system("cls");
        printCurrentScreen("Transactions Menu Screen");
        printTransactionsMenu();
        transactionChoice = enTransactionsChoice(getChoiceFromUser(enDeposit, enLogout));
        proccTransactions(vClients, transactionChoice);
        if (transactionChoice != enGoToMainMenu)
        {
            cout << "\n\nPress Any Key To Go Back To Transaction Menu";
            system("pause>0");
        }
    } while (transactionChoice != enGoToMainMenu);
}
short manageUsers(const vector<stClientInfo> &vClients)
{
    short permession = 0;

    return permession;
}
void proccMainChoice(vector<stClientInfo> &vClients,
                     const enmainChoice(mainChoice),
                     short CurrentUserPermission)
{
    switch (mainChoice)
    {
    case enPrintList:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pPrintList))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Print List Screen");
        printList(vClients);
        break;
    case enAddNewClient:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pAddNewClient))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Add New Clients Screen");
        addNewClients(vClients);
        break;
    case enDeleteClient:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pDeleteClient))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Delete Client Screen");
        deleteClientInfo_main(vClients);
        break;
    case enUpdateClientInfo:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pUpdateClient))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Update Client Info Screen");
        updateClientInfo_main(vClients);
        break;
    case enFindClient:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pFindClient))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Find Client Screen");
        findClient(vClients);
        break;
    case enTransactions:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pTransactions))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Transactions Screen");
        transactions(vClients);
        break;
    case enManageUsers:
        if (!CheckAccessPermission(CurrentUserPermission, enPermissions::pManageUsers))
        {
            cout << "\nAccess Denied! You don't have permission to do this.\n";
            break;
        }
        printCurrentScreen("Manage Clients");
        manageUsers(vClients);
        break;
    case enLogout:
        cout << "\nThank You For Using Our Bank.\n";
        break;
    }
}
void printMainMenu()
{
    cout << "\t[1] Show Client List.\n"
         << "\t[2] Add New Client.\n"
         << "\t[3] Delete Client.\n"
         << "\t[4] Update Client Info.\n"
         << "\t[5] Find Client .\n"
         << "\t[6] Transactions .\n"
         << "\t[7] Manage Users.\n"
         << "\t[8] Exit.\n";
}
void mainMenuScreen(short CurrentUserPermission)
{
    vector<stClientInfo> vClients;
    enmainChoice mainChoice;
    fillVectorFromFile(vClients, fileName, separator);
    do
    {
        system("cls");
        printCurrentScreen("Main Menu Screen");
        printMainMenu();
        mainChoice = enmainChoice(getChoiceFromUser(enPrintList, enLogout));
        proccMainChoice(vClients, mainChoice, CurrentUserPermission);
        if (mainChoice != enTransactions && mainChoice != enLogout)
        {
            cout << "\nEnter Any Key To Go To Main Menu";
            system("pause>0");
        }
    } while (mainChoice != enLogout);
}
bool loginUser(const vector<stClientInfo> &vClients, const size_t posOfClient,
               const string &pinCode, stClientInfo &CurrentUser)
{
    if (vClients[posOfClient].pinCode == pinCode)
    {
        CurrentUser = vClients[posOfClient];
        return true;
    }
    else
        return false;
}
int main()
{
    vector<stClientInfo> vClients;
    fillVectorFromFile(vClients, fileName, separator);
    stClientInfo CurrentUser;
    size_t posOfClient = 0;
    do
    {
        system("cls");
        printCurrentScreen("Login Screen");
        if (searchInVectorByUserName(vClients, readUserName(), posOfClient) &&
            (loginUser(vClients, posOfClient, readPinCode(), CurrentUser)))
            mainMenuScreen(CurrentUser.permission);
        else
            cout << "\n\nCan Not Found The User.";
        cout << "\n\nDo You Want To Go To Login Screen(y, n): ";
    } while (wantToDoThing());
    cout << "\n\nProgram Bank Is Exit.\n";
    return 0;
}