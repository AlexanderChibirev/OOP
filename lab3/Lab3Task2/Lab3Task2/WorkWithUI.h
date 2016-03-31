#pragma once
#include <boost/noncopyable.hpp>

class CCalculator;

class CWorkWithUI : boost::noncopyable
{
public:
	CWorkWithUI(CCalculator & calculator, std::istream & input, std::ostream & output);
	bool HandleCommand();
	~CWorkWithUI();
private:
	bool Var(std::istream & args);
	//bool Let(std::istream & args);
	//bool Fn(std::istream & args);
	//bool Print(std::istream & args);
	bool Printvars(std::istream & args);
	//bool Printfns(std::istream & args);
private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	CCalculator & m_calculator;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};

