// Lab2Task3Var2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <windows.h>
#include "AddInformationIntoDictionaryFileTxt.h"
#include "SearchWordsInDictionary.h"
#include "WriteInDictionaryMap.h"



void WorkWithUser( string &searchString,  string &wordTranslate, SSMap &dictionaryMap, string &searchStringToLower, SSMap dictionaryNewMap)
{
	bool wasError = false;
	cout << ">";
	getline(cin, searchString);
	searchStringToLower = searchString;
	transform(searchStringToLower.begin(), searchStringToLower.end(), searchStringToLower.begin(), tolower);
	if (searchString == "..." && (!dictionaryNewMap.empty()))
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n>";
		string wasSave;
		getline(cin, wasSave);
		if (wasSave == "y" || wasSave == "Y")
		{
			AddInformationIntoDictionaryFileTxt(dictionaryNewMap);
		}
	}
	else if (searchString != "" && searchString != "...")
	{
		wordTranslate = SearchWordsInDictionary(searchString, dictionaryMap, searchStringToLower);
		if (!wordTranslate.empty())
		{
			cout << wordTranslate << endl;
			wordTranslate.clear();
			WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
		}
		else
		{
			cout << "Неизвестное слово " << searchString << ". Введите перевод или пустую строку для отказа.\n>";
			getline(cin, wordTranslate);
			if (wordTranslate != "")
			{
				dictionaryNewMap.insert(pair<string, string>(searchString, wordTranslate));
				dictionaryMap.insert(pair<string, string>(searchString, wordTranslate));
				cout << "Слово " << searchString << " сохранено в словаре как " << wordTranslate << endl;
			}
			wordTranslate.clear();
			WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
		}
	}
	else if (searchString == "...")
	{
		return;
	}
	else
	{
		WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);
	}
}




int _tmain()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	SSMap dictionaryMap;
	SSMap dictionaryNewMap;
	string searchString;
	string searchStringToLower;
	string wordTranslate;
	string dictionaryName = "dictionary.txt";


	if(!WriteInDictionaryMap(dictionaryName, dictionaryMap))
	{
		cout << "CANT OPEN DICTIONARY\n";
		return 1;
	}
	WorkWithUser(searchString, wordTranslate, dictionaryMap, searchStringToLower, dictionaryNewMap);

	return 0;
}

