#include "stdafx.h"
#include "Calculator.h"


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}

void CCalculator::PutInfoInVariableList(string variable, string value)
{
	m_variableNameList[variable] = value;
}

void  CCalculator::PrintVars()
{
	for (auto &it : m_variableNameList)
	{
		cout << it.first << ":" << it.second << endl;
	}
}