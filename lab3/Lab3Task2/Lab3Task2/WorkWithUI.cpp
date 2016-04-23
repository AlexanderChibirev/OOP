#include "stdafx.h"
#include "WorkWithUI.h"
#include "Calculator.h"

using namespace std;
using namespace std::placeholders;

CWorkWithUI::CWorkWithUI(CCalculator & calculator, std::istream & input, std::ostream & output)
	: m_calculator(calculator)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "var", bind(&CWorkWithUI::Var, this, std::placeholders::_1) },
		{ "let", bind(&CWorkWithUI::Let, this, std::placeholders::_1) },
		{ "fn", bind(&CWorkWithUI::Fn, this, std::placeholders::_1) },
		{ "print", bind(&CWorkWithUI::Print, this, std::placeholders::_1) },
		{ "printvars", bind(&CWorkWithUI::Printvars, this, std::placeholders::_1) },
		{ "printfns", bind(&CWorkWithUI::Printfns, this, std::placeholders::_1) }
})
{
}

bool CWorkWithUI::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

bool CWorkWithUI::Var(std::istream & args)
{
	string line;
	args >> line;
	if (!isalpha(line[0]))
	{
		cout << "first symbol variable name is not letter, variable name must not start with a digit\n";
		return false;
	}
	else if(!m_calculator.SetVariableIdentifier(line))
	{
		cout << "it's variable has already been declared\n";
	}
	return true;
}
bool CWorkWithUI::Printvars(std::istream & args)
{
	for (CCalculator::ConstIteratorForVariablesList iter = m_calculator.BeginItForVariablesList(); iter != m_calculator.EndItForVariablesList(); ++iter)
	{
		if (isnan(iter->second))
		{
			cout << iter->first << ":" << "nan" << endl;

		}
		else
		{
			cout << iter->first << ":";
			cout << std::fixed <<std::setprecision(2) << iter->second << endl;
		}
	}
	return true;
}

bool  CWorkWithUI::Print(std::istream & args)
{
	string line;
	args >> line;
	if (!m_calculator.GetValue(line).is_initialized())
	{
		cout << "not found value\n";
	}
	else if (isnan(m_calculator.GetValue(line).get()))
	{
		cout << "nan" << endl;
	}
	else 
	{
		cout << std::fixed << std::setprecision(2) << m_calculator.GetValue(line).get() << endl;
	}
	return true;
}


bool CWorkWithUI::Let(std::istream & args)
{
	string line;
	args >> line;
	int posForSplit = line.find("=");
	if(posForSplit == std::string::npos)
	{
		cout << "incorrect entry, read help please\n";
		return false;
	}
	string variable;
	variable.append(line, 0, posForSplit);
	string value;
	value.append(line, posForSplit+1, line.length());
	if (!isalpha(variable[0]))
	{
		cout << "First symbol variable name is not letter, variable name must not start with a digit\nRead help please\n";
		return false;
	}
	if (isdigit(value[0]))
	{
		if (!m_calculator.SetVariableValue(variable, atof(value.c_str()))) 
		{
			cout << "variable can not be set to other undeclared variable";
		}
	}
	else
	{
		m_calculator.SetVariableValue(variable, value);
	}
	return true;
}

bool CWorkWithUI::Printfns(std::istream & args)
{
	for (CCalculator::ConstIteratorForFunctionsList iter = m_calculator.BeginItForFunctionList(); iter != m_calculator.EndItForFunctionList(); ++iter)
	{
		if (isnan(m_calculator.GetFunctionsValue(iter->first).get()))
		{
			cout << iter->first << ":" << "nan" << endl;

		}
		else
		{
			cout << iter->first << ":";
			cout << std::fixed << std::setprecision(2) << m_calculator.GetFunctionsValue(iter->first).get() << endl;
		}
	}
	return true;
}

void CWorkWithUI::PrintError(const string &fnName, const string &firstValue, const OperationType &operation, const string & secondValue)
{
	if (!m_calculator.DefineFunction(fnName, firstValue, operation, secondValue))
	{
		cout << "функция не может вычислять цифры, потому что их нет в списках переменных\n";
	}
}

bool CWorkWithUI::Fn(std::istream & args)
{
	string line;
	args >> line;
	int posForNameSplit = line.find("=");
	if (posForNameSplit == std::string::npos)
	{
		cout << "incorrect entry, read help please\n";
		return false;
	}
	string fnName;
	fnName.append(line, 0, posForNameSplit);
	string firstValue;
	string operation;
	string secondValue;
	int posForOperationSplit;
	posForOperationSplit = line.find("+");
	if ((posForOperationSplit = line.find("+")) != std::string::npos)
	{
		SplitName(firstValue, operation, secondValue, posForNameSplit, posForOperationSplit, line);
		PrintError(fnName, firstValue, OperationType::ADD, secondValue);
	}
	else if ((posForOperationSplit = line.find("-")) != std::string::npos)
	{
		SplitName(firstValue, operation, secondValue, posForNameSplit, posForOperationSplit, line);
		PrintError(fnName, firstValue, OperationType::SUB, secondValue);
	}
	else if ((posForOperationSplit = line.find("*")) != std::string::npos)
	{
		SplitName(firstValue, operation, secondValue, posForNameSplit, posForOperationSplit, line);
		PrintError(fnName, firstValue, OperationType::MUL, secondValue);
	}
	else if ((posForOperationSplit = line.find("/")) != std::string::npos)
	{
		SplitName(firstValue, operation, secondValue, posForNameSplit, posForOperationSplit, line);
		PrintError(fnName, firstValue, OperationType::DIV, secondValue);
	}
	else
	{
		string var;
		var.append(line, posForNameSplit+1, line.length());
		if (!m_calculator.DefineFunction(fnName, var))
		{
			cout << "incorrect expression" << endl;
		}
	}
	return true;
}



void CWorkWithUI::SplitName(string &firstValue, string &operation, string &secondValue, const int &posForNameSplit, const int &posForOperationSplit, const string &line)
{
	firstValue.append(line, posForNameSplit + 1, posForOperationSplit - 1 - posForNameSplit);
	operation.append(line, posForOperationSplit, 1);
	secondValue.append(line, posForOperationSplit + 1, line.length());
}
CWorkWithUI::~CWorkWithUI()
{
}
