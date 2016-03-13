#include "stdafx.h"
#include "WorkWithUser.h"
#include "SearchWordsInDictionary.h"
#include "AddInformationIntoDictionaryFileTxt.h"


bool WorkWithUser(std::string &searchString, std::string &wordTranslate, std::map <std::string, std::string> &dictionaryMap, std::string &searchStringToLower)
{
	bool wasError = false;
	std::cout << ">";
	std::getline(std::cin, searchString);
	searchStringToLower = searchString;
	std::transform(searchStringToLower.begin(), searchStringToLower.end(), searchStringToLower.begin(), tolower);
	if (searchString == "..." && (!dictionaryMap.empty()))
	{
		AddInformationIntoDictionaryFileTxt(dictionaryMap);
		searchString = "...";
	}
	else if(searchString != "" && searchString != "...")
	{
		switch (SearchWordsInDictionary(searchString, wordTranslate, dictionaryMap,searchStringToLower))
		{
			case ALL_IS_OK: 
			{
				std::cout << wordTranslate << std::endl;
				wordTranslate.clear();
				WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower);
				break;
			}
			case CANT_OPEN_FILE:
			{
				std::cout << "CANT_OPEN_FILE\n";
				wasError = true;
				break;
			}
			case WORD_CAN_NOT_BE_FOUND:
			{
				std::cout << "Неизвестное слово " << searchString << ". Введите перевод или точку для отказа.\n>";
				std::getline(std::cin, wordTranslate);
				if (wordTranslate != "." && wordTranslate != "...")
				{
					dictionaryMap.insert(std::pair<std::string, std::string>(searchString, wordTranslate));
					std::cout << "Слово " << searchString << " сохранено в словаре как " << wordTranslate << std::endl;
					wordTranslate.clear();
					WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower);
				}
				else
				{
					wordTranslate.clear();
					WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower);
				}	
				break;
			}
		}
	}	
	return wasError;
}