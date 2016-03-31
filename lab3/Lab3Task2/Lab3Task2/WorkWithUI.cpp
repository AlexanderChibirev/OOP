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
	//	{ "let", bind(&CWorkWithUI::Let, this, _1) },
	//	{ "fn", bind(&CWorkWithUI::Fn, this, _1) },
	//	{ "print", bind(&CWorkWithUI::Print, this, _1) },
		{ "printvars", bind(&CWorkWithUI::Printvars, this, _1) },
	//	{ " printfns", bind(&CWorkWithUI::Printfns, this, _1) },
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
	getline(args, line);
	m_calculator.PutInfoInVariableList(line, "nan");
	return true;
}
bool CWorkWithUI::Printvars(std::istream & args) 
{
	m_calculator.PrintVars();
	return true;
}

CWorkWithUI::~CWorkWithUI()
{
}
