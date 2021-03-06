// OopLab1Task2Var7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h" 
#include <string> 
#include <iostream> 
#include <fstream> 
#include <sys\stat.h> 
#include <algorithm> 
#include <vector>


using namespace std;

string CheckSign(string const &initialNumber, string &sign, bool &wasSign)
{
	string withoutSign;
	if (initialNumber[0] == '-')
	{
		for (int i = 1; i < initialNumber.length(); i++)
		{
			withoutSign += initialNumber[i];
		}
		sign = "-";
		wasSign = true;
		return withoutSign;
	}
	else if (initialNumber[0] == '+')
	{
		for (int i = 1; i < initialNumber.length(); i++)
		{
			withoutSign += initialNumber[i];
		}
		sign = "+";
		wasSign = true;
		return withoutSign;
	}
	else
	{
		return initialNumber;
	}
}
bool CheckAdmissibleNumber(string const &initialNumber, const vector<char> &admissibleNumber)
{
	bool wasError = false;
	size_t numberOfDigits = initialNumber.length();
	int checkNumberOfDigits = 0;
	int k = 0;
	for (int i = 0; i < initialNumber.length(); i++)
	{
		for (int j = 0; j < admissibleNumber.size(); j++)
		{
			if (initialNumber[i] == admissibleNumber[j])
			{
				checkNumberOfDigits++;
			}
		}
	}
	if (checkNumberOfDigits != numberOfDigits)
	{
		wasError = true;
	}
	return wasError;
}

int StringToInt(string const &initialNumber)
{
	unsigned char byte;
	char checkChar;
	unsigned long long int result = 0;
	for (byte = 0; byte < initialNumber.length();byte++)
	{
		result *= 16;
		checkChar = initialNumber[byte];
		if (isdigit(static_cast<int>(checkChar)))
		{
			result = int(checkChar) - int('0');
		}
		else
		{
			result = int(checkChar) - int('A') + 10;
		}
	}
	return result;
}

bool CheckNumberSystem(string const &baseIn, string const &baseOut, string const &initialNumber)
{
	bool wasError = false;
	string symbolOne;
	if ((atoi(baseIn.c_str()) < 2 || atoi(baseIn.c_str()) > 36) || (atoi(baseOut.c_str()) < 2 || atoi(baseOut.c_str()) > 36))
	{
		cout << "Incorrect data enter\n";
		wasError = true;
	}
	if (!wasError)
	{
		for (int i = 0; i < initialNumber.length(); i++)
		{
			symbolOne = initialNumber[i];
			if ((StringToInt(symbolOne)) >= atoi(baseIn.c_str()) && !wasError)
			{
				cout << "Incorrect data enter\n";
				wasError = true;
			}
		}
	}
	return wasError;
}
void IntConverter(string const &baseIn, string const &baseOut, string const &initialNumber)
{
	size_t lenInitialNumber = initialNumber.length();
	long long int number = 0;
	long long int count;
	long long int buff[255];
	int symbolOneForInt;
	string symbolOneForStr;
	for (int i = 0; i < lenInitialNumber; i++)
	{
		symbolOneForStr = initialNumber[i];
		number = number * (atoi(baseIn.c_str())) + (StringToInt(symbolOneForStr));
	}
	if (number == 0)
	{
		cout << 0;
	}
	else
	{
		count = 0;
		while (number != 0)
		{
			buff[count] = number % (atoi(baseOut.c_str()));
			number = number / (atoi(baseOut.c_str()));
			count++;
		}
		for (long long int i = count - 1; i >= 0; i--)
		{
			symbolOneForInt = buff[i];
			symbolOneForStr = buff[i];
			if (symbolOneForInt >= 0 && symbolOneForInt <= 9) {
				cout << symbolOneForInt;
			}
			else
			{
				cout << (atoi(symbolOneForStr.c_str()));
			}
		}
	}
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <source notation> <destination notation> <value>'\n";
		return 1;
	}
	vector<char> admissibleNumber = { '+', '-','0','1','2','3','4','5','6','7','8','9',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
		'Q','R','S','T','U','V','W','X','Y','Z' };

	string baseIn = argv[1];
	string baseOut = argv[2];
	string initialNumber = argv[3];

	if (initialNumber.length() > 10)
	{
		cout << "a large number";
	}
	if (CheckAdmissibleNumber(initialNumber, admissibleNumber))
	{
		return 1;
	}
	if (CheckNumberSystem(baseIn, baseOut, initialNumber))
	{
		return 1;
	}
	string sign;
	bool wasSign = false;
	initialNumber = CheckSign(initialNumber, sign, wasSign);
	if (wasSign)
	{
		cout << sign;
	}
	IntConverter(baseIn, baseOut, initialNumber);
	return 0;
}