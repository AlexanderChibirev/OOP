#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sys\stat.h>


using namespace std;
const int QUANTITY_ARGUMENTS = 5;

struct DataProgram
{
	string nameImputFile;
	string nameOutputFile;
	string searchStr;
	string replaceStr;

	ifstream fileImput;
	ofstream fileOutput;

	int flag = 0;
	int k = 0;
};

int ErrorExitProgram()
{
	exit(1);
}

void ErrorCheckingAndInitData(int argc, char** argv, DataProgram& dataProgram)
{
	struct stat fileSize;

	if (argc != 5) {
		cout << "Wrong amount of arguments was proposed" << endl;
		ErrorExitProgram();
	}
	dataProgram.nameImputFile = argv[1];
	dataProgram.nameOutputFile = argv[2];
	dataProgram.searchStr = argv[3];
	dataProgram.replaceStr = argv[4];

	stat(argv[1], &fileSize);
	if (fileSize.st_size > (2e+9))
	{
		cout << "file size larger than 2 GB" << endl;
		ErrorExitProgram();
	}
	if (dataProgram.searchStr == "")
	{
		cout << "you are looking for an empty string" << endl;
		ErrorExitProgram();
	}

	dataProgram.fileImput.open(dataProgram.nameImputFile);
	if (!dataProgram.fileImput.is_open())
	{
		cout << "Failed to open " << dataProgram.nameImputFile << " for reading" << endl;
		ErrorExitProgram();
	}
	dataProgram.fileOutput.open(dataProgram.nameOutputFile);
	if (!dataProgram.fileOutput.is_open())
	{
		cout << "Failed to open " << dataProgram.nameOutputFile << " for writing" << endl;
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

	while (!dataProgram.fileImput.eof())
	{
		getline(dataProgram.fileImput, lineStr);

		for (size_t i = 0; i <= lineStr.length(); i++)
		{
			for (int j = 0; j < lenSearchStr; j++)
			{
				if (i + j < lineStr.length())
				{
					if (lineStr[i + j] == dataProgram.searchStr[j])
					{
						countLettersInStr++;
					}
				}
			}

			if (countLettersInStr == lenSearchStr)
			{
				dataProgram.fileOutput << dataProgram.replaceStr;// << lineStr[i];
				countLettersInStr = 0;
				i = i + lenSearchStr - 1;
			}
			else
			{
				if (i == lineStr.length())
				{
					dataProgram.fileOutput << '\n';
				}
				else
				{
					dataProgram.fileOutput << lineStr[i];
				}
				countLettersInStr = 0;
			}

		}
	}
	dataProgram.fileImput.close();
	dataProgram.fileOutput.close();
	cout << "test passed successfully" << endl;
}

int main(int argc, char** argv)
{
	DataProgram dataProgram;
	ErrorCheckingAndInitData(argc, argv, dataProgram);
	BeginProgramm(dataProgram);
	return 0;
}