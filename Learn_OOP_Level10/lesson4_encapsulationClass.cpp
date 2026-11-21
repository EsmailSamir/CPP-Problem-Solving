#include <iostream>
using namespace std;
class clsCalculator
{
private:
	float _Number = 0;
	float _CurrentNumber = 0;
	string _Stat = "Starting";

public:
	float Clear()
	{
		_Stat = "Clear";
		return _Number = _CurrentNumber = 0;
	}
	float Add(const float number)
	{
		_CurrentNumber = number;
		_Stat = "Adding";
		return _Number += number;
	}
	float Subtract(const float number)
	{
		_CurrentNumber = number;
		_Stat = "Subtracting";
		return _Number -= number;
	}
	float Multiply(const float number)
	{
		_CurrentNumber = number;
		_Stat = "Multiplying By";
		return _Number *= number;
	}
	float Divide(const float number)
	{
		_CurrentNumber = number;
		if (number != 0)
		{
			_Stat = "Dividing By";
			return _Number /= number;
		}
		else
		{
			_Stat = "Cannot Divide By Zero";
			return _Number;
		}
	}
	float GetFinalResult() const
	{
		return _Number;
	}
	void PrintResult() const
	{
		if (_Stat == "Cannot Divide By Zero")
		{
			cout << _Stat << " :Result = " << _Number << endl;
		}
		else if (_Stat == "Clear" || _Stat == "Starting")
		{
			cout << "Result After: " << _Stat << " Is = "
				 << _Number << endl;
		}
		else
		{
			cout << "Result After: " << _Stat
				 << " (" << _CurrentNumber << ") Is = "
				 << _Number << endl;
		}
	}
};
int main()
{
	clsCalculator calculator1;
	calculator1.PrintResult();
	calculator1.Clear();
	calculator1.PrintResult();
	calculator1.Add(100);
	calculator1.PrintResult();
	calculator1.Clear();
	calculator1.PrintResult();
	calculator1.Add(10);
	calculator1.PrintResult();
	calculator1.Divide(0);
	calculator1.PrintResult();
	calculator1.Multiply(45);
	calculator1.PrintResult();

	return 0;
}