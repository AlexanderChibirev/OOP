// Lab2Task3Var2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <windows.h>



using namespace std;

typedef map <string, string> SSMap;

void WorkWithUser(string &searchString, string &wordTranslate, SSMap &dictionaryMap, string &searchStringToLower, SSMap dictionaryNewMap);
bool WriteInDictionaryMap(const string &dictionaryName, SSMap &dictionaryMap);
string SearchWordsInDictionary(const string &searchString, SSMap &dictionaryMap, string &searchStringToLower);
void AddInformationIntoDictionaryFileTxt(SSMap &newDictionary);

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

string SearchWordsInDictionary(const string &searchString, SSMap &dictionaryMap, string &searchStringToLower)
{
	string lineStrToLower;
	string wordTranslate;
	for (auto &it : dictionaryMap)///вывод на экран
	{
		string firstToLower = it.first;
		string secondToLower = it.second;
		transform(firstToLower.begin(), firstToLower.end(), firstToLower.begin(), tolower);
		transform(secondToLower.begin(), secondToLower.end(), secondToLower.begin(), tolower);
		if (firstToLower == searchStringToLower)
		{
			wordTranslate += it.second + ", ";
		}
		if (secondToLower == searchStringToLower)
		{
			wordTranslate += it.first + ", ";
		}
	}
	if (!wordTranslate.empty())
	{
		wordTranslate.pop_back();
		wordTranslate.pop_back();
	}
	return wordTranslate;
}

void AddInformationIntoDictionaryFileTxt(SSMap &newDictionary)
{
	ofstream dictionary("dictionary.txt", ios_base::app);
	if (dictionary.is_open())
	{
		for (auto &it : newDictionary)
		{
			dictionary << it.first << endl << it.second << endl;
		}
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

