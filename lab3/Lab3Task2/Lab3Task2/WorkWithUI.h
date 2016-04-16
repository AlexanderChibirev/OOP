#pragma once
#include <boost/noncopyable.hpp>
#include <iostream>
#include "string"
#include "Difinition.h"

using namespace std;

class CCalculator;

class CWorkWithUI : boost::noncopyable
{
public:
	CWorkWithUI(CCalculator & calculator, std::istream & input, std::ostream & output);
	bool HandleCommand();
	~CWorkWithUI();
private:
	bool Var(std::istream & args);
	bool Let(std::istream & args);
	bool Fn(std::istream & args);
	bool Print(std::istream & args);
	bool Printvars(std::istream & args);
	bool Printfns(std::istream & args);
	void PrintError(const string &fnName, const string &firstValue, const OperationType &operation, const string & secondValue);
	void SplitName(string &firstValue, string &operation, string &secondValue,const int &posForNameSplit, const int &posForOperationSplit, const string &line);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;
	CCalculator & m_calculator;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};

