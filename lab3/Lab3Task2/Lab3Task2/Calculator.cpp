#include "stdafx.h"
#include "Calculator.h"


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}

ErrorCode CCalculator::CheckInfoInVariableList(string var)
{
	if(!isalpha(var[0]))
	{
		return FIRST_SYMBOL_IS_NOT_LETTER;
	}
	if(!CheckVarOnCoincidence(var) || !CheckFunctionrOnCoincidence(var))
	{
		return VAR_HAS_ALREADY_BEEN_DECLARED;
	}
	return IS_ALL_OK;
}

ErrorCode CCalculator::DeclareVariable(string variable)
{
	m_errorCode = CheckInfoInVariableList(variable);
	if(m_errorCode == IS_ALL_OK)
	{
		m_variableNameList[variable] = "nan";
	}
	return m_errorCode;
}

void  CCalculator::PrintVars() const
{
	for (auto &it : m_variableNameList)
	{
		if(it.second != "nan")
		{
			std::string::size_type sz;
			double secondEl = std::stod(it.second, &sz);
			cout << it.first << ":";
			printf("%.2f\n", secondEl);
		}
		else
		{
			cout << it.first << ":" << it.second << endl;
		}
	}
}

void CCalculator::Print(string var)
{
	if (var != "nan")
	{
		std::string::size_type sz;
		double secondEl = std::stod(var, &sz);
		printf("%.2f\n", secondEl);
	}
	else
	{
		cout << var << endl;
	}
}

bool CCalculator::CheckValueForPrint(string varName) 
{
	if (m_variableNameList.find(varName) != m_variableNameList.end())
	{
		string secondVar = m_variableNameList.find(varName)->second;
		Print(secondVar);
		return true;
	}
	else if (m_functionNameList.find(varName) != m_functionNameList.end())
	{
		string secondVar = GetFn(varName);
		Print(secondVar);
		return true;
	}
	return false;
}

bool CCalculator::CheckVarOnCoincidence(string variable)
{
	if( m_variableNameList.find(variable) != m_variableNameList.end() )
	{
		return false;
	}
	return true;
}

bool CCalculator::CheckFunctionrOnCoincidence(string functionName)
{
	if (m_functionNameList.find(functionName) != m_functionNameList.end())
	{
		return false;//если встретили
	}
	return true;//если не встретили такую же переменную
}

void  CCalculator::PutValueInVariableList(string variable, string value)
{
	m_variableNameList[variable] = value;
}

bool CCalculator::IsDoubleNumber(string const &str)
{
	int countPoint = 0;
	for (auto &it : str)
	{
		if (it == '.')
		{
			countPoint++;
		}
		else if(!isdigit(it))
		{
			return false;
		}
	}
	if (countPoint > 1 || str[0] == '.' || str[str.length()-1] == '.')
	{
		return false;
	}
	return true;
}

ErrorCode CCalculator::PutInfoInVariableList(string variable, string value)
{
	m_errorCode = CheckInfoInVariableList(variable);
	if (m_errorCode == VAR_HAS_ALREADY_BEEN_DECLARED || m_errorCode == IS_ALL_OK )
	{
		if(IsDoubleNumber(value))
		{
			PutValueInVariableList(variable, value);
		}
		else
		{
			m_errorCode = CheckInfoInVariableList(value);
			if(!CheckFunctionrOnCoincidence(value))
			{
				PutValueInVariableList(variable, GetFn(value));
				return m_errorCode;
			}
			if(!CheckVarOnCoincidence(value))
			{
				PutValueInVariableList(variable, m_variableNameList.find(value)->second);
				return m_errorCode;
			}
			m_errorCode = INCORRECT_ENTER;
		}
	}
	return m_errorCode;
}

void CCalculator::Printfns()
{
	for (auto &it : m_functionNameList)
	{
		std::string::size_type sz;
		double secondEl = std::stod(GetFn(it.first), &sz);
		cout << it.first << ":";
		printf("%.2f\n", secondEl);
	}
}

double CCalculator::Calculation(double firstValue, string operand, double secondValue)
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
	if (CheckInfoInVariableList(firstValue) == VAR_HAS_ALREADY_BEEN_DECLARED && CheckInfoInVariableList(secondValue) == VAR_HAS_ALREADY_BEEN_DECLARED)
	{
		info.firstVal = firstValue;
		info.operand = operand;
		info.secondVal = secondValue;
		m_functionNameList.insert(std::pair<std::string, SecondMapInformation>(fnName, info));
		return true;
	}
	return false;
}

string CCalculator::GetFn(string fnName)
{
	SecondMapInformation information;
	information = m_functionNameList.find(fnName)->second;
	string firstValueStr;
	string secondValueStr;
	if(!CheckVarOnCoincidence(information.firstVal))
	{
		firstValueStr = GetVariableValue(information.firstVal);
	}
	else
	{
		firstValueStr = GetFn(information.firstVal);
	}
	if (!CheckVarOnCoincidence(information.secondVal))
	{
		secondValueStr = GetVariableValue(information.secondVal);
	}
	else
	{
		secondValueStr = GetFn(information.secondVal);
	}
	string operandStr = information.operand;
	if (firstValueStr == "nan" || secondValueStr == "nan")
	{
		return "nan";
	}
	std::string::size_type sz;
	if(operandStr == "funWithOneValue")
	{
		return firstValueStr;
	}
	double firstDouble = std::stod(firstValueStr, &sz);
	double secondDouble = std::stod(secondValueStr, &sz);
	return to_string(Calculation(firstDouble, operandStr, secondDouble));
}


string CCalculator::GetVariableValue(string varName) const
{
	return m_variableNameList.find(varName)->second;
}