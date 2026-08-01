#include <iostream>
#include <fstream>
using namespace std;
void printFileContent(string file)
{
    fstream myFile;
    myFile.open(file, ios::in);
    string line;
    while (getline(myFile, line))
    {
        cout << line << '\n';
    }
}
int main()
{
    fstream file;
    file.open("som3a.txt", ios::out | ios::app);
    file << "som3a\n"
         << "samir\n"
         << "esmail\n";
    printFileContent("som3a.txt");
    file.close();

    return 0;
}