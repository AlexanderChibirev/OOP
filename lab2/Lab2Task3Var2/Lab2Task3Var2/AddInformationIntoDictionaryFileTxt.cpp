#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"

bool AddInformationIntoDictionaryFileTxt(const std::string &dictionaryName, std::map <std::string, std::string> &dictionaryMap)
{
	bool wasError = false;
	std::cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом.\n" << ">";
	std::string wasExit;
	std::getline(std::cin, wasExit);
	std::ofstream dictionary(dictionaryName, std::ios_base::app);
	if (dictionary.is_open())
	{
		if (wasExit == "y" || wasExit == "Y")
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