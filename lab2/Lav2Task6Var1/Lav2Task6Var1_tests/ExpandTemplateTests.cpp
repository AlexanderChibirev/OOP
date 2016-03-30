#include "stdafx.h"
#include "..//Lav2Task6Var1/ExpandTemplate.h"
#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(ProcessVector_function)


	BOOST_AUTO_TEST_CASE(SimpleCheck)
	{
		std::string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
		std::map< std::string, std::string> params;
		params["%USER_NAME%"] = "Ivan Petrov";
		params["{WEEK_DAY}"] = "Friday";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Ivan Petrov. Today is Friday.");
	}
	BOOST_AUTO_TEST_CASE(MidCheck)
	{
		std::string const tpl = "Hello, %USER_NAME%. Today is {WEEK_DAY}.";
		std::map< std::string, std::string> params;
		params["%USER_NAME%"] = "Super %USER_NAME% {WEEK_DAY}";
		params["{WEEK_DAY}"] = "Friday. {WEEK_DAY}";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "Hello, Super %USER_NAME% {WEEK_DAY}. Today is Friday. {WEEK_DAY}.");
	}
	BOOST_AUTO_TEST_CASE(VerificationOfDifferentLengthsword)
	{
		std::string const tpl = "-AABBCCCCCABC+";
		std::map< std::string, std::string> params;
		params["A"] = "[a]";
		params["AA"] = "[aa]";
		params["B"] = "[b]";
		params["BB"] = "[bb]";
		params["C"] = "[c]";
		params["CC"] = "[cc]";
		BOOST_CHECK(ExpandTemplate(tpl, params) == "-[aa][bb][cc][cc][c][a][b][c]+");
	}

	BOOST_AUTO_TEST_CASE(MalovsTestEasy)
	{
		BOOST_CHECK_EQUAL(ExpandTemplate("CCC",
		{ { "CC", "CCC" },
		{ "C", "CCCC" } }), "CCCCCCC");
	}

	BOOST_AUTO_TEST_CASE(MalovsTestBiasPositionsMidLvl)
	{
		BOOST_CHECK_EQUAL(ExpandTemplate("-AABBCC+", { { "CC" ,"[cc]"},
		{"B","[b]"},
		{"A", "[a]"} }), "-[a][a][b][b][cc]+");
	}

	BOOST_AUTO_TEST_CASE(MalovsTestHard)
	{
		BOOST_CHECK_EQUAL(ExpandTemplate("CCCAAA",
		{ { "CC", "CCC" },
		{ "C", "CCCC" },
		{"AA", "AAA"},
		{ "A", "AAAA" } }), "CCCCCCCAAAAAAA");
	}
BOOST_AUTO_TEST_SUITE_END()


