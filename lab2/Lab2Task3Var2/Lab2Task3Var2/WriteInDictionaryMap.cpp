#include "stdafx.h"
#include "WriteInDictionaryMap.h"


bool WriteInDictionaryMap(const string &dictionaryName, SSMap &dictionaryMap)
{
	string lineStr;
	ifstream dictionary(dictionaryName);
	if (dictionary.is_open())
	{
		bool wasWord = false;
		int count = 1;
		string firstWord;
		while (getline(dictionary, lineStr))
		{
			if (count % 2 == 0)
			{
				dictionaryMap[firstWord] = lineStr;
			}
			else
			{
				firstWord = lineStr;
			}
			++count;
		}
	}
	else
	{
		return false;
	}
	return true;
}