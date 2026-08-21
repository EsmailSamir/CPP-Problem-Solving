#include <iostream>
#include <string>
#include <limits>
using namespace std;
string readText()
{
    string originalText = "";
    cout << "\nEnter Your Text: \n";
    getline(cin, originalText);
    return originalText;
}
string readOldWord()
{
    string oldWord = "";
    cout << "\nEnter Old Word: \n";
    getline(cin, oldWord);
    return oldWord;
}
string readNewWord()
{
    string newWord = "";
    cout << "\nEnter New Word: \n";
    getline(cin, newWord);
    return newWord;
}
bool isMatchCase()
{
    bool match;
    cout << "\nDo you Want Match Cases:\n(0)No, (1)Yes: ";
    cin >> match;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\nDo you Want Match Cases:\n(0)No, (1)Yes: ";
        cin >> match;
    }

    return match;
}
string myReplace(
    const string &text, const size_t start,
    const size_t lengthOfOldWord, const string &newWord)
{
    return text.substr(0, start) + newWord +
           text.substr(start + lengthOfOldWord);
}
string replaceWordInText(const string &originalText,
                         const string &oldWord,
                         const string &newWord)
{
    bool sameWord = true, match = isMatchCase();
    size_t k = 0;
    string editedText = originalText;
    if (!oldWord.empty())
        for (size_t i = 0; i < editedText.length(); i++)
        {
            bool same;
            if (!match)
                same = tolower(editedText[i]) == tolower(oldWord[0]);
            else
                same = editedText[i] == oldWord[0];
            if (same)
            {
                k = i;
                if (k + oldWord.length() <= editedText.length())
                {
                    bool validLeft = (i == 0 || !isalpha(editedText[k - 1]));
                    bool validRight = (i + oldWord.length() == editedText.length() ||
                                       !isalpha(editedText[oldWord.length() + k]));
                    if (validLeft && validRight)
                    {
                        for (size_t j = 0; j < oldWord.length(); j++)
                        {
                            if (match && editedText[k] != oldWord[j])
                                sameWord = false;
                            else if (tolower(editedText[k]) != tolower(oldWord[j]))
                                sameWord = false;
                            k++;
                        }
                    }
                    if (sameWord)
                    {
                        editedText = myReplace(
                            editedText, i, oldWord.length(), newWord);
                        newWord.length() >= 1 ? i += newWord.length() - 1 : i--;
                        sameWord = false;
                    }
                }
            }
        }
    return editedText;
}
int main()
{
    string originalText = readText(),
           oldWord = readOldWord(), newWord = readNewWord();
    string editedText = replaceWordInText(
        originalText, oldWord, newWord);
    cout << "\n=================================\n"
         << "The Text After Replace The Word:\n"
         << editedText;
    return 0;
}