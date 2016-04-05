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
		{ "var", bind(&CWorkWithUI::Var, this, _1) },
		{ "let", bind(&CWorkWithUI::Let, this, _1) },
		{ "fn", bind(&CWorkWithUI::Fn, this, _1) },
		{ "print", bind(&CWorkWithUI::Print, this, _1) },
		{ "printvars", bind(&CWorkWithUI::Printvars, this, _1) },
		{ "printfns", bind(&CWorkWithUI::Printfns, this, _1) },
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
	ErrorCode errorCode;
	errorCode = m_calculator.DeclareVariable(line);
	if (errorCode == FIRST_SYMBOL_IS_NOT_LETTER)
	{
		cout << "first symbol variable name is not letter, variable name must not start with a digit\n";
		return false;
	}
	else if(errorCode == VAR_HAS_ALREADY_BEEN_DECLARED)
	{
		cout << "it's variable has already been declared\n";
	}
	return true;
}
bool CWorkWithUI::Printvars(std::istream & args) 
{
	m_calculator.PrintVars();
	return true;
}

bool  CWorkWithUI::Print(std::istream & args)
{
	string line;
	args >> line;
	if (!m_calculator.CheckValueForPrint(line))
	{
		cout << "not found value\n";
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
	ErrorCode errorCode;
	errorCode = m_calculator.PutInfoInVariableList(variable, value);
	if(errorCode == INCORRECT_ENTER)
	{
		cout << "incorrect entry, read help please\n";//добавить функцию которая выводит запись о том, как правильно вводить данные
	}
	return true;
}

bool CWorkWithUI::Printfns(std::istream & args)
{
	m_calculator.Printfns();
	return true;
}

void CWorkWithUI::PrintError(const string &fnName, const string &firstValue, const string &operand, const string & secondValue)
{
	if (!m_calculator.CheckNameFn(fnName, firstValue, operand, secondValue))
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
	string operand;
	string secondValue;
	int posForOperandSplit;
	posForOperandSplit = line.find("+");
	if (posForOperandSplit == std::string::npos)
	{
		posForOperandSplit = line.find("-");
		if (posForOperandSplit == std::string::npos)
		{
			posForOperandSplit = line.find("*");
			if (posForOperandSplit == std::string::npos)
			{
				posForOperandSplit = line.find("/");
				if (posForOperandSplit == std::string::npos)
				{
					string var;
					var.append(line, posForNameSplit+1, line.length());
					//получим значение секонд от имени функции разобьем ее на фест секон операнд и ввызовем задать функцию
					PrintError(fnName, var, "funWithOneValue", var);
				}
				else 
				{
					SplitName(firstValue, operand, secondValue, posForNameSplit, posForOperandSplit, line);
					PrintError(fnName, firstValue, operand, secondValue);
				}
			}
			else 
			{
				SplitName(firstValue, operand, secondValue, posForNameSplit, posForOperandSplit, line);
				PrintError(fnName, firstValue, operand, secondValue);
			}
		}
		else
		{
			SplitName(firstValue, operand, secondValue, posForNameSplit, posForOperandSplit, line);
			PrintError(fnName, firstValue, operand, secondValue);
		}
	}
	else
	{
		SplitName(firstValue, operand, secondValue, posForNameSplit, posForOperandSplit, line);
		PrintError(fnName, firstValue, operand, secondValue);
	}
	return true;
}

void CWorkWithUI::SplitName(string &firstValue, string &operand, string &secondValue, const int &posForNameSplit, const int &posForOperandSplit, const string &line)
{
	firstValue.append(line, posForNameSplit + 1, posForOperandSplit - 1 - posForNameSplit);
	operand.append(line, posForOperandSplit, 1);
	secondValue.append(line, posForOperandSplit + 1, line.length());
}
CWorkWithUI::~CWorkWithUI()
{
}
