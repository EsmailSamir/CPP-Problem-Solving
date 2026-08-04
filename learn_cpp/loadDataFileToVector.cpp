#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void loadDataFromFileToVector(const string &fileName, vector<string> &vNames)
{
    ifstream fPersons(fileName); // for read mode
    string line;
    if (fPersons.is_open())
    {
        while (getline(fPersons, line))
        {
            vNames.push_back(line);
        }
    }
    fPersons.close();
}
void printFileContent(const vector<string> &vNames)
{
    for (const string &name : vNames)
    {
        cout << name << '\n';
    }
}
int main()
{
    vector<string> vNames;
    loadDataFromFileToVector("som3a.txt", vNames);
    printFileContent(vNames);
    return 0;
}