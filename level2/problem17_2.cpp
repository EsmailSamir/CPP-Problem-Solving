#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;
string readPassword()
{
    string password = "";
    char temb;
    for (short i = 1; i <= 3; i++)
    {
        cout << "Enter Password[" << i << "]: ";
        cin >> temb;
        if (cin.eof())
        {
            cout << "\n[Error] Input stream was forcefully closed. Exiting program...\n";
            exit(0);
        }
        while (cin.fail() || temb < 'A' || 'Z' < temb)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter An One \"CAPITAL\" letter[A:Z]: ";
            cin >> temb;
            if (cin.eof())
            {
                cout << "\n[Error] Input stream was forcefully closed. Exiting program...\n";
                exit(0);
            }
        }
        password += temb;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return password;
}
void printAllWords(string password)
{
    string trial = " Trial";
    cout << "========================";
    short h = 1;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            for (char k = 'A'; k <= 'Z'; k++)
            {
                string userPass = "";
                userPass += i;
                userPass += j;
                userPass += k;
                cout << '\n'
                     << "Trial[" << h << "]: " << userPass;
                if (password == userPass)
                {
                    if (h > 1)
                        trial += 's';
                    cout << "\n========================\n"
                         << "Found After " << h << trial;
                    return;
                }
                h++;
            }
        }
    }
}
int main()
{
    printAllWords(readPassword());
    return 0;
}