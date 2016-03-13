#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"

void AddInformationIntoDictionaryFileTxt(std::map <std::string, std::string> &dictionaryMap)
{
	std::cout << "В словарь были внесены изменения.Введите Y или y для сохранения перед выходом.\n" << ">";
	std::string wasExit;
	std::getline(std::cin, wasExit);
	std::ofstream dictionary("dictionary.txt", std::ios_base::app);
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