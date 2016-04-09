#include "stdafx.h"
#include "AddInformationIntoDictionaryFileTxt.h"

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