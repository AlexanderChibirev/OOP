#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"

void WorkWithUser(const std::string &dictionaryName, std::string &searchString, std::string &wordTranslate, std::map <std::string, std::string> &dictionaryMap, std::string &searchStringToLower, std::map <std::string, std::string> dictionaryNewMap)
{
	bool wasError = false;
	std::cout << ">";
	std::getline(std::cin, searchString);
	searchStringToLower = searchString;
	std::transform(searchStringToLower.begin(), searchStringToLower.end(), searchStringToLower.begin(), tolower);
	if (searchString == "..." && (!dictionaryNewMap.empty()))
	{
		std::cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n>";
		std::string wasSave;
		std::getline(std::cin, wasSave);
		if (wasSave == "y" || wasSave == "Y")
		{
			AddInformationIntoDictionaryFileTxt(dictionaryName, dictionaryNewMap);
		}//
	}
	else if(searchString != "" && searchString != "...")
	{
		switch (SearchWordsInDictionary(dictionaryName, searchString, wordTranslate, dictionaryMap,searchStringToLower))
		{
			case ALL_IS_OK: 
			{
				std::cout << wordTranslate << std::endl;
				wordTranslate.clear();
				WorkWithUser(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower,dictionaryNewMap);
				break;
			}
			case WORD_CAN_NOT_BE_FOUND:
			{
				std::cout << "Неизвестное слово " << searchString << ". Введите перевод или пустую строку для отказа.\n>";
				std::getline(std::cin, wordTranslate);
				if (wordTranslate != "")
				{
					dictionaryNewMap.insert(std::pair<std::string, std::string>(searchString, wordTranslate));
					dictionaryMap.insert(std::pair<std::string, std::string>(searchString, wordTranslate));
					std::cout << "Слово " << searchString << " сохранено в словаре как " << wordTranslate << std::endl;
				}
				wordTranslate.clear();
				WorkWithUser(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
				break;
			}
		}
	}
	else if (searchString == "...")
	{
		return;
	}
	else 
	{
		WorkWithUser(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
	}
}