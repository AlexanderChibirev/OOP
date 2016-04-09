#pragma once


class CCalculator
{
public:
	CCalculator();
	~CCalculator();

	//ErrorCode CheckInfoInVariableList(const string & variable);
	bool IsDeclareVariable(const string & variable);
	bool PutInfoInVariableList(const string & variable, const string & value);
	
	bool  CheckValueForPrint(const string &varName);
	bool CheckNameFn(const string &fnName, const string &firstValue, const string &operand, const string & secondValue);

	void Print(double secondVar);
	void PrintVars() const;
	void Printfns();
	double Calculation(double firstValue, const string & operand, double secondValue);
	double GetFn(const string & fnName);
	double GetVariableValue(const string & varName) const;

private:
	void  CCalculator::SetVariableValue(const string & variable, double value);
	bool IsVariableDefine(const string & variable);
	bool IsFunctionDefine(const string & functionName);
private:
	map <string, double, ByAlphabet> m_variableNameList;
	map <string, SecondMapInformation, ByAlphabet> m_functionNameList;
	ErrorCode m_errorCode;
};

