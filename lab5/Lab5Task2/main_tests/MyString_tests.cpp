#include "stdafx.h"
#include "../Lab5Task2/MyString.h"


struct DefaultConstructorMyString
{
	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(myString, DefaultConstructorMyString)
	BOOST_AUTO_TEST_CASE(returns_the_string_length_excluding_the_terminating_null_character)
	{
		BOOST_CHECK(myString.GetLength() == 0);
	}
	BOOST_AUTO_TEST_CASE(at_the_end_of_the_array_must_be_a_terminating_null_character)
	{
		BOOST_CHECK(myString.GetStringData()[myString.GetLength()] == '\0');
	}
	BOOST_AUTO_TEST_CASE(can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
	}
	BOOST_AUTO_TEST_CASE(calling_SubString_then_empty_str_returns_empty_value)
	{
		BOOST_CHECK_EQUAL(myString.SubString(0, 0), "");
	}

BOOST_AUTO_TEST_SUITE_END()


struct ConstructorMyStringInitializingWithValue
{
	ConstructorMyStringInitializingWithValue()
		: myString("MyStringNoEmpty")
	{};

	CMyString myString;
};

BOOST_FIXTURE_TEST_SUITE(myStringWithValue, ConstructorMyStringInitializingWithValue)

	BOOST_AUTO_TEST_CASE(default_length_of_the_string_is_equal_to_length_MyStringNoEmpty)
	{
		BOOST_CHECK_EQUAL(myString.GetLength(), 15);
	}

	BOOST_AUTO_TEST_CASE(GetStringData_return_string_is_equal_to_length_MyStringNoEmpty)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData(), "MyStringNoEmpty");
	}


	BOOST_AUTO_TEST_CASE(have_a_null_char_on_end)
	{
		BOOST_CHECK_EQUAL(myString.GetStringData()[myString.GetLength()], '\0');
	}

	BOOST_AUTO_TEST_CASE(correct_substring_returns_this_substr)
	{
		auto subStr = myString.SubString(2, 6);
		BOOST_CHECK_EQUAL(subStr.GetLength(), 6);
		BOOST_CHECK_EQUAL(subStr.GetStringData(), "String");
	}

	BOOST_AUTO_TEST_CASE(incorrect_substring_returns_exception)
	{
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(16, 16), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_clear_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}
	BOOST_AUTO_TEST_CASE(after_clear_string_can_clear_empty_string)
	{
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ConstructorMyStringInitializingWithValueAndLength)
	BOOST_AUTO_TEST_CASE(string_is_equal_to_length_StringWithValueAndLen)
	{
		CMyString myString("StringWithValueAndLen", 11);
		BOOST_CHECK_EQUAL(myString.GetLength(), 11);
	}
	BOOST_AUTO_TEST_CASE(strings_is_equal_to_StringWithValueAndLen)
	{
		CMyString myString("StringWithValueAndLen", 21);
		BOOST_CHECK_EQUAL(myString.GetStringData(), "StringWithValueAndLen");
	}

	BOOST_AUTO_TEST_CASE(then_we_transmit_in_constructor_len_is_equal_zero_fun_getLength_returns_the_str_len_is_equal_zero)
	{
		CMyString myString("", 0);
		BOOST_CHECK(myString.GetLength() == 0);
	}
	BOOST_AUTO_TEST_CASE(correct_substring_returns_this_substr)
	{
		CMyString myString("StringWithValueAndLen", 11);
		auto substr = myString.SubString(0, 6);
		BOOST_CHECK_EQUAL(substr.GetLength(), 6);
		BOOST_CHECK_EQUAL(substr.GetStringData(), "String");
	}

	BOOST_AUTO_TEST_CASE(incorrect_substring_returns_exception)
	{
		CMyString myString("StringWithValueAndLen", 11);
		BOOST_REQUIRE_THROW(auto substr = myString.SubString(20, 30), std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(have_a_null_char_on_end)
	{
		CMyString myString("StringWithValueAndLen", 11);
		BOOST_CHECK_EQUAL(myString.GetStringData()[myString.GetLength()], '\0');
	}
	BOOST_AUTO_TEST_CASE(can_clear_initialized_string)
	{
		CMyString myString("StringWithValueAndLen", 11);
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0u);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}
	BOOST_AUTO_TEST_CASE(after_clear_string_can_clear_empty_string)
	{
		CMyString myString("StringWithValueAndLen", 11);
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_NO_THROW(myString.Clear());
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
		BOOST_CHECK_EQUAL(myString.GetStringData()[0], '\0');
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(CopyConstructor)
	BOOST_AUTO_TEST_CASE(can_copy_str_in_str1)
	{
		CMyString str("heyCopy");
		CMyString str1(str);
		BOOST_CHECK_EQUAL(str.GetLength(), 7);
		BOOST_CHECK_EQUAL(str.GetStringData(), "heyCopy");
		BOOST_CHECK_EQUAL(str1.GetLength(), 7);
		BOOST_CHECK_EQUAL(str1.GetStringData(), "heyCopy");
	}
	BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(MovingConstructor)
	BOOST_AUTO_TEST_CASE(can_move_the_str_in_str1_to_become_empty)
	{
		CMyString str("heyMoving");
		CMyString str1(move(str));
		BOOST_CHECK_EQUAL(str.GetLength(), 0);
		BOOST_CHECK_EQUAL(str.GetStringData(), "");
		BOOST_CHECK_EQUAL(str1.GetLength(), 9);
		BOOST_CHECK_EQUAL(str1.GetStringData(), "heyMoving");

	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(concatenationOperator)
	void VerifyString(CMyString const & str, size_t length, std::string const & reference)
	{
		BOOST_CHECK_EQUAL(str.GetLength(), length);
		BOOST_CHECK_EQUAL(str.GetStringData(), reference);
	}
	BOOST_AUTO_TEST_CASE(can_add_two_strings_type_CMyString)
	{
		CMyString addMyStr = CMyString("x") + CMyString("y");
		VerifyString(addMyStr, 2, "xy");
	}
	BOOST_AUTO_TEST_CASE(can_add_STL_string_with_the_string)
	{
		CMyString addStlStr = std::string("x") + CMyString("y");
		VerifyString(addStlStr, 2, "xy");
	}
	BOOST_AUTO_TEST_CASE(can_add_char_string_with_the_string)
	{
		CMyString addCharStr = "x" + CMyString("y");
		VerifyString(addCharStr, 2, "xy");
	}
	BOOST_AUTO_TEST_CASE(can_be_assign_addition_of_itself)
	{
		CMyString addMyStr("x");
		BOOST_CHECK_NO_THROW(addMyStr = addMyStr + addMyStr);
		BOOST_CHECK_EQUAL(addMyStr.GetStringData(), "xx");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(unaryAddOperator)
	BOOST_AUTO_TEST_CASE(can_add_empty_string)
	{
		CMyString myString("x");
		myString += "";
		BOOST_CHECK_EQUAL(myString.GetLength(), 1);
		BOOST_CHECK_EQUAL(myString.GetStringData(), "x");
	}
	BOOST_AUTO_TEST_CASE(can_add_char_string)
	{
		CMyString myString("x");
		myString += "y";
		BOOST_CHECK_EQUAL(myString.GetLength(), 2);
		BOOST_CHECK_EQUAL(myString.GetStringData(), "xy");
	}
	BOOST_AUTO_TEST_CASE(can_add_stl_string)
	{
		CMyString myString("x");
		std::string stlString = "stl";
		myString += stlString;
		BOOST_CHECK_EQUAL(myString.GetLength(), 4);
		BOOST_CHECK_EQUAL(myString.GetStringData(), "xstl");
	}
BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(assignmentOperator)


	BOOST_AUTO_TEST_CASE(can_assign_itself_as_the_value_string)
	{
		CMyString str("x");
		str = str;
		BOOST_CHECK_EQUAL(str.GetStringData(), "x");
	}

	BOOST_AUTO_TEST_CASE(can_assign_a_string_value)
	{
		CMyString str;
		CMyString someString("x");
		str = someString;
		BOOST_CHECK_EQUAL(str.GetStringData(), "x");
	}

	BOOST_AUTO_TEST_CASE(can_assign_a_string_value_of_other_type)
	{
		CMyString str;
		BOOST_CHECK_EQUAL((str = "x").GetStringData(), "x");
		BOOST_CHECK_EQUAL((str = std::string("y")).GetStringData(), "y");
		char *chars = "chars";
		BOOST_CHECK_EQUAL((str = chars).GetStringData(), "chars");
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(comparisonOperator)

	BOOST_AUTO_TEST_CASE(strings_are_equal)
	{
		BOOST_CHECK(CMyString("x") == CMyString("x"));
	}

	BOOST_AUTO_TEST_CASE(strings_are_not_equal)
	{
		BOOST_CHECK(!(CMyString("x") == CMyString("y")));
	}

BOOST_AUTO_TEST_SUITE_END()


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(lessOperator)

	BOOST_AUTO_TEST_CASE(str2_less_str1_by_alphabet)
	{
		BOOST_CHECK((CMyString("ab") < CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(str1_less_str2)
	{
		BOOST_CHECK(!(CMyString("abz") < CMyString("abcd", 3)));
	}

	BOOST_AUTO_TEST_CASE(str2_equal_str1)
	{
		BOOST_CHECK(!(CMyString("Test", 4u) < CMyString("Test")));
	}

BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(moreOperator)

	BOOST_AUTO_TEST_CASE(str2_more_str1_by_alphabet)
	{
		BOOST_CHECK(!(CMyString("ab") > CMyString("abc", 3)));
	}

	BOOST_AUTO_TEST_CASE(str1_more_str2)
	{
		BOOST_CHECK((CMyString("abz") > CMyString("abcd", 3)));
	}
	BOOST_AUTO_TEST_CASE(str1_equal_str2)
	{
		BOOST_CHECK(!(CMyString("Test", 4u) > CMyString("Test", 4u)));
	}
BOOST_AUTO_TEST_SUITE_END()
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(lessOrEqualOperator)

	BOOST_AUTO_TEST_CASE(compare_them_in_alphabetical_order)
	{
		BOOST_CHECK((CMyString("aba") <= CMyString("abc")));
	}

	BOOST_AUTO_TEST_CASE(right_str_is_more_by_left_str_and_operator_return_false)
	{
		BOOST_CHECK((CMyString("a") <= CMyString("b")));
	}
	BOOST_AUTO_TEST_CASE(if_strings_is_equal_return_true)
	{
		BOOST_CHECK((CMyString("x", 1) <= CMyString("x", 1)));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(greaterOrEqualOperator)

	BOOST_AUTO_TEST_CASE(compare_them_in_alphabetical_order)
	{
		BOOST_CHECK((CMyString("abc") >= CMyString("aba")));
	}

	BOOST_AUTO_TEST_CASE(left_str_is_more_by_right_str_and_operator_return_true)
	{
		BOOST_CHECK((CMyString("b") >= CMyString("a")));
	}

	BOOST_AUTO_TEST_CASE(if_strings_is_equal_return_true)
	{
		BOOST_CHECK((CMyString("x", 1) >= CMyString("x",1)));
	}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(indexedAccessOperator)

	BOOST_AUTO_TEST_CASE(indexed_access_to_a_string_of_characters_by_integer_index_reading)
	{
		CMyString str("x");
		BOOST_CHECK(str[0] == 'x');
	}
	BOOST_AUTO_TEST_CASE(indexed_access_to_a_string_of_characters_by_integer_index_writing)
	{
		CMyString str("xer");
		str[2] = 'x';
		BOOST_CHECK_EQUAL(str.GetStringData(), "xex");
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(istreamOperator)
	BOOST_AUTO_TEST_CASE(string_with_null_char_in_middle)
	{
		std::istringstream strm("Some\0String");
		CMyString myStr;
		strm >> myStr;
		BOOST_CHECK_EQUAL(myStr.GetStringData(), "Some\0String");
	}
BOOST_AUTO_TEST_SUITE_END()

/////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(Ostream)
	BOOST_AUTO_TEST_CASE(string_with_null_char_in_middle)
	{
		std::ostringstream strm;
		strm << CMyString("m\0o",3);
		string stdStr("m\0o", 3);
		BOOST_CHECK_EQUAL(strm.str(), stdStr);
	}
BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////////

BOOST_AUTO_TEST_SUITE(Then_we_used_str_cpy)
	BOOST_AUTO_TEST_CASE(null_character_will_be_ignored)
	{
		BOOST_CHECK(!(CMyString("str_cpy") == CMyString("str_cpy\0", 5)));
	}
BOOST_AUTO_TEST_SUITE_END()



struct MyStringIterator
{
	MyStringIterator()
		: myStr("iterRevers", strlen("iterRevers"))
		, constMyStr("iterReversConst", strlen("iterReversConst"))
	{
	}
	CMyString myStr;
	const CMyString constMyStr;
};

BOOST_FIXTURE_TEST_SUITE(testIterator, MyStringIterator)

	BOOST_AUTO_TEST_CASE(can_get_point_to_start_str)
	{
		auto it = myStr.begin();
		BOOST_CHECK_EQUAL(*it, myStr[0]);
	}

	BOOST_AUTO_TEST_CASE(can_get_point_to_end_str)
	{
		auto it = myStr.end();
		--it;
		BOOST_CHECK_EQUAL(*it, myStr[myStr.GetLength() - 1]);
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_constant_string_in_forward_direction)
	{
		size_t i = 0;
		for (CMyString::const_iterator it = constMyStr.begin(); it != constMyStr.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, constMyStr[i]);
			++i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_not_constant_string_in_forward_direction)
	{
		size_t i = 0;
		for (CMyString::iterator it = myStr.begin(); it != myStr.end(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, myStr[i]);
			++i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_constant_string_in_reverse_direction)
	{

		CMyString str("iterRevers");
		size_t i = str.GetLength() - 1;
		for (CMyString::iterator it = str.rbegin(); it != str.rend(); ++it)
		{
			auto element1 = str[i];
			auto element2 = *it;
			BOOST_CHECK_EQUAL(element1, element2);
			i--;
		}
	}

	BOOST_AUTO_TEST_CASE(can_iterate_over_not_constant_string_in_reverse_direction)
	{
		size_t i = myStr.GetLength() - 1;
		for (CMyString::iterator it = myStr.rbegin(); it != myStr.rend(); ++it)
		{
			BOOST_CHECK_EQUAL(*it, myStr[i]);
			--i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_get_distance_between_two_iterators)
	{
		BOOST_CHECK_EQUAL(myStr.end() - myStr.begin(), 10);
	}
	BOOST_AUTO_TEST_CASE(can_addition_iter_and_integer)
	{
		auto it = myStr.begin() + 9;
		BOOST_CHECK_EQUAL(*it, 's');
	}
	
	BOOST_AUTO_TEST_CASE(access_to_the_elements_of_the_line_relative_to_the_iterator)
	{
		auto it = constMyStr.begin();
		BOOST_CHECK_EQUAL(it[0], 'i');
	}

	BOOST_AUTO_TEST_CASE(supports_iteration_over_the_elements_by_means_of_range_based_for)
	{
		size_t i = 0;
		for (auto it : myStr)
		{
			BOOST_CHECK_EQUAL(it, myStr[i]);
			++i;
		}
	}

	BOOST_AUTO_TEST_CASE(can_addition_integer_and_iter)
	{
		auto it = 9 + myStr.begin();
		BOOST_CHECK_EQUAL(*it, 's');
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(afterClearString)
	BOOST_AUTO_TEST_CASE(can_perform_all_operations)
	{
		CMyString myString("Clear", 5);
		myString.Clear();
		BOOST_CHECK_EQUAL(myString.GetLength(), 0);
		BOOST_CHECK_EQUAL(myString.GetStringData(), "");
		BOOST_CHECK_EQUAL(myString.SubString(0, 0), "");
		BOOST_REQUIRE_THROW(myString[0], std::out_of_range);
		CMyString str1(myString.GetStringData()); 
		CMyString str2(myString.GetStringData(), myString.GetLength());
		CMyString str3(myString);
		BOOST_CHECK_EQUAL(str1, myString);
		BOOST_CHECK_EQUAL(str2, myString);
		BOOST_CHECK_EQUAL(str3, myString);
	}
BOOST_AUTO_TEST_SUITE_END()