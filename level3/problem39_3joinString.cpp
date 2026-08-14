#include <iostream>
#include <string>
#include <limits>
#include <vector>
using namespace std;
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
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
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
        cout << "\nEnter Word: \n";
        getline(cin, word);
        while (cin.fail() || word.empty())
        {
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            cout << "\nEnter Word: \n";
            getline(cin, word);
        }
        tokens.push_back(word);
    } while (readAgain() == 'y');
    return tokens;
}
string getDelimiter()
{
    string delimiter;
    cout << "\nEnter The Delimiter:";
    getline(cin, delimiter);
    return delimiter;
}
size_t countTotalLength(const vector<string> &tokens,
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
    const vector<string> &tokens,
    const string &delimiter)
{
    if (tokens.empty())
        return "";
    string text = "";
    size_t tLength = countTotalLength(tokens, delimiter);
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
    const vector<string> tokens = readStringToVector();
    const string delimiter = getDelimiter();
    const string text = makeStringWithTokensAndDelimiter(
        tokens, delimiter);
    cout << "\n========================\n"
         << "Vector After Join = \n{"
         << text << "}\n";
    return 0;
}