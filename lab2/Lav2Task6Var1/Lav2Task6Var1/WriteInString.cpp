#include "stdafx.h"
#include "WriteInString.h"

bool WriteInString(std::string const &inputFileName, std::string &tpl)
{
	std::ifstream input(inputFileName);
	if (!input.is_open())
	{
		return true;
	}
	else
	{
		std::string lineStr;
		while (!input.eof())
		{
			std::getline(input, lineStr);
			tpl += lineStr;
			if (!input.eof())
			{
				tpl += "\n";
			}
		}
	}
	return false;
}
