// Lab2Task3Var2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "WorkWithUser.h"
#include <windows.h>
#include "WriteInDictionaryMap.h"


//enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE, WORD_CAN_NOT_BE_FOUND };

int _tmain()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::map <std::string, std::string> dictionaryMap;
	std::map <std::string, std::string> dictionaryNewMap;
	std::string searchString;
	std::string searchStringToLower;
	std::string wordTranslate;
	std::string dictionaryName = "dictionary.txt";


	if(!WriteInDictionaryMap(dictionaryName, dictionaryMap))
	{
		std::cout << "CANT OPEN DICTIONARY\n";
		return 1;
	}
	WorkWithUser(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
	
	
	return 0;
}

