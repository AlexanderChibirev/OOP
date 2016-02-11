#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sys\stat.h>
#include <algorithm>

using namespace std;


const int QUANTITY_ARGUMENTS = 5;

void ErrorProgram(string text, bool & error)
{
	cout << text << endl;
	error = true;
}

void BeginProgramm(char const *inputFileName, string const &outputFileName, string const &searchStr, string const &replaceStr, bool & error)
{
	struct stat fileSize;
	stat(inputFileName, &fileSize);

	if (fileSize.st_size > 2147483648)
	{
		ErrorProgram("file size larger than 2 GB\nUse a file size less then 2gb please\n", error);
	}
	ifstream inputFile;
	ofstream outputFile;

	string lineStr;
	string outPut;

	size_t lenSearchStr = searchStr.length();
	size_t lenReplaceStr = replaceStr.length();

	size_t position = 0;
	size_t oldPosition = 0;

	int countLettersInStr = 0;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		inputFile.close();
		outputFile.close();
		ErrorProgram("Failed to open input file for reading\n", error);
	}
	if (error == false)
	{
		outputFile.open(outputFileName);
		while (!inputFile.eof())
		{
			getline(inputFile, lineStr);
			if (searchStr.empty() || replaceStr.empty() || lineStr.empty())
			{
				outputFile << lineStr << endl;;
			}
			else
			{
				oldPosition = 0;
				position = 0;
				while ((position = lineStr.find(searchStr, position)) != std::string::npos) {
					outputFile << lineStr.substr(oldPosition, position - oldPosition) + replaceStr;
					position += searchStr.length();
					oldPosition = position;
				}
				if (lineStr != "")
				{
					outputFile << lineStr.substr(oldPosition) << endl;
				}
			}
		}
		cout << "test passed successfully" << endl;
	}
	inputFile.close();
	outputFile.close();


}

int main(int argc, char** argv)
{
	bool error = false;
	if (argc != 5)
	{
		ErrorProgram("Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n'programm.exe <input file> <output file> <search string> <replace string>'", error);
		return 1;
	}
	char* inputFileName = argv[1];
	string outputFileName = argv[2];
	string searchStr = argv[3];
	string replaceStr = argv[4];

	if (error == false)
	{
		BeginProgramm(inputFileName, outputFileName, searchStr, replaceStr, error);
	}
	else
	{
		cout << "This program is completed with an error" << endl;
	}
	return 0;
}
