#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include "../som3aLib.h"
using std::wcout;
int main()
{
    system("chcp 65001 > nul");
    srand((unsigned)time(NULL));
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    short Number1 = limitsOfRandom(1, 5)*2,
          Number2 = limitsOfRandom(1, 10);
    wcout << "فكر في رقم من 1 ل 10\n";
    Sleep(5000);
    wcout << "اضرب الرقم في اتنين\n";
    Sleep(5000);
    wcout << "زود عليه \n"
         << Number1;
    Sleep(5000);
    wcout << "ارمي نصهم في البحر\n";
    Sleep(5000);
    wcout << "نقص منه \n"
         << Number2;
    Sleep(5000);
    wcout << "نقص منه الرقم اللي انت اختارته منه\n";
    Sleep(5000);
    wcout << "========================\nتبقى معاك"
         << 0.5 * Number1 - Number2;
    return 0;
}