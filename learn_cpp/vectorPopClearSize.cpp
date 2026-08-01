#include <iostream>
#include <vector>
using namespace std;
void editOnVector(vector<short> &vNumbers)
{
    vNumbers.push_back(10);
    vNumbers.push_back(20);
    vNumbers.push_back(30);
    vNumbers.push_back(40);
    vNumbers.push_back(50);

    cout << "Size Of Vector = " << vNumbers.size() << '\n';
    vNumbers.pop_back();

    // while (!vNumbers.empty()) //while vector  not empty
    // {
    //       vNumbers.pop_back();
    //  }
    // or

    //   if (!vNumbers.empty())// if not empty

    // if (vNumbers.size() > 0)// if size > 0
    //    vNumbers.pop_back();
    if (!vNumbers.empty())
    {
        cout << "Size Of Vector = " << vNumbers.size() << '\n';
        cout << "first element = " << vNumbers.front() << '\n';
    }
    cout << "last element = " << vNumbers.back() << '\n';
    cout << "capacity = " << vNumbers.capacity() << '\n';
    vNumbers.clear(); // delet all
    cout << "Size Of Vector = " << vNumbers.size() << '\n';
    vNumbers.shrink_to_fit(); // delete All capacity from Ram
    cout << "capacity = " << vNumbers.capacity() << '\n';
}
int main()
{
    vector<short> vNumbers;
    editOnVector(vNumbers);

    return 0;
}