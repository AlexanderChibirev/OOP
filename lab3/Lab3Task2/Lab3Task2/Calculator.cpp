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
	if (GetVariableValue(variable).is_initialized() || GetOperationsFunction(variable).is_initialized())
	{
		return false;
	}
	m_variableNameList[variable] = NAN;
	return true;
}

boost::optional<double> CCalculator::GetValue(const string & identifier) const
{
	boost::optional<double> valueEmpty;
	boost::optional<double> variable = GetVariableValue(identifier);
	boost::optional<OperationsFunction> function = GetOperationsFunction(identifier);
	if (variable)
	{
		return variable.get();
	}
	else if (function)
	{
		return GetFunctionsValue(identifier).get();
	}
	return valueEmpty;
}

boost::optional<OperationsFunction> CCalculator::GetOperationsFunction(const string & functionName) const
{
	boost::optional<OperationsFunction> operationsFunction;
	try
	{
		operationsFunction = m_functionNameList.at(functionName);
	}
	catch (...)
	{
		return operationsFunction;
	}
	return operationsFunction;
}


boost::optional<double> CCalculator::GetVariableValue(const string &identifier) const
{
	boost::optional<double> value;
	try
	{
		value = m_variableNameList.at(identifier);
	}
	catch (...)
	{
		return value;
	}
	return value;
}

bool CCalculator::SetVariableValue(const string &variable, const string &value)
{
	boost::optional<OperationsFunction> it;
	it = GetOperationsFunction(value);
	if(it)
	{
		m_variableNameList[variable] = GetFunctionsValue(value).get();
		true;
	}
	else
	{
		boost::optional<double> it;
		it = GetVariableValue(value);
		if (it) 
		{
			m_variableNameList[variable] = it.get();
			return true;
		}
		
	}
	return false;
}

bool CCalculator::SetVariableValue(const string &variable, double value)
{
	m_variableNameList[variable] = value;
	return true;
}



double CCalculator::CalculateFunction(double firstValue, const OperationType &operation, double secondValue) const
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

bool CCalculator::DefineFunction(const string &fnName, const string &identifier1, const OperationType &operation, const string & identifier2)
{
	OperationsFunction info;
	if ((!GetVariableValue(fnName)) && (!GetOperationsFunction(fnName)) && (!fnName.empty()))
	{
		auto IsValueAlreadyDefined = [this](const string &identifier) {
			return (GetVariableValue(identifier) || GetOperationsFunction(identifier));
		};

		if (IsValueAlreadyDefined(identifier1) && IsValueAlreadyDefined(identifier2))
		{
			info.firstVal = identifier1;
			info.operation = operation;
			info.secondVal = identifier2;
			info.wasTwoOperands = true;
			m_functionNameList.emplace(fnName, info);
			return true;
		}
	}
	return false;
}

bool CCalculator::DefineFunction(const string &fnName, const string &identifier)
{
	OperationsFunction info;
	if((!GetVariableValue(fnName)) && (!GetOperationsFunction(fnName)) &&(!fnName.empty()))
	{
		if (GetVariableValue(identifier) || GetOperationsFunction(identifier))
		{
			info.firstVal = identifier;
			info.wasTwoOperands = false;
			m_functionNameList.emplace(fnName, info);
			return true;
		}
	}
	return false;
}

boost::optional<double> CCalculator::GetFunctionsValue(const string & fnName) const
{
	boost::optional<OperationsFunction> information;
	information = GetOperationsFunction(fnName);
	if (information)
	{
		boost::optional<double> valueVariable;
		if (information->wasTwoOperands == false)
		{
			auto value = information->firstVal;
			valueVariable = GetVariableValue(value);
			if (valueVariable)
			{
				return valueVariable;
			}
			return NAN;
		}
		boost::optional<double> firstValue;
		valueVariable = GetVariableValue(information->firstVal);
		if (valueVariable)
		{
			firstValue = valueVariable;
		}
		else
		{
			firstValue = GetFunctionsValue(information->firstVal).get();
		}
		boost::optional<double> secondValue;
		valueVariable = GetVariableValue(information->secondVal);
		if (valueVariable)
		{
			secondValue = valueVariable;
		}
		else
		{
			secondValue = GetFunctionsValue(information->secondVal).get();
		}

		if (isnan(firstValue.get()) || isnan(secondValue.get()))
		{
			return NAN;
		}
		return CalculateFunction(firstValue.get(), information->operation, secondValue.get());
	}
	boost::optional<double> valueEmpty;
	return valueEmpty;
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