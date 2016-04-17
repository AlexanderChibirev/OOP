#pragma once
#include "Difinition.h"
#include <memory>
#include <vector>
#include <boost/iterator/indirect_iterator.hpp>



#include <list>
#include <vector>
#include <deque>

#include <boost/range/functions.hpp>

using namespace std;

class CCalculator
{
public:
	CCalculator();
	~CCalculator();

	typedef map <string, double>::const_iterator ConstIteratorForVariablesList;
	typedef map <string, OperationsFunction>::const_iterator ConstIteratorForFunctionsList;

	ConstIteratorForVariablesList BeginItForVariablesList() const;
	ConstIteratorForVariablesList EndItForVariablesList() const;

	ConstIteratorForFunctionsList BeginItForFunctionList() const;
	ConstIteratorForFunctionsList EndItForFunctionList() const;

	bool SetVariableIdentifier(const string & variable);
	bool SetVariableValue(const string & variable, const string & value);
	bool SetVariableValue(const string & variable, double value);
	bool DefineFunction(const string &fnName, const string &firstValue, const OperationType &, const string & secondValue);
	bool DefineFunction(const string &fnName, const string &firstValue);

	double GetValueFn(const string & fnName) const ;
	boost::optional<double>  GetValue(const string &identifier) const;
private:
	double CalculateFunction(double firstValue, const OperationType &operation, double secondValue) const;
	double GetVariableValue(const string & varName) const;
	bool IsVariableDefined(const string & variable) const;
	bool IsFunctionDefined(const string & functionName) const;
private:
	map <string, double> m_variableNameList;
	map <string, OperationsFunction> m_functionNameList;
};

