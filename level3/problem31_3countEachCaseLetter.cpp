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
wchar_t readLetter()
{
    wchar_t letter;
    wcout << L"\nEnter Any Character: \n";
    if (!(wcin >> letter))
    {
        wcin.clear();
        wcin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            L'\n');
        wcout << L"Input Is Canceled!...\n";
    }
    return letter;
}
void countTheLetter(const wstring &text, const wchar_t letter,
                    size_t &countLower, size_t &countUpper)
{
    const wchar_t upperLetter = towupper(letter),
                  lowerLetter = towlower(letter);
    for (size_t i = 0; i < text.length(); i++)
    {
        if (iswlower(text[i]) && text[i] == lowerLetter)
            countLower++;
        else if (iswupper(text[i]) && text[i] == upperLetter)
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
    wchar_t letter = readLetter();
    size_t countLower = 0, countUpper = 0;
    countTheLetter(text, letter, countLower, countUpper);
    wcout << L"========================\n"
          << L"Letter '" << wchar_t(towlower(letter))
          << L"' Count = " << countLower
          << L"\nLetter '" << wchar_t(towupper(letter))
          << L"' Count = " << countUpper << L'\n';
    return 0;
}