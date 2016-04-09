#include "stdafx.h"
#include "Calculator.h"


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}
bool CCalculator::IsDeclareVariable(const string & variable)
{
	if(!IsVariableDefine(variable) && !IsFunctionDefine(variable))
	{
		m_variableNameList[variable] = NAN;
		return false;
	}
	return true;
}

void  CCalculator::PrintVars() const
{
	for (auto &it : m_variableNameList)
	{
		if(it.second != NAN)
		{
			cout << it.first << ":";
			printf("%.2f\n", it.second);
		}
		else
		{
			cout << it.first << ":" << it.second << endl;
		}
	}
}

void CCalculator::Print(double var)
{
	if (var != NAN)
	{
		printf("%.2f\n", var);
	}
	else
	{
		cout << var << endl;
	}
}

bool CCalculator::CheckValueForPrint(const string & varName) 
{
	if (m_variableNameList.find(varName) != m_variableNameList.end())
	{
		Print(m_variableNameList.find(varName)->second);
		return true;
	}
	else if (m_functionNameList.find(varName) != m_functionNameList.end())
	{
		Print(GetFn(varName));
		return true;
	}
	return false;
}

bool CCalculator::IsVariableDefine(const string & variable)
{
	if( m_variableNameList.find(variable) != m_variableNameList.end() )
	{
		return true;
	}
	return false;
}

bool CCalculator::IsFunctionDefine(const string & functionName)
{
	if (m_functionNameList.find(functionName) != m_functionNameList.end())
	{
		return true;//если встретили
	}
	return false;//если не встретили такую же переменную
}

void  CCalculator::SetVariableValue(const string & variable, double value)
{
	m_variableNameList[variable] = value;
}

bool CCalculator::PutInfoInVariableList(const string &variable, const string &value)
{
	if(IsFunctionDefine(value))
	{
		SetVariableValue(variable, GetFn(value));
		return true;
	}
	else if(IsVariableDefine(value))
	{
		SetVariableValue(variable, m_variableNameList.find(value)->second);
		return true;
	}
	else 
	{
		SetVariableValue(variable, atof(value.c_str()));
		return true;
	}
	return false;
}

void CCalculator::Printfns()
{
	for (auto &it : m_functionNameList)
	{
		cout << it.first << ":";
		printf("%.2f\n", GetFn(it.first));
	}
}

double CCalculator::Calculation(double firstValue, const string & operand, double secondValue)
{
	if (operand == "+")
	{
		return (firstValue + secondValue);
	}
	else if (operand == "-")
	{
		return (firstValue - secondValue);
	}
	else if (operand == "*")
	{
		return (firstValue * secondValue);
	}
	else
	{
		return (firstValue / secondValue);
	}
	return 0;
}

bool CCalculator::CheckNameFn(const string &fnName, const string &firstValue, const string &operand, const string & secondValue)
{
	SecondMapInformation info;
	if (IsVariableDefine(firstValue) || IsFunctionDefine(firstValue) && IsVariableDefine(secondValue) || IsFunctionDefine(secondValue))
	{
		info.firstVal = firstValue;
		info.operand = operand;
		info.secondVal = secondValue;
		m_functionNameList.insert(std::pair<std::string, SecondMapInformation>(fnName, info));
		return true;
	}
	return false;
}

double CCalculator::GetFn(const string & fnName)
{
	SecondMapInformation information;
	information = m_functionNameList.find(fnName)->second;
	double firstValue;
	double secondValue;
	if(IsVariableDefine(information.firstVal))
	{
		firstValue = GetVariableValue(information.firstVal);
	}
	else
	{
		firstValue = GetFn(information.firstVal);
	}
	if (IsVariableDefine(information.secondVal))
	{
		secondValue = GetVariableValue(information.secondVal);
	}
	else
	{
		secondValue = GetFn(information.secondVal);
	}
	string operandStr = information.operand;
	if (firstValue == NAN || secondValue == NAN)
	{
		return NAN;
	}
	if(operandStr == "funWithOneValue")
	{
		return firstValue;
	}
	return Calculation(firstValue, operandStr, secondValue);
}


double CCalculator::GetVariableValue(const string & varName) const
{
	return m_variableNameList.find(varName)->second;
}