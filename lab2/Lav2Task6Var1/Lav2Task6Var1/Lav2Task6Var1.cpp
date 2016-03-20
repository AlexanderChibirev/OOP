#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <algorithm>


using namespace std;


enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE};

ERROR_CODE WriteInOutputFile(string const &outputFileName, const string & tpl)
{
	ofstream output(outputFileName);
	
	if (!output.is_open())
	{
		return ERROR_CODE::CANT_OPEN_FILE;
 	}
	else
	{
		output << tpl;
	}
	return ERROR_CODE::ALL_IS_OK;
}

struct CStrCmp
{
	bool operator()(
		const string Left,
		const string Right
		) const
	{
		return (Left.size() > Right.size());
	}
};

string FindAndReplace(const string & tpl, const string & searchString, const string & replaceString)
{
	if (searchString.empty())
	{
		return tpl;
	}
	string newTpl;

	size_t position = 0;
	size_t afterChangingPosition = 0;

	while ((position = tpl.find(searchString, position)) != string::npos)
	{
		newTpl.append(tpl, afterChangingPosition, position - afterChangingPosition).append(replaceString);
		position += searchString.length();
		afterChangingPosition = position;
	}
	newTpl.append(tpl, afterChangingPosition);
	return newTpl;
}

string ExpandTemplate(string const& tpl, map< string, string, CStrCmp > const& params)
{
	string newTpl;
	for (auto it = params.begin(); it != params.end(); ++it)
	{	
		newTpl = FindAndReplace(tpl, it->first, it->second);
	}
	return newTpl;
}


ERROR_CODE ReadInFile(string const &inputFileName, string &tpl)
{
	ifstream input(inputFileName);
	if (!input.is_open()) 
	{
		return ERROR_CODE::CANT_OPEN_FILE;
	}
	else
	{
		string lineStr;
		while(!input.eof())
		{
			getline(input, lineStr);
			tpl += lineStr + "\n";
		}
	}
	return ERROR_CODE::ALL_IS_OK;
}


int main(int argc, char** argv)
{
	
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);	
	
	if (argc < 5 || argc % 2 == 0)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file> <search string> <replace string> ....'";
		return 1;
	}

	string inputFileName = argv[1];
	string tpl;

	switch (ReadInFile(inputFileName,tpl))
	{
		case ERROR_CODE::CANT_OPEN_FILE:
			return 1;
	}
	
	map <string, string, CStrCmp> params;
//	vector <string> paramsFirst;
	for (int i = 3; i < argc - 1; i = i + 2)
	{
		string search = argv[i];
//		paramsFirst.push_back(argv[i]);
		string reaplace = argv[i + 1];
		params.insert(pair <string, string> ( search, reaplace ) );
	}

	tpl = ExpandTemplate(tpl, params);
	
	string outputFileName = argv[2];

	switch (WriteInOutputFile(outputFileName, tpl))
	{
		case ERROR_CODE::CANT_OPEN_FILE:
			return 1;
	}

	//sort(paramsFirst.begin(), paramsFirst.end(),
	//	[](const string & first, const string & second) -> bool
	//{
	//	return first.size() > second.size();
	//});
	
	//for (size_t i = 0; i < paramsFirst.size(); ++i)
	//{
	//	for (auto it = paramsNotSort.begin(); it != paramsNotSort.end(); ++it)///вывод на экран
	//	{
	//		if (it->first == paramsFirst[i])
	//		{
	//			
	//		}
	//	}
	//}
	//for (auto it = params.begin(); it != params.end(); ++it)
	//{
	//	cout << (*it).first << " : " << (*it).second << endl;
	//}

    return 0;
}
