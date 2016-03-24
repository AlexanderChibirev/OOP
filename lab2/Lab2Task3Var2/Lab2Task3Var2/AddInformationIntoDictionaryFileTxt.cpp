#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"

bool AddInformationIntoDictionaryFileTxt(const std::string &dictionaryName, std::map <std::string, std::string> &newDictionary)
{
	bool wasError = false;
	std::ofstream dictionary(dictionaryName, std::ios_base::app);
	if (dictionary.is_open())
	{
		for (auto it = newDictionary.begin(); it != newDictionary.end(); ++it)///вывод на экран
		{
			dictionary << it->first << "||" << it->second << std::endl;
		}
		dictionary.close();
	}
	else 
	{
		wasError = true;
	}
	return wasError;
}