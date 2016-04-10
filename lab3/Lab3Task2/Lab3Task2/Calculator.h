#pragma once


class CCalculator
{
public:
	CCalculator();
	~CCalculator();

	bool SetVariableIdentifier(const string & variable);
	bool SetVariableValue(const string & variable, const string & value);
	bool SetFunction(const string &fnName, const string &firstValue, const string &operand, const string & secondValue);

	map <string, double> GetVariableList() const; //printvars
	map <string, SecondMapInformation> GetFunctionList() const; //printfns

	double GetValueFn(const string & fnName);//print
	double GetValue(const string &varName);//print
private:
	double Calculation(double firstValue, const string & operand, double secondValue);
	double GetValueVariable(const string & varName) const;
	bool IsVariableDefine(const string & variable) const;
	bool IsFunctionDefine(const string & functionName) const;
private:
	map <string, double> m_variableNameList;
	map <string, SecondMapInformation> m_functionNameList;
};

