// OopLab1Task5Var3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

const char BEGIN_CHAR = '0';
const char FILL_CHAR = ' ';
const char FILL_TO_CHAR = '.';


using namespace std;


void FillArea(vector<string> & area, vector<pair<int, int>> startDots, int row, int col)
{
	//if (row > 0 && col > 1 && row < area.size() && area[row][col] == FILL_CHAR)
	//{
	//	area[row][col] = FILL_TO_CHAR;
	//	if (area[row + 1][col] != '#')
	//		FillArea(area, startDots, row + 1, col);
	//	if (area[row - 1][col] != '#')
	//		FillArea(area, startDots, row - 1, col);
	//	if (area[row][col - 1] != '#')
	//		FillArea(area, startDots, row, col - 1);
	//	if (area[row][col + 1] != '#')
	//		FillArea(area, startDots, row, col + 1);
	//}
	while (startDots.size() > 0)
	{
		int row = startDots[0].first;
		int col = startDots[0].second;
		if (area[col][row] != '.' && area[col][row] != '#')
		{
			area[col][row] = '.';
			if (row > 0)
			{
				startDots.push_back(make_pair(row, col - 1));
			}
			if (row < 101)
			{
				startDots.push_back(make_pair(row, col + 1));
			}
			if (col > 0)
			{
				startDots.push_back(make_pair(row-1, col));
			}
			if (col < 101)
			{
				startDots.push_back(make_pair(row+1, col));
			}
		}
		//else area[col][row] = '.';

		startDots.erase(startDots.begin());
	}
}
vector<pair<int, int>> GetPositionDots(vector<string> area, vector< pair<int, int> > startDots)
{
	for (int numLine = 0; numLine < area.size(); numLine++)
	{
		int positionStartDots = int(area[numLine].find(BEGIN_CHAR));
		if (positionStartDots != string::npos)
		{
			startDots.push_back(pair<int, int>(numLine, positionStartDots));
		}
	}
	return startDots;
}
vector<string> GetArea(const string & fileName)
{
	string latticeSet;
	string sizeArea;
	vector<string> area;
	for (int i = 0; i < 100; i++)
	{
		sizeArea += " ";
	}
	for (int i = 0; i < 102; i++)
	{
		latticeSet += "#";

	}
	area.push_back(latticeSet + "\n");
	ifstream areaFileInput(fileName);
	if (areaFileInput.is_open())
	{
		string line;
		while (getline(areaFileInput, line))
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
		while (area.size() < 102)
		{
			area.push_back("#" + sizeArea + "#" + "\n");
			if (area.size() == 101)
			{
				area.push_back(latticeSet);
			}
		}
	}
	else
	{
		cout << "error with opening input file";
		area.push_back("error");
	}

	areaFileInput.close();
	return area;
}
void WriteInOutputFile(vector<string> area, const string outputFileName)
{
	ofstream outFile(outputFileName);
	for (int i = 1; i < area.size() - 1; i++)
	{
		string rowString;
		rowString = area[i];
		for (int g = 1; g < area.size() - 1; g++)
		{
			outFile << rowString[g];
			if (g == 100) outFile << "\n";
		}
	}
}
vector<string> GetAreaFinish(vector<pair<int, int>> startDots, vector<string> area)
{
	for (unsigned i = 0; i < startDots.size(); ++i)
	{
	/*const char BEGIN_CHAR = '0';
	 const char FILL_CHAR = ' ';
	 const char FILL_TO_CHAR = '.';*/
		area[startDots[i].first][startDots[i].second] = FILL_CHAR;
		FillArea(area, startDots, startDots[i].first, startDots[i].second);
		area[startDots[i].first][startDots[i].second] = BEGIN_CHAR;
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
	string outputFileName = argv[2];
	vector< pair<int, int> > startDots;
	vector<string> area;
	area = GetArea(inputFileName);
	WriteInOutputFile(area, outputFileName);
	if (area[0] == "error")
	{
		return 1;
	}
	if (area.empty())
	{
		cout << "your input file empty";
		return 0;
	}
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

