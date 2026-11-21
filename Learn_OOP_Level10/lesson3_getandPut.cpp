#include <iostream>
using namespace std;
class clsPersons
{
private:
	string _FirstName;

public:
	void SetFirstName(string firstName)
	{
		_FirstName = firstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))
		string FirstName;
};
int main()
{
	clsPersons person1;
	person1.SetFirstName("Esmail");
	cout << "First Name Is: " << person1.GetFirstName();
	// Onother way
	person1.FirstName = "Esmail";
	cout << "\nFirst Name Is : " << person1.FirstName << endl;
	return 0;
}