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

using namespace std;

struct ByLength : public std::binary_function<string, string, bool>
{
	bool operator()(const string& lhs, const string& rhs) const
		{
			//int lhsAscii = atoi(lhs.c_str());
			//int rhsAscii = atoi(rhs.c_str());
			string lhsForCmp = lhs;
			string rhsForCmp = rhs;
			if (lhs.length() < rhs.length())
			{
				while (rhsForCmp.length() != lhs.length())
				{
					rhsForCmp.erase(lhs.length(), 1);
				}
			}
			else if (lhs.length() > rhs.length())
			{
				while (lhsForCmp.length() != rhs.length())
				{
					lhsForCmp.erase(rhs.length(), 1);
				}
			}
			int lhsAscii = 0;
			int rhsAscii = 0;
			//inputStr.erase(0, 4);
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
				return lhs > rhs;
			}
		return lhs < rhs;
	}
};



// TODO: reference additional headers your program requires here
