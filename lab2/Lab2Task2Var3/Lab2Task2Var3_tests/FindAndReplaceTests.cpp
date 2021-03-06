#include "stdafx.h"
#include <boost/test/unit_test.hpp>

using namespace std;

string FindAndReplace(const string & text, const string & searchString, const string & replaceString);
BOOST_AUTO_TEST_SUITE(Replace_function)

//
	BOOST_AUTO_TEST_CASE(replacing_subject_should_not_be_made_from_empty_subject)
	{
		string subject = "";
		string search = "hello";
		string replace = "bye";
		BOOST_CHECK(FindAndReplace(subject, search, replace) == "");
	}
	BOOST_AUTO_TEST_CASE(make_subject_from_empty_search)
	{
		string subject = "Empty";
		string search = "";
		string replace = "bye";
		BOOST_CHECK(FindAndReplace(subject, search, replace) == "Empty");
	}
	BOOST_AUTO_TEST_CASE(make_subject_from_empty_replace)
	{
		string subject = "Empty";
		string search = "Hello";
		string replace = "";
		BOOST_CHECK(FindAndReplace(subject, search, replace) == "Empty");
	}

	BOOST_AUTO_TEST_CASE(make_mamamama_from_search_ma_and_replace_mama_and_subject_mama)
	{
		string subject = "mama";
		string search = "ma";
		string replace = "mama";
		FindAndReplace(subject, search, replace);
		BOOST_CHECK(FindAndReplace(subject, search, replace) == "mamamama");
	}

	BOOST_AUTO_TEST_CASE(make_123true5_from_search_1231234_and_replace_true_and_subject_12312312345)
	{
		string subject = "12312312345";
		string search = "1231234";
		string replace = "true";
		BOOST_CHECK(FindAndReplace(subject, search, replace) == "123true5");
	}

BOOST_AUTO_TEST_SUITE_END()


