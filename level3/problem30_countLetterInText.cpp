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
    wcout << L"\nEnter A Character: \n";
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
size_t countTheLetter(const wstring &text, const wchar_t letter)
{
    size_t count = 0;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (text[i] == letter)
            count++;
    }
    return count;
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
    wcout << L"\n========================\n"
          << L"Letter '" << letter << L"' Count = "
          << countTheLetter(text, letter) << L'\n';
    return 0;
}