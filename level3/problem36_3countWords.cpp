#include <iostream>
#include <string>
#include <cstddef>
#include <limits>
#include <cwctype>
#ifdef _WIN32
// لو إحنا على ويندوز، استدعي الأسلحة التقيلة دي
#include <io.h>
#include <fcntl.h>
#else
// لو إحنا على لينكس أو ماك، استدعي المكتبة القياسية دي
#include <clocale>
#endif
using std::getline;
using std::size_t;
using std::wcin;
using std::wcout;
using std::wstring;
wstring readText()
{
    wstring text;
    wcout << L"Enter Text: \n";
    if (!getline(wcin, text))
    {
        wcin.clear();
        wcin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            L'\n');
        wcout << L"Input Is Canceled!...\n";
    }
    return text;
}
size_t printAllWordInText(const wstring &text)
{
    size_t countWords = 0;
    bool isWord = false;
    wcout << L"\nThe Words In String:\n";
    for (size_t i = 0; i < text.length(); i++)
    {
        if (!iswspace(text[i]))
        {
            if (!isWord)
            {
                countWords++;
                isWord = true;
            }
            wcout << text[i];
        }
        else if (iswspace(text[i]) && isWord)
        {
            wcout << L'\n';
            isWord = false;
        }
    }
    return countWords;
}
int main()
{
#ifdef _WIN32
    // أوامر الويندوز العنيد
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#else
    // أمر لينكس وماك المرن
    setlocale(LC_ALL, "");
#endif
    size_t countWords = printAllWordInText(readText());
    wcout << L"\n\nCount Of Words In The String = " << countWords;
    return 0;
}