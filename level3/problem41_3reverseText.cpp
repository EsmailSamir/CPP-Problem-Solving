#include <iostream>
#include <string>
using namespace std;
string readText()
{
    string userText = "";
    cout << "\nEnter Your Text: \n";
    getline(cin, userText);
    return userText;
}
string reverseAllTextWord(const string &userText)
{
    string reveUserText = "";
    reveUserText.reserve(userText.length());
    int j = 0;
    bool isWord = false;
    for (int i = userText.length() - 1; i >= 0; i--)
    {
        if (!isspace(userText[i]))
        {
            if (!isWord)
            {
                j = i;
                isWord = true;
            }
            if (i == 0 && isWord)
                reveUserText += userText.substr(0, j + 1);
        }
        else if (isspace(userText[i]))
        {
            reveUserText += userText[i];
            if (isWord)
            {
                reveUserText += userText.substr(i + 1, j - i);
                isWord = false;
            }
        }
    }
    return reveUserText;
}
int main()
{
    string reveUserText = reverseAllTextWord(readText());
    cout << "\n=================================\n"
         << "The Text After Reverse:\n"
         << reveUserText;
    return 0;
}