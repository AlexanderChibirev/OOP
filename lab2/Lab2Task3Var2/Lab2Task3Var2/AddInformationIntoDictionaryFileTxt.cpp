#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"

bool AddInformationIntoDictionaryFileTxt(const std::string &dictionaryName, std::map <std::string, std::string> &dictionaryMap)
{
	bool wasError = false;
	std::string wasSave;
	std::getline(std::cin, wasSave);
	std::ofstream dictionary(dictionaryName, std::ios_base::app);
	if (dictionary.is_open())
	{
		if (wasSave == "y" || wasSave == "Y")
		{
			for (auto it = dictionaryMap.begin(); it != dictionaryMap.end(); ++it)///вывод на экран
			{
				dictionary << std::endl;
				dictionary << it->first;
				dictionary << " ";
				dictionary << it->second;
			}
		}
		dictionary.close();
	}
	else 
	{
		wasError = true;
	}
	return wasError;
}