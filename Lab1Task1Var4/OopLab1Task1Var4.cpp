#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sys\stat.h>


using namespace std;


const int QUANTITY_ARGUMENTS = 5;

struct DataProgram
{
	string inputFileName;
	string outputFileName;
	string searchStr;
	string replaceStr;

	ifstream inputFile;
	ofstream outputFile;
};

void ErrorExitProgram()
{
	exit(1);
}

void ErrorCheckingAndInitData(int argc, char** argv, DataProgram& dataProgram)
{
	struct stat fileSize;

	if (argc != 5) {
		cout << "Wrong amount of arguments was proposed" << endl;
		cout << "Enter a correct arguments amount please, for example:" << endl;
		cout << "'programm.exe <input file> <output file> <search string> <replace string>'" << endl;
		ErrorExitProgram();
	}
	dataProgram.inputFileName = argv[1];
	dataProgram.outputFileName = argv[2];
	dataProgram.searchStr = argv[3];
	dataProgram.replaceStr = argv[4];

	stat(argv[1], &fileSize);
	if (fileSize.st_size > 2147483648)
	{
		cout << "file size larger than 2 GB" << endl;
		cout << "Use a file size less then 2gb please" << endl;
		ErrorExitProgram();
	}

	dataProgram.inputFile.open(dataProgram.inputFileName);
	if (!dataProgram.inputFile.is_open())
	{
		cout << "Failed to open " << dataProgram.inputFileName << " for reading" << endl;
		cout << "Enter a correct name of an input.txt file please" << endl;
		ErrorExitProgram();
	}
	dataProgram.outputFile.open(dataProgram.inputFileName);
	if (!dataProgram.outputFile.is_open())
	{
		cout << "Failed to open " << dataProgram.inputFileName << " for writing" << endl;
		cout << "Enter a correct name of an output.txt file please" << endl;
		ErrorExitProgram();
	}
}

void BeginProgramm(DataProgram& dataProgram)
{
	string lineStr;
	string outPut;

	size_t lenSearchStr = dataProgram.searchStr.length();
	size_t lenReplaceStr = dataProgram.replaceStr.length();

	int countLettersInStr = 0;

	while (!dataProgram.inputFile.eof())
	{
		getline(dataProgram.inputFile, lineStr);

		for (size_t i = 0; i <= lineStr.length(); i++)
		{
			for (int j = 0; j < lenSearchStr; j++)
			{
				if ((i + j < lineStr.length()) && (lineStr[i + j] == dataProgram.searchStr[j]))
				{
					countLettersInStr++;
				}
			}

			if (countLettersInStr == lenSearchStr && dataProgram.searchStr != "")
			{
				dataProgram.outputFile << dataProgram.replaceStr;// << lineStr[i];
				countLettersInStr = 0;
				i = i + lenSearchStr - 1;
			}
			else
			{
				if (i == lineStr.length())
				{
					dataProgram.outputFile << '\n';
				}
				else
				{
					dataProgram.outputFile << lineStr[i];
				}
				countLettersInStr = 0;
			}

		}
	}
	dataProgram.inputFile.close();
	dataProgram.outputFile.close();
	cout << "test passed successfully" << endl;
}

int main(int argc, char** argv)
{
	DataProgram dataProgram;
	ErrorCheckingAndInitData(argc, argv, dataProgram);
	BeginProgramm(dataProgram);
	return 0;
}
