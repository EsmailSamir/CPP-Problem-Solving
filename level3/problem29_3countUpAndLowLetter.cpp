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
    wcout << L"Enter Text:\n";
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
void countCases(const wstring &text, size_t &countLower,
                size_t &countUpper)
{
    for (size_t i = 0; i < text.length(); i++)
    {
        if (iswlower(text[i]))
            countLower++;
        else if (iswupper(text[i]))
            countUpper++;
    }
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
    size_t countLower = 0, countUpper = 0;
    countCases(text, countLower, countUpper);
    wcout << L"\n=============================="
          << L"\n        String Length = " << text.length()
          << L"\nCapital Letters Count = " << countUpper
          << L"\n  Small Letters Count = " << countLower << L'\n';
    return 0;
}