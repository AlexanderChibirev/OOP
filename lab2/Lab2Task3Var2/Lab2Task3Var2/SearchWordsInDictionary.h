#pragma once

enum ERROR_CODE { ALL_IS_OK, CANT_OPEN_FILE, WORD_CAN_NOT_BE_FOUND };

ERROR_CODE SearchWordsInDictionary(const std::string &dictionaryName, const std::string &searchString, std::string &wordTranslate, std::map <std::string, std::string> &dictionaryMap, std::string &searchStringToLower);