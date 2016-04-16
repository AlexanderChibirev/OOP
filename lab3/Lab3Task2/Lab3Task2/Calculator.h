#pragma once
#include "Difinition.h"
#include <memory>
#include <vector>
#include <boost/iterator/indirect_iterator.hpp>

using namespace std;

class CCalculator
{
public:
	CCalculator();
	~CCalculator();

	bool SetVariableIdentifier(const string & variable);
	bool SetVariableValue(const string & variable, const string & value);
	bool SetVariableValue(const string & variable, double value);
	bool DefineFunction(const string &fnName, const string &firstValue, const OperationType &, const string & secondValue);
	bool CCalculator::DefineFunction(const string &fnName, const string &firstValue);
	map <string, double> GetVariableList() const; 
	map <string, OperationsFunction> GetFunctionList() const;

	typedef boost::indirect_iterator<map <string, double>::const_iterator, map <string, double>::value_type> ConstIteratorForVariableList;
	ConstIteratorForVariableList BeginForVariableList()const;
	ConstIteratorForVariableList EndForVariableList()const;

	typedef boost::indirect_iterator<map <string, OperationsFunction> ::const_iterator, map <string, OperationsFunction> ::value_type> ConstIteratorForFunctionList;
	ConstIteratorForFunctionList BeginForFunctionList()const;
	ConstIteratorForFunctionList EndForFunctionList()const;

	double GetValueFn(const string & fnName);
	boost::optional<double>  GetValue(const string &identifier);
private:
	double CalculateFunction(double firstValue,const OperationType &operation, double secondValue);
	double GetVariableValue(const string & varName) const;
	bool IsVariableDefined(const string & variable) const;
	bool IsFunctionDefined(const string & functionName) const;
private:
	map <string, double> m_variableNameList;
	map <string, OperationsFunction> m_functionNameList;
};

