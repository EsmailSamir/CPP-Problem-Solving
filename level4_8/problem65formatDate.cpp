#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stDate
{
    short year;
    short month;
    short day;
};
vector<string> splitString(string S1, string Delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord; // define a string variable
    // use find() function to get the position of the delimiters
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }
    return vString;
}
stDate stringToDate(string DateString)
{
    stDate Date;
    vector<string> vDate;
    vDate = splitString(DateString, "/");
    Date.day = stoi(vDate[0]);
    Date.month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);
    return Date;
}
string readStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}
void printFormatsDate(stDate date)
{
    cout << "============================================\n"
         << "Formats Of date:\n"
         << date.day << '/' << date.month << '/' << date.year << '\n'
         << date.year << '/' << date.day << '/' << date.month << '\n'
         << date.month << '/' << date.day << '/' << date.year << '\n'
         << date.year << '-' << date.day << '-' << date.month << '\n'
         << date.day << '-' << date.month << '-' << date.year << '\n';
}
int main()
{
    string dateString = readStringDate("\nPlease Enter Date: dd/mm/yyyy? ");
    stDate date = stringToDate(dateString);
    printFormatsDate(date);
    cout << "Day: " << date.day << ", Month: " << date.month << ", Year: " << date.year;
    return 0;
}