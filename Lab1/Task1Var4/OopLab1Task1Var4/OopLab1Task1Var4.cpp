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
	bool wasError = false;
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
		cout << "is not enough space on the disc\nFree up disk space, please";
		wasError = true;
	};
	return wasError;
}

bool BeginProgramm(char const *inputFileName, string const &outputFileName, string const &searchStr, string const &replaceStr)
{
	bool wasError = false;
	struct stat fileSize;
	stat(inputFileName, &fileSize);

	if (fileSize.st_size > 2147483647)
	{
		cout << "file size larger than 2 GB\nUse a file size less then 2GB please\n";
		wasError = true;
	}
	if (!wasError)
	{
		ifstream inputFile;
		ofstream outputFile;

		string lineStr;
		bool methodFind;

		inputFile.open(inputFileName);
		if (!inputFile.is_open())
		{
			cout << "Failed to open input file for reading\n";
			wasError = true;
		}
		if (!wasError)
		{
			outputFile.open(outputFileName);
			if (!wasError)
			{
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
						wasError = FindAndReplace(lineStr, searchStr, replaceStr, methodFind, outputFile);
					}
				}
			}
		}
	}
	return wasError;
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
	if (BeginProgramm(inputFileName, outputFileName, searchStr, replaceStr))
	{
		cout << "This program is completed with an error" << endl;
		return 1;
	}
	return 0;
}