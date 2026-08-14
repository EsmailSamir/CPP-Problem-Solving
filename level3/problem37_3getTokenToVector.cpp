#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;
string readText()
{
    string text;
    cout << "Enter Text: \n";
    if (!getline(cin, text))
    {
        cin.clear();
        cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            L'\n');
        cout << "Input Is Canceled!...\n";
    }
    return text;
}
void getTokenToVectorFromText(const string &text,
                              vector<string> &vTokenInText)
{
    string temp = "";
    cout << "\nThe Tokens In String:\n";
    for (size_t i = 0; i < text.length(); i++)
    {
        if (!isspace(text[i]))
        {
            temp += text[i];
        }
        else if (isspace(text[i]) && !temp.empty())
        {
            vTokenInText.push_back(temp);
            temp.clear();
        }
    }
    if (!temp.empty())
        vTokenInText.push_back(temp);
}
void printTokenFromVector(const vector<string> &vTokenInText)
{
    for (const string &token : vTokenInText)
    {
        cout << token << '\n';
    }
}
int main()
{
    vector<string> vTokenInText;
    getTokenToVectorFromText(readText(), vTokenInText);
    printTokenFromVector(vTokenInText);
    cout << "\n\nCount Of Words In The String = "
         << vTokenInText.size();
    return 0;
}