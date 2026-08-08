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
        wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
        wcout << L"Input Is Canceled!...\n";
    }
    return text;
}
wstring convertLetterToUppercase(wstring &text)
{
    for (size_t i = 0; i < text.length(); i++)
    {
        text[i] = towupper(text[i]);
    }
    return text;
}
wstring convertLetterToLowercase(wstring &text)
{
    if (!text.empty())
    {
        for (size_t i = 0; i < text.length(); i++)
        {
            text[i] = towlower(text[i]);
        }
    }
    return text;
}
void printLetterAfterConvert(const wstring &text)
{
    wcout << text << L'\n';
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
    wcout << L"=================================================\n"
          << L"\nAfter Convert All Letter To lowercase:\n";
    printLetterAfterConvert(convertLetterToLowercase(text));
    wcout << L"\nAfter Convert All Letter To Uppercase:\n";
    printLetterAfterConvert(convertLetterToUppercase(text));
    return 0;
}