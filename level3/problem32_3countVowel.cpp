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
bool isVowel(const wchar_t letter)
{
    const wstring arrayVowel = L"aAeEoOiIuU";
    return arrayVowel.find(letter) != wstring::npos;
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

    wchar_t letter = readLetter();
    isVowel(letter) ? wcout << L"\nYes, Letter '"
                            << letter << L"' Is A Vowel\n"
                    : wcout << L"\nNo, Letter '"
                            << letter << L"' Is Not A Vowel\n";
    return 0;
}