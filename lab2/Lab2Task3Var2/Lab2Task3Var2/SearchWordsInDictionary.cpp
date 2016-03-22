#include "stdafx.h"
#include "SearchWordsInDictionary.h"

using namespace std;

//������� �������, ������� ����� ��������� �� ����� � �������
//��������� ���������� ����
//������� ���� ���������


ERROR_CODE SearchWordsInDictionary(const string &dictionaryName, const string &searchString, string &wordTranslate, map <string, string> &dictionaryMap, string &searchStringToLower)
{
	string lineStr;
	string lineStrToLower;
	bool wasWord = false;
	for (auto it = dictionaryMap.begin(); it != dictionaryMap.end(); ++it)///����� �� �����
	{
		string firstToLower = it->first;
		string secondToLower = it->second;
		transform(firstToLower.begin(), firstToLower.end(), firstToLower.begin(), tolower);
		transform(secondToLower.begin(), secondToLower.end(), secondToLower.begin(), tolower);
		if (firstToLower == searchStringToLower)
		{
			wordTranslate += it->second + ", ";
			wasWord = true;
		}
		if (secondToLower == searchStringToLower)
		{
			wordTranslate += it->first + ", ";
			wasWord = true;
		}
	}
	if (!wasWord)
	{
		return ERROR_CODE::WORD_CAN_NOT_BE_FOUND;
	}
	else
	{
		wordTranslate.pop_back();
		wordTranslate.pop_back();
	}
	return ERROR_CODE::ALL_IS_OK;
}