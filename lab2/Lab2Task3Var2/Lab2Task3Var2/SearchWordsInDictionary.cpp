#include "stdafx.h"
#include "SearchWordsInDictionary.h"


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