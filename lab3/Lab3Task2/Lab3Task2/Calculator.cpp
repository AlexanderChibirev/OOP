#include "stdafx.h"
#include "Calculator.h"


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}
bool CCalculator::SetVariableIdentifier(const string & variable)
{
	if(!IsVariableDefine(variable) && !IsFunctionDefine(variable))
	{
		m_variableNameList[variable] = NAN;
		return true;
	}
	return false;
}

double CCalculator::GetValue(const string & varName)//getValue
{
	if (m_variableNameList.find(varName) != m_variableNameList.end())//если встертили в списке переменных
	{
		return (m_variableNameList.find(varName)->second);
	}
	else if (m_functionNameList.find(varName) != m_functionNameList.end())//если встертили в списке функций
	{
		return GetValueFn(varName);
	}
	return NULL;
}

bool CCalculator::IsVariableDefine(const string & variable) const
{
	if( m_variableNameList.find(variable) != m_variableNameList.end() )
	{
		return true;//если встретили
	}
	return false;//если не встретили такую же переменную
}

bool CCalculator::IsFunctionDefine(const string & functionName) const
{
	if (m_functionNameList.find(functionName) != m_functionNameList.end())
	{
		return true;//если встретили
	}
	return false;//если не встретили такую же переменную
}

bool CCalculator::SetVariableValue(const string &variable, const string &value)
{
	if(IsFunctionDefine(value))
	{
		m_variableNameList[variable] = GetValueFn(value);
		return true;
	}
	else if(IsVariableDefine(value))
	{
		m_variableNameList[variable] = m_variableNameList.find(value)->second;
		return true;
	}
	m_variableNameList[variable] = atof(value.c_str());
	return true;
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
	return (firstValue / secondValue);
}

bool CCalculator::SetFunction(const string &fnName, const string &firstValue, const string &operand, const string & secondValue)
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

double CCalculator::GetValueFn(const string & fnName)
{
	SecondMapInformation information;
	information = m_functionNameList.find(fnName)->second;
	double firstValue;
	double secondValue;
	if(IsVariableDefine(information.firstVal))
	{
		firstValue = GetValueVariable(information.firstVal);
	}
	else
	{
		firstValue = GetValueFn(information.firstVal);
	}
	if (IsVariableDefine(information.secondVal))
	{
		secondValue = GetValueVariable(information.secondVal);
	}
	else
	{
		secondValue = GetValueFn(information.secondVal);
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


double CCalculator::GetValueVariable(const string & varName) const
{
	return m_variableNameList.find(varName)->second;
}

map <string, double> CCalculator::GetVariableList() const
{
	return m_variableNameList;
}
map <string, SecondMapInformation> CCalculator::GetFunctionList() const
{
	return m_functionNameList;
}