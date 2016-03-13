#include "SearchWordsInDictionary.h"
#include "stdafx.h"

using namespace std;

enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE, WORD_CAN_NOT_BE_FOUND };

ERROR_CODE SearchWordsInDictionary(const string &dictionaryName, const string &searchString, string &wordTranslate, map <string, string> &dictionaryMap, string &searchStringToLower)
{	
	string lineStr;
	string lineStrToLower;
	ifstream dictionary(dictionaryName);
	if (dictionary.is_open()) // если файл открыт
	{
		bool wasWord = false;
		while (getline(dictionary, lineStr))
		{
			lineStrToLower = lineStr;
			transform(lineStrToLower.begin(), lineStrToLower.end(), lineStrToLower.begin(), tolower);
			if(lineStrToLower.find(searchStringToLower) != string::npos && lineStrToLower.find(searchStringToLower) == 0 && lineStrToLower[searchStringToLower.length()] == ' ')
			{
				int i = searchString.length() + 1;
				while (i != lineStr.length())
				{
					wordTranslate += lineStr[i];
					i++;
				}
				wasWord = true;
				break;
			}
		}
		if (!wasWord)
		{
			for (auto it = dictionaryMap.begin(); it != dictionaryMap.end(); ++it)///вывод на экран
			{
				string firstToLower = it->first;
				transform(firstToLower.begin(), firstToLower.end(), firstToLower.begin(), tolower);
				if (firstToLower == searchStringToLower)
				{
					wordTranslate = it->second;
					wasWord = true;
				}
			}
		}
		if (!wasWord)
		{
			return ERROR_CODE::WORD_CAN_NOT_BE_FOUND;
		}
	}
	else 
	{
		return ERROR_CODE::CANT_OPEN_FILE;
	}

	dictionary.close();
	return ERROR_CODE::ALL_IS_OK;
}