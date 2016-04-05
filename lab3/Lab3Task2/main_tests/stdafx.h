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
#include <boost/algorithm/string/replace.hpp>

#define BOOST_TEST_INCLUDED
#pragma warning (disable: 4702)
#include <boost/test/unit_test.hpp>
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

struct ByLength : public std::binary_function<string, string, bool>
{
	bool operator()(const string& lhs, const string& rhs) const
	{
		string lhsForCmp = lhs;
		string rhsForCmp = rhs;
		if (lhs.length() < rhs.length()) //AA < AAB
		{
			while (rhsForCmp.length() != lhs.length())
			{
				rhsForCmp.erase(lhs.length(), 1);
			}
		}
		else if (lhs.length() > rhs.length()) //AAB > AA
		{
			while (lhsForCmp.length() != rhs.length())
			{
				lhsForCmp.erase(rhs.length(), 1);
			}
		}
		int lhsAscii = 0;
		int rhsAscii = 0;
		/*for (size_t i = 0; i < lhsForCmp.length(); ++i)
		{
		if()


		}*/
		for (auto &it : lhsForCmp)
		{
			lhsAscii += int(it);
			if (int(it) >= 97)
			{
				lhsAscii -= 32;
			}
		}
		for (auto &it : rhsForCmp)
		{
			rhsAscii += int(it);
			if (int(it) >= 97)
			{
				rhsAscii -= 32;
			}
		}
		if (lhsAscii == rhsAscii)
		{
			return lhs < rhs;
		}
		return lhs < rhs;
	}
};

typedef map <string, string, ByLength> SortMap;

// TODO: reference additional headers your program requires here
