#include "stdafx.h"
#include "..\Lab2Task3Var2\SearchWordsInDictionary.h"
#include "..\Lab2Task3Var2\AddInformationIntoDictionaryFileTxt.h"

using namespace std;


BOOST_AUTO_TEST_SUITE(SearchWordsInDictionary_function)
	BOOST_AUTO_TEST_CASE(WHEN_THE_FUNCTION_RETURN_ERROR_CODE_WORD_CAN_NOT_BE_FOUND)
	{
		string searchString = "KOKO";
		string wordTranslate;
		string searchStringToLower;
		map <string, string> dictionaryMap;
		string dictionaryName = "dictionary.txt";
		BOOST_CHECK(SearchWordsInDictionary(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower), ERROR_CODE::WORD_CAN_NOT_BE_FOUND);
	}
	BOOST_AUTO_TEST_CASE(WHEN_THE_FUNCTION_RETURN_ERROR_CODE_ALL_IS_OK)
	{
		string searchString = "Father";
		string wordTranslate;
		string searchStringToLower;
		string dictionaryName = "dictionary.txt";
		map <string, string> dictionaryMap;
		BOOST_CHECK(SearchWordsInDictionary(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower), ERROR_CODE::ALL_IS_OK);
	}
	BOOST_AUTO_TEST_CASE(WHEN_THE_FUNCTION_RETURN_ERROR_CODE_CANT_OPEN_FILE)
	{
		string searchString = "Father";
		string wordTranslate;
		string searchStringToLower;
		string dictionaryName = "dictionary.bat";
		map <string, string> dictionaryMap;
		BOOST_CHECK(SearchWordsInDictionary(dictionaryName, searchString, wordTranslate, dictionaryMap, searchStringToLower), ERROR_CODE::CANT_OPEN_FILE);
	}
BOOST_AUTO_TEST_SUITE_END()
