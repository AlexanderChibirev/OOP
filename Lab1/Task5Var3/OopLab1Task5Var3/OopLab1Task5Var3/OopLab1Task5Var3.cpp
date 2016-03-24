// OopLab1Task5Var3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>


using namespace std;


void FillArea(vector<string> & area, vector<pair<int, int>> startDots)
{
	while (startDots.size() > 0)
	{
		int row = startDots[0].first;
		int col = startDots[0].second;
		if (area[row][col] != '.' && area[row][col] != '#' && row < 101 && col < 101)
		{
			area[row][col] = '.';
			startDots.push_back(make_pair(row - 1, col));
			startDots.push_back(make_pair(row + 1, col));
			startDots.push_back(make_pair(row, col - 1));
			startDots.push_back(make_pair(row, col + 1));
		}
		startDots.erase(startDots.begin());
	}
}

void FoundBeginDots(string str, vector< pair<int, int> > & startDots, int numLine, int lenStr)
{
	if (str.find('0') < lenStr)
	{
		startDots.push_back(pair<int, int>(numLine, static_cast<int>(lenStr - str.length() + str.find('0'))));
		str = str.substr(str.find('0') + 1);
		FoundBeginDots(str, startDots, numLine, lenStr);
	}
}
vector<pair<int, int>> GetPositionDots(vector<string> const &area, vector< pair<int, int> > startDots)
{
	int numLine = 0;
	for (auto &it : area)
	{
		numLine++;
		FoundBeginDots(it, startDots, numLine, int(it.length()));
	}
	return startDots;
}

bool IsCorrectSymbol(const string & line)
{
	bool wasError = false;
	for (auto symbol : line)
	{
		if ((symbol != ' ' && symbol != '0' && symbol != '#' && symbol != '\n' && symbol != '\0'))
		{
			wasError = true;
		}
	}
	return wasError;
}


void StartInitialArea(string &latticeSet, string &sizeArea, vector<string> &area)
{
	for (int i = 0; i < 100; i++)
	{
		sizeArea += " ";
	}
	for (int i = 0; i < 102; i++)
	{
		latticeSet += "#";
	}
	area.push_back(latticeSet + "\n");
}

void EndInitialArea(string &latticeSet, string &sizeArea, vector<string> &area)
{
	while (area.size() < 102)
	{
		area.push_back("#" + sizeArea + "#" + "\n");
		if (area.size() == 101)
		{
			area.push_back(latticeSet);
		}
	}
}

void BaseInitialArea(vector<string> &area, string &line)
{
	line = "#" + line;
	if (line.length() < 100)
	{
		for (size_t i = line.length(); i < 101; i++)
		{
			line += " ";
			if (i == 100)
			{
				line += "#";
			}
		}
	}
	area.push_back(line + "\n");
}


enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE, INVALID_CHARACTER, EMPTY_FILE};

ERROR_CODE GetArea(const string & fileName,	vector<string> &area)
{
	string sizeArea;
	string latticeSet;
	StartInitialArea(latticeSet, sizeArea, area);

	ifstream areaFileInput(fileName);
	if (areaFileInput.is_open())
	{
		string line;
		while (getline(areaFileInput, line))
		{
			if (IsCorrectSymbol(line))
			{
				return ERROR_CODE::INVALID_CHARACTER;
			}
			BaseInitialArea(area, line);
		}
		if (area.size() == 1)
		{
			return ERROR_CODE::EMPTY_FILE;
		}
		EndInitialArea(latticeSet, sizeArea, area);
	}
	else
	{
		return ERROR_CODE::CANT_OPEN_FILE;
	}
	areaFileInput.close();
	return ERROR_CODE::ALL_IS_OK;
}

void WriteInOutputFile(vector<string> area, const string outputFileName)
{
	ofstream outFile(outputFileName);
	for (int i = 1; i < 101; i++)
	{
		string rowString;
		rowString = area[i];
		for (int g = 1; g < 101; g++)
		{
			outFile << rowString[g];
			if (g == 100) outFile << "\n";
		}
	}
}
vector<string> GetAreaFinish(vector<pair<int, int>> startDots, vector<string> area)
{
	FillArea(area, startDots);
	for (unsigned i = 0; i < startDots.size(); ++i)
	{
		area[startDots[i].first][startDots[i].second] = '0';
	}
	return area;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n'programm.exe <input file> <output file>";
		return 1;
	}

	string inputFileName = argv[1];
	vector<string> area;

	switch (GetArea(inputFileName, area))
	{
		case ERROR_CODE::CANT_OPEN_FILE:
			cout << "cant open file";
			return 1;
		case ERROR_CODE::INVALID_CHARACTER:
			cout << "invalid character";
			return 1;
		case ERROR_CODE::EMPTY_FILE:
			cout << "your input file empty";
			return 1;
		default:
			break;
	}

	vector< pair<int, int> > startDots;
	string outputFileName = argv[2];

	if (GetPositionDots(area, startDots).empty())
	{
		WriteInOutputFile(area, outputFileName);
		return 0;
	}
	startDots = GetPositionDots(area, startDots);
	area = GetAreaFinish(startDots, area);
	WriteInOutputFile(area, outputFileName);
	return 0;
}

