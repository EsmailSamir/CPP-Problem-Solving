#include <iostream>
#include <string>
using namespace std;
string readText()
{
    string originalText = "";
    cout << "\nEnter Your Text: \n";
    getline(cin, originalText);
    return originalText;
}
string copyTextWithoutPunctuations(const string &originalText)
{
    string copyText = "";
    copyText.reserve(originalText.length());
    for (size_t i = 0; i < originalText.length(); i++)
    {
        if (!ispunct(originalText[i]))
            copyText += originalText[i];
    }
    return copyText;
}
int main()
{
    string originalText = readText(),
           copyText = copyTextWithoutPunctuations(originalText);
    cout << "\n=================================\n"
         << "The Original Text:\n"
         << originalText
         << "\n\nThe Text Without Punctuations:\n"
         << copyText << endl;
    return 0;
}