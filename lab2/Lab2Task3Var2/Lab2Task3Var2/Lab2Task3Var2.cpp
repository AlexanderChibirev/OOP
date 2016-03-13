// Lab2Task3Var2.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "WorkWithUser.h"
#include <windows.h>

using namespace std;

//enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE, WORD_CAN_NOT_BE_FOUND };


int _tmain()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	map <string, string> dictionaryMap;
	string searchString;
	string searchStringToLower;
	string wordTranslate;
	string dictionaryName = "dictionary.txt";
	if (WorkWithUser(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower))
	{
		cout << "CANT_OPEN_FILE\n";
		return 1;
	}
	return 0;
}

