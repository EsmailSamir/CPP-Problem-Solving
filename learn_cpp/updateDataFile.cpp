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
void updateItem(vector<string> &vNames, const string &cutName, const string &newName)
{
    for (unsigned int i = 0; i < vNames.size(); i++)
    {
        if (vNames[i] == cutName)
            vNames[i] = newName;
    }
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
void loadDataFromVectorToFile(const string &fileName, const vector<string> &vNames)
{
    ofstream fPersons(fileName); // for write mode
    if (fPersons.is_open())
        for (const string &name : vNames)
        {
            fPersons << name << '\n';
        }
    fPersons.close();
}
int main()
{
    vector<string> vNames;
    loadDataFromFileToVector("som3a2.txt", vNames);
    cout << "Data Befor Update:\n";
    printFileContent("som3a2.txt");
    updateItem(vNames, "ali", "omar");
    loadDataFromVectorToFile("som3a2.txt", vNames);
    cout << "\n\nData After Update:\n";
    printFileContent("som3a2.txt");
    return 0;
}