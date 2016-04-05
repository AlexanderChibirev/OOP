// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <sstream>
#include <functional>
#include <iomanip>
#include <iostream>

using namespace std;

struct SecondMapInformation
{
	string firstVal;
	string operand;
	string secondVal;
};

enum ErrorCode {
	VAR_HAS_ALREADY_BEEN_DECLARED,
	FIRST_SYMBOL_IS_NOT_LETTER,
	IS_ALL_OK,
	INCORRECT_ENTER
};

struct ByAlphabet : public std::binary_function<std::string, std::string, bool>
{
	bool const operator () (const std::string &str1, const std::string &str2) { return _stricoll(str1.c_str(), str2.c_str()) < 0; }
};

typedef map <string, string, ByAlphabet> SortMap;

// TODO: reference additional headers your program requires here
