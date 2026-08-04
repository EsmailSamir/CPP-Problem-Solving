#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../som3aLib.h"
using namespace std;
void filloutVector(vector<string> &vNames)
{
    unsigned short i = 1;
    bool more;
    string line;
    do
    {
        cout << "\nEnter String Line(" << i << "): \n";
        getline(cin, line);
        vNames.push_back(line);
        cout << "\nDo you Want To Add More:\n"
             << "(0)NO, (1)YES : ";
        cin >> more;
        validation(more, 0, 1);
        i++;
        cin.ignore(9999999999999, '\n');
    } while (more);
}
void loadDataFromVectorToFile(const string &fileName, const vector<string> &vNames)
{
    ofstream fPersons(fileName, ios::app); // for write and append mode
    if (fPersons.is_open())
        for (const string &name : vNames)
        {
            fPersons << name << '\n';
        }
    fPersons.close();
}
void printFileContent(const string &file)
{
    string line;
    ifstream myFile(file);
    if (myFile.is_open())
        while (getline(myFile, line))
        {
            cout << line << '\n';
        }
    myFile.close();
}
int main()
{
    vector<string> vNames;
    filloutVector(vNames);
    loadDataFromVectorToFile("som3a2.txt", vNames);
    cout << "\n==========================\n"
         << "The Data In The File Is:\n\n";
    printFileContent("som3a2.txt");
    return 0;
}