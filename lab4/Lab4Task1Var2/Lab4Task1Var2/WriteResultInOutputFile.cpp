#include "stdafx.h"
#include "WriteResultInOutputFile.h"


bool WriteResultInOutputFile(const string &result, const string &outputFileName)
{
	ofstream outputFile;
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		return false;
	}
	outputFile << result;
	return true;
}
