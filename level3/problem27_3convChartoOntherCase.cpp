#include <iostream>
using namespace std;
char readCharacter()
{
    char character;
    cout << "Enter Character: ";
    if (!(cin >> character))
    {
        cin.clear();
        cin.ignore(9999999999, '\n');
        cout << "Input Is Canceled!...\n";
    }
    return character;
}
char convertCharacterToAnotherCase(const char character)
{
    return islower(character) ? toupper(character) : tolower(character);
}
void printCharacterAfterConvert(const char character)
{
    cout << character;
}
int main()
{
    char character = readCharacter();
    cout << "=========================================\n"
         << "After Convert Character To Anothercase: ";
    printCharacterAfterConvert(convertCharacterToAnotherCase(character));
    return 0;
}