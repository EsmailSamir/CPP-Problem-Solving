#include <iostream>
#include <string>
#include <limits>
using namespace std;
void failInput()
{
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

unsigned short readLength(const short from, const short to)
{
    unsigned short length;
    cout << "Enter Length: ";
    cin >> length;
    while (cin.fail() || length < from || to < length)
    {
        failInput();
        cout << "\nEnter A Positive Numeric Value["
             << from << ", " << to << "]:\n"
             << "Enter Length: ";
        cin >> length;
    }
    failInput();
    return length;
}

void readStringToArray(string tokens[], const unsigned short length)
{
    string word;
    for (short i = 0; i < length; i++)
    {
        do
        {
            cout << "\nEnter Word(" << i + 1 << "): \n";
            getline(cin, word);
            if (cin.fail())
                failInput();
        } while (cin.fail() || word.empty());

        tokens[i] = word;
    }
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

size_t countTotalLength(const string tokens[],
                        const unsigned short length,
                        const string &delimiter)
{
    if (length < 1)
        return 0;
    size_t tLength = 0;
    for (short i = 0; i < length; i++)
    {
        tLength += tokens[i].length();
    }
    tLength += delimiter.length() * (length - 1);
    return tLength;
}

string makeStringWithTokensAndDelimiter(
    const string tokens[], const unsigned short length,
    const string &delimiter)
{
    if (length < 1)
        return "";
    string text = "";
    const size_t tLength = countTotalLength(
        tokens, length, delimiter);
    text.reserve(tLength);
    for (size_t i = 0; i < length - 1; i++)
    {
        text += tokens[i];
        text += delimiter;
    }
    text += tokens[length - 1];
    return text;
}

int main()
{
    const unsigned short maxLength = 10;
    const unsigned short length = readLength(1, maxLength);
    string tokens[maxLength];
    readStringToArray(tokens, length);
    const string delimiter = getDelimiter();
    const string text = makeStringWithTokensAndDelimiter(
        tokens, length, delimiter);
    cout << "\n==========================================\n"
         << "Array After Join = \n{"
         << text << "}\n";
    return 0;
}