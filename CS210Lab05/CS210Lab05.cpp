#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int convert(char num)
{

	//Converts char to its int value by subtracting the ascii value of 0
	//Handles Hexadecimal letters such as A,B,C,D,E and adds 10 to set the value to 10,11,12 etc.
	if (num >= '0' && num <= '9')
	{
		return (int)num - '0';
	}
	else
	{
		return (int)num - 'A' + 10;
	}
}

int ToDecimal(int base1, string unconverted)
{
	int Dec = 0;
	int j = unconverted.length() - 1;

	for (int i = 0; i < unconverted.length(); i++)
	{
		Dec += convert(unconverted[j]) * (int)pow(base1, i);
		j--;
	}
	
	return Dec;
}

string ToBaseN(int base2, int Dec)
{
	string Base;
	while (Dec > 0)
	{
		Base += to_string(Dec % base2);
		Dec /= base2;
	}
	reverse(Base.begin(), Base.end());
	return Base;
}

int main()
{
	int base1, base2;
	string unconverted;
	

	cin >> base1 >> base2 >> unconverted;

	string converted = ToBaseN(base2, ToDecimal(base1,unconverted));
	cout << converted;

	return 0;
}