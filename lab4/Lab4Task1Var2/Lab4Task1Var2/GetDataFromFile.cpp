#include "stdafx.h"
#include "GetDataFromFile.h"

string GetDataFromFile(string & inputFileName)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Failed to open input file for reading\n";
	}
	string line;
	string result;
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		result += line + "\n";
	}
	return result;
}
