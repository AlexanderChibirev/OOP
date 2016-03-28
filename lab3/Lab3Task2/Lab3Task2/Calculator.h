#pragma once
class CCalculator
{
public:
	CCalculator();
	~CCalculator();
	void PutInfoInVariableList(string variable, string value);
	void PrintVars();
private:
	map <string, string, ByLength> m_variableNameList;
	map <string, string, ByLength> m_functionNameList;
};

