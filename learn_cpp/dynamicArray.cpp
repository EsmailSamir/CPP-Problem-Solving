#include <iostream>
#include "../som3aLib.h"
using namespace std;
int main()
{
    unsigned int students;
    cout << "Enter How Many Student? ";
    cin >> students;
    validation(students, 0, 32000);
    float *poin;
    poin = new float[students];
    for (unsigned int i = 0; i < students; i++)
    {
        cout << "Enter Degree Of Student Num(" << i + 1 << ") = ";
        cin >> *(poin + i);
        validation(*(poin + i), 0, 100);
    }
    cout << "\nThe Degree Of Sudent Equal: \n";
    for (unsigned int i = 0; i < students; i++)
    {
        cout << "Degree Of Student Num(" << i + 1 << ") = "
             << *(poin + i) << '\n';
    }
    delete[] poin;
    poin = nullptr;
    return 0;
}