#include "stdafx.h"
#include "Calculator.h"
#include <assert.h>


CCalculator::CCalculator()
{
}


CCalculator::~CCalculator()
{
}
bool CCalculator::SetVariableIdentifier(const string & variable)
{
	if(!IsVariableDefined(variable) && !IsFunctionDefined(variable))
	{
		m_variableNameList[variable] = NAN;
		return true;
	}
	return false;
}

boost::optional<double> CCalculator::GetValue(const string & identifier)
{
	boost::optional<double> valueEmpty;
	if (m_variableNameList.find(identifier) != m_variableNameList.end())
	{
		return (m_variableNameList.find(identifier)->second);
	}
	else if (m_functionNameList.find(identifier) != m_functionNameList.end())
	{
		return GetValueFn(identifier);
	}
	return valueEmpty;
}

bool CCalculator::IsVariableDefined(const string & variable) const
{
	if( m_variableNameList.find(variable) != m_variableNameList.end() )
	{
		return true;//если встретили
	}
	return false;//если не встретили такую же переменную
}

bool CCalculator::IsFunctionDefined(const string & functionName) const
{
	if (m_functionNameList.find(functionName) != m_functionNameList.end())
	{
		return true;
	}
	return false;
}

bool CCalculator::SetVariableValue(const string &variable, const string &value)
{
	if(IsFunctionDefined(value))
	{
		m_variableNameList[variable] = GetValueFn(value);
		return true;
	}
	else if(IsVariableDefined(value))
	{
		m_variableNameList[variable] = m_variableNameList.find(value)->second;
		return true;
	}
	return true;
}

bool CCalculator::SetVariableValue(const string &variable, double value)
{
	m_variableNameList[variable] = value;
	return true;
}



double CCalculator::CalculateFunction(double firstValue, const OperationType &operation, double secondValue)
{
	if (operation == OperationType::ADD)
	{
		return (firstValue + secondValue);
	}
	else if (operation == OperationType::SUB)
	{
		return (firstValue - secondValue);
	}
	else if (operation == OperationType::MUL)
	{
		return (firstValue * secondValue);
	}
	return (firstValue / secondValue);
}

bool CCalculator::DefineFunction(const string &fnName, const string &identifier1,const OperationType &operation, const string & identifier2)
{
	OperationsFunction info;
	if (IsVariableDefined(identifier1) || IsFunctionDefined(identifier1) && IsVariableDefined(identifier2) || IsFunctionDefined(identifier2))
	{
		info.firstVal = identifier1;
		info.operation = operation;
		info.secondVal = identifier2;
		info.wasTwoOperands = true;
		m_functionNameList.emplace(fnName, info);
		return true;
	}
	return false;
}

bool CCalculator::DefineFunction(const string &fnName, const string &identifier)
{
	OperationsFunction info;
	if (IsVariableDefined(identifier) || IsFunctionDefined(identifier))
	{
		info.firstVal = identifier;
		info.wasTwoOperands = false;
		m_functionNameList.emplace(fnName, info);
		return true;
	}
	return false;
}

double CCalculator::GetValueFn(const string & fnName)
{
	if (m_functionNameList.find(fnName)->second.wasTwoOperands == false)
	{
		auto value = m_functionNameList.find(fnName)->second.firstVal;
		if (IsVariableDefined(value))
		{
			return GetVariableValue(value);
		}
		return NAN;
	}
	OperationsFunction information;
	information = m_functionNameList.find(fnName)->second;
	double firstValue;
	if(IsVariableDefined(information.firstVal))
	{
		firstValue = GetVariableValue(information.firstVal);
	}
	else
	{
		firstValue = GetValueFn(information.firstVal);
	}
	double secondValue;
	if (IsVariableDefined(information.secondVal))
	{
		secondValue = GetVariableValue(information.secondVal);
	}
	else
	{
		secondValue = GetValueFn(information.secondVal);
	}
	
	if (isnan(firstValue) || isnan(secondValue))
	{
		return NAN;
	}
	return  CalculateFunction(firstValue, information.operation, secondValue);
}


double CCalculator::GetVariableValue(const string & varName) const
{
	assert(m_variableNameList.find(varName)->second);
	return m_variableNameList.find(varName)->second;
}


map <string, OperationsFunction>::const_iterator CCalculator::BeginItForFunctionList() const
{
	return m_functionNameList.begin();
}

map <string, OperationsFunction>::const_iterator CCalculator::EndItForFunctionList() const
{
	return m_functionNameList.end();
}

map <string, double>::const_iterator CCalculator::BeginItForVariablesList() const
{
	return m_variableNameList.begin();
}

map <string, double>::const_iterator CCalculator::EndItForVariablesList() const
{
	return m_variableNameList.end();
}