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
    wcout << L"Enter Text: ";
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
wstring convertFirstLetterToLowercase(wstring &text)
{
    bool firstLetter = true;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (!iswspace(text[i]) && firstLetter)
            text[i] = towlower(text[i]);
        firstLetter = iswspace(text[i]);
    }
    return text;
}
void printLetterAfterConvert(const wstring &text)
{
    wcout << L"\nLetter After Convert First Letter To lowercase:\n"
          << L"=================================================\n"
          << text << L'\n';
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
    wstring text = readText();
    printLetterAfterConvert(convertFirstLetterToLowercase(text));
    return 0;
}