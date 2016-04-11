#include "stdafx.h"
#include "GetInformationAboutShapesFromFile.h"

string GetInformationAboutShapesFromFile(string & inputFileName, bool &wasError)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	string line;
	string result;
	if (!inputFile.is_open())
	{
		wasError == true;
	}
	else
	{
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			result += line + "\n";
		}
	}
	return result;
}
