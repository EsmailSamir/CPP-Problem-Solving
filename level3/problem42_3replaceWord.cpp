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

string replaceWordInText(const string &originalText,
                         const string &oldWord,
                         const string &newWord)
{
    bool sameWord = true;
    size_t k = 0;
    string editedText = originalText;
    if (!oldWord.empty())
    {

        for (size_t i = 0; i < editedText.length(); i++)
        {

            if (editedText[i] == oldWord[0])
            {

                k = i;

                if (k + oldWord.length() <= editedText.length())
                {
                    for (size_t j = 0; j < oldWord.length(); j++)
                    {

                        if (editedText[k] != oldWord[j])
                            sameWord = false;
                        k++;
                    }

                    if (sameWord)
                    {
                        editedText.replace(i, oldWord.length(), newWord);
                        (newWord.length() >= 1) ? (i += newWord.length() - 1) : i--;
                    }

                    sameWord = true;
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