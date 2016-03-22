#include "stdafx.h"
#include "WriteInDictionaryMap.h"

bool WriteInDictionaryMap(const std::string &dictionaryName, std::map <std::string, std::string> &dictionaryMap)
{
	std::string lineStr;
	std::ifstream dictionary(dictionaryName);
	if (dictionary.is_open())
	{
		bool wasWord = false;
		while (std::getline(dictionary, lineStr))
		{
			size_t position = lineStr.find("||");
			std::string first;
			for (size_t i = 0; i < position; ++i)
			{
				first += lineStr[i];
			}
			std::string second;
			for (size_t i = position+2; i < lineStr.length(); ++i)
			{
				second += lineStr[i];
			}
			dictionaryMap[first] = second;
		}
	}
	else
	{
		return false;
	}
	return true;
}
