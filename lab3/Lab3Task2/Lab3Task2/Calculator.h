#pragma once


class CCalculator
{
public:
	CCalculator();
	~CCalculator();

	ErrorCode CheckInfoInVariableList(string variable);
	ErrorCode DeclareVariable(string variable);
	ErrorCode PutInfoInVariableList(string variable, string value);
	
	bool CheckVarOnCoincidence(string variable);
	bool CheckFunctionrOnCoincidence(string functionName);
	bool IsDoubleNumber(string const &str);
	bool  CheckValueForPrint(string);
	bool CheckNameFn(const string &fnName, const string &firstValue, const string &operand, const string & secondValue);

	void PutValueInVariableList(string variable, string value);
	void Print(string secondVar);
	void PrintVars() const;
	void Printfns();

	double Calculation(double firstValue, string operand, double secondValue);
		
	string GetFn(string fnName);
	string GetVariableValue(string varName) const;
private:
	SortMap m_variableNameList;
	map <string, SecondMapInformation, ByAlphabet> m_functionNameList;
	ErrorCode m_errorCode;
};

