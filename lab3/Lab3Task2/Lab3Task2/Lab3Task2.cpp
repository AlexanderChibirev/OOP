// Lab3Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Calculator.h"

#include <map>
#include <set>
#include <string>
#include <iostream>
#include <iterator>


void WorkWithUser()
{
	CCalculator calculator;
	string inputStr;
	while ((cout << ">") && getline(cin, inputStr))
	{
		if(inputStr.find("var") == 0)
		{
			inputStr.erase(0, 4);
			calculator.PutInfoInVariableList(inputStr, "nan");
		}
		else if (inputStr.find("let") == 0)
		{
			cout << "let ...\n";
		}
		else if (inputStr.find("fn=") == 0)
		{
			cout << "fn= ...\n";
		}
		else if (inputStr.find("printvars") == 0 && inputStr.length() == 9)
		{
			calculator.PrintVars();
		}
		else
		{
			cout << "incorrect\n";
		}
	}
}

int main()
{


	/*map <string, string, ByLength> m_variableNameList;
	m_variableNameList["AA"] = "1";
	m_variableNameList["aa"] = "1";
	m_variableNameList["C"] = "2";
	m_variableNameList["CCC"] = "3";
	m_variableNameList["CDDD"] = "3";
	m_variableNameList["D"] = "3";
	m_variableNameList["B"] = "3";
	for (auto &it : m_variableNameList)
	{
		cout << it.first << ":" << it.second << endl;
	}*/
	WorkWithUser();
    return 0;
}

