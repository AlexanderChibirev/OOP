#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "../Lav2Task6Var1/FindAndReplace.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <algorithm>
#include <sstream>
#include <iterator>


using namespace std;

struct ByLength : public std::binary_function<string, string, bool>
{
	bool operator()(const string& lhs, const string& rhs) const
	{
		if (lhs.length() == rhs.length())
		{
			return lhs > rhs;
		}
		return lhs.length() > rhs.length();
	}
};


typedef map<string, string, ByLength> lenmap;

std::string ExpandTemplate(std::string const& tpl, lenmap params)
{
	std::string newTpl;
	std::string tplTemp;
	std::istringstream iss(tpl);
	int count = 0;
	int iteratorTpl = 0;

	while (!iss.eof())
	{
		iss >> tplTemp;
		iteratorTpl += tplTemp.size();
		string spaceTpl;
		for (size_t i = iteratorTpl; i < tpl.size(); ++i)
		{
			if (tpl[i] == ' ' || tpl[i] == '\n')
			{
				spaceTpl += tpl[i];
				iteratorTpl++;
			}
			else
			{
				break;
			}
		}
		bool wasFind = false;
		//если че тут просто потом добавить еще цикл, по длине TplTemp, если без нее норм, то убрать wasFind, поставить break;
		//если серый не поможет с изменением шаблона, то тогда заменить на старый вариант
		for (auto it = params.begin(); it != params.end(); ++it)
		{
			std::string checkTpl = FindAndReplace(tplTemp, it->first, it->second);
			if (checkTpl == "" && count == params.size() - 1 && !wasFind)
			{
				newTpl += tplTemp + spaceTpl;
				wasFind = true;
			}
			else if (checkTpl != "" && !wasFind)
			{
				newTpl += checkTpl + spaceTpl;
				wasFind = true;
			}
			count++;
		}
		count = 0;
	}
	return newTpl;
}

BOOST_AUTO_TEST_SUITE(ExpandTamplate_function)


	BOOST_AUTO_TEST_CASE(SIMPLE_CHECK)
	{
		std::string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
		lenmap params;
		params["%USER_NAME%"] = "Ivan Petrov";
		params["{WEEK_DAY}"] = "Friday";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Ivan Petrov. Today is Friday.");
	}
	BOOST_AUTO_TEST_CASE(MID_CHECK)
	{
		std::string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
		lenmap params;
		params["%USER_NAME%"] = "Super %USER_NAME% {WEEK_DAY}";
		params["{WEEK_DAY}"] = "Friday. {WEEK_DAY}";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Super %USER_NAME% {WEEK_DAY}. Today is Friday. {WEEK_DAY}.");
	}
	BOOST_AUTO_TEST_CASE(VERIFICATION_OF_DIFFERENT_LENGTHS_WORD)
	{
		std::string const tpl = "-AABBCCCCCABC+";
		lenmap params;
		params["A"] = "[a]";
		params["AA"] = "[aa]";
		params["B"] = "[b]";
		params["BB"] = "[bb]";
		params["C"] = "[c]";
		params["CC"] = "[cc]";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "-[aa][bb][cc][cc][c][a][b][c]+");
	}
BOOST_AUTO_TEST_SUITE_END()


