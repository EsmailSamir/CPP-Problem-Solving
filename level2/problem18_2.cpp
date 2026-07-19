#include <iostream>
#include <string>
using namespace std;
string readName()
{
    string name;
    cout << "Enter Name: ";
    getline(cin, name);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(10000000, '\n');
        cout << "Enter Name: ";
        getline(cin, name);
    }
    return name;
}
string convertToEncryption(string name)
{
    for (unsigned short i = 0; i < name.length(); i++)
    {
        name[i] += 2;
    }
    string nameEncryption = name;
    return nameEncryption;
}
string convertToDecryption(string nameEncryption)
{
    for (unsigned short i = 0; i < nameEncryption.length(); i++)
    {
        nameEncryption[i] -= 2;
    }
    string nameDecryption = nameEncryption;
    return nameDecryption;
}
void printAfterAllConverts(string name, string nameEncryption, string nameDecryption)
{
    cout << "============================================\n"
         << "Text Before Encryption: " << name << '\n'
         << "Text After Encryption : " << nameEncryption << '\n'
         << "Text After Decryption : " << nameDecryption;
}
int main()
{
    string name = readName(), nameEncryption = convertToEncryption(name),
           nameDecryption = convertToDecryption(nameEncryption);
    printAfterAllConverts(name, nameEncryption, nameDecryption);
    return 0;
}