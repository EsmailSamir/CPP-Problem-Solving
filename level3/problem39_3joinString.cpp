#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;
void failInput()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
char readAgain()
{
    char again = ' ';
    cout << "\n==========================\n"
         << "Do you Want To Add More:\n"
         << "(n)NO, (y)YES : ";
    cin >> again;
    again = tolower(again);
    while (cin.fail() ||
           (again != 'n' && again != 'y'))
    {
        if (cin.fail())
            failInput();
        cout << "\nEnter Only[n, y]\n"
             << "(n)NO, (y)YES : ";
        cin >> again;
        again = tolower(again);
    }
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return again;
}

vector<string> readStringToVector()
{
    vector<string> tokens;
    string word;
    do
    {
        do
        {
            cout << "\nEnter Word: \n";
            getline(cin, word);
            if (cin.fail())
                failInput();
        } while (cin.fail() || word.empty());
        tokens.push_back(word);
    } while (readAgain() == 'y');
    return tokens;
}

string getDelimiter()
{
    string delimiter;
    do
    {
        cout << "\nEnter The Delimiter:";
        getline(cin, delimiter);
        if (cin.fail())
            failInput();
    } while (cin.fail() || delimiter.empty());
    return delimiter;
}

size_t countTotalLength(vector<string> &tokens,
                        const string &delimiter)
{
    if (tokens.empty())
        return 0;
    size_t tLength = 0;
    for (const string &token : tokens)
    {
        tLength += token.length();
    }
    tLength += delimiter.length() * (tokens.size() - 1);
    return tLength;
}

string makeStringWithTokensAndDelimiter(
    vector<string> &tokens,
    const string &delimiter)
{
    if (tokens.empty())
        return "";
    string text = "";
    const size_t tLength = countTotalLength(tokens, delimiter);
    text.reserve(tLength);
    for (size_t i = 0; i < tokens.size() - 1; i++)
    {
        text += tokens[i];
        text += delimiter;
    }
    text += tokens[tokens.size() - 1];
    return text;
}

int main()
{
    vector<string> tokens = readStringToVector();
    const string delimiter = getDelimiter();
    const string text = makeStringWithTokensAndDelimiter(
        tokens, delimiter);
    cout << "\n========================\n"
         << "Vector After Join = \n{"
         << text << "}\n";
    return 0;
}