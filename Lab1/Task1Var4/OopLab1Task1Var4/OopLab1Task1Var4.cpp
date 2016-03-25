// OopLab1Task1Var4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h" 
#include <string> 
#include <iostream> 
#include <fstream> 
#include <sys\stat.h> 
#include <algorithm> 

using namespace std;


void WriteInOutputFile(ofstream & outputFile, const string & lineStr, bool &methodFind, string const &replaceStr)
{
	if (methodFind)
	{
		outputFile << lineStr << replaceStr;
	}
	else
	{
		outputFile << lineStr << endl;
	}

}
bool FindAndReplace(const string & lineStr, string const &searchStr,  string const &replaceStr, bool &methodFind, ofstream & outputFile)
{
	size_t position = 0;
	size_t afterChangingPosition = 0;
	while ((position = lineStr.find(searchStr, position)) != std::string::npos)
	{
		methodFind = true;
		WriteInOutputFile(outputFile, lineStr.substr(afterChangingPosition, position - afterChangingPosition), methodFind, replaceStr);
		position += searchStr.length();
		afterChangingPosition = position;
	}
	if (lineStr != "")
	{
		methodFind = false;
		WriteInOutputFile(outputFile, lineStr.substr(afterChangingPosition), methodFind, replaceStr);
	}
	if (!outputFile.flush())
	{
		
		return false;
	};
	return true;
}
enum class ErrorCode 
{	
	FILE_SIZE_LARGER_THAN_2GB,
	CANT_OPEN_INPUT_FILE, 
	IS_NOT_ENOUGH_SPACE_ON_THE_DISC,
	WITHOUT_ERROR
};
ErrorCode BeginProgramm(char const *inputFileName, string const &outputFileName, string const &searchStr, string const &replaceStr)
{
	struct stat fileSize;
	stat(inputFileName, &fileSize);
	if (fileSize.st_size > 2147483647)
	{	
		return ErrorCode::FILE_SIZE_LARGER_THAN_2GB;
	}
	
	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Failed to open input file for reading\n";
	}

	ofstream outputFile;
	outputFile.open(outputFileName);

	string lineStr;
	bool methodFind;
	while (!inputFile.eof())
	{
		getline(inputFile, lineStr);
		if (searchStr.empty() || replaceStr.empty() || lineStr.empty())
		{
			methodFind = false;
			outputFile << lineStr << endl;
		}
		else
		{
			if (!FindAndReplace(lineStr, searchStr, replaceStr, methodFind, outputFile))
			{
				return ErrorCode::IS_NOT_ENOUGH_SPACE_ON_THE_DISC;
			}
		}
	}
	return ErrorCode::WITHOUT_ERROR;
}

int main(int argc, char** argv)
{
	if (argc != 5)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file> <search string> <replace string>'";
		return 1;
	}

	char* inputFileName = argv[1];
	string outputFileName = argv[2];
	string searchStr = argv[3];
	string replaceStr = argv[4];
	switch (BeginProgramm(inputFileName, outputFileName, searchStr, replaceStr))
	{
		case ErrorCode::FILE_SIZE_LARGER_THAN_2GB:
			cout << "file size larger than 2 GB\nUse a file size less then 2GB please\n";
			return 1;
		case ErrorCode::CANT_OPEN_INPUT_FILE:
			cout << "Failed to open input file for reading\n";
			return 1;
		case ErrorCode::IS_NOT_ENOUGH_SPACE_ON_THE_DISC:
			cout << "is not enough space on the disc\nFree up disk space, please";
			return 1;
		default:
			break;
	}
	return 0;
}