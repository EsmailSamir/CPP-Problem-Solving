#include <iostream>
#include <string>
#include <limits>
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
string trimTextFromRight(string text)
{
    int i = text.length() - 1;
    while (i >= 0 && isspace(text[i]))
    {
        i--;
    }
    return text.substr(0, i + 1);
}
string trimTextFromLeft(string text)
{
    int i = 0;
    while (i < text.length() && isspace(text[i]))
    {
        i++;
    }
    return text.substr(i);
}
int main()
{
    string text = readText();
    cout << "String       = \n"
         << text
         << "\nTrim Right = \n"
         << trimTextFromRight(text)
         << "\nTrim Left  = \n"
         << trimTextFromLeft(text)
         << "\nTrim All   = \n"
         << trimTextFromRight(trimTextFromLeft(text));
    return 0;
}