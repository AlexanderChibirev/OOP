#include "stdafx.h"
#include "../Lab6-CMyList/StringList.h"
#include "../Lab6-CMyList/ListIterators.h"

using namespace std;

struct EmptyStringList
{
	CStringList list;
};

BOOST_FIXTURE_TEST_SUITE(Stringlist, EmptyStringList)

	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK(list.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_push_back_a_string)

	BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
	{
		auto oldSize = list.GetSize();
		list.PushBack("Hello World");
		BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
		list.PushBack("Hello World");
		BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
	}

	BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetBackElement_and_GetFrontElement_method)
	{
		list.PushBack("Hello World");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "Hello World");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "Hello World");
		list.PushBack("bye");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "bye");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "Hello World");
	}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_push_front_a_string)

	BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
	{
		auto oldSize = list.GetSize();
		list.PushFront("Hello World");
		BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 1);
		list.PushFront("Hello World");
		BOOST_CHECK_EQUAL(list.GetSize(), oldSize + 2);
	}

	BOOST_AUTO_TEST_CASE(makes_it_accessible_via_GetBackElement_and_GetFrontElement_method)
	{
		list.PushFront("Hello World");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "Hello World");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "Hello World");
		list.PushFront("bye");
		BOOST_CHECK_EQUAL(list.GetFrontElement(), "bye");
		BOOST_CHECK_EQUAL(list.GetBackElement(), "Hello World");
	}

	BOOST_AUTO_TEST_CASE(makes_it_accessible_via_iterator_to_first_element)
	{
		list.PushBack("Hello World");
		auto it = list.begin();
		BOOST_CHECK_EQUAL(addressof(*it), addressof(list.GetBackElement()));
	}

	BOOST_AUTO_TEST_SUITE_END()

struct WasFilled : public EmptyStringList
{
	WasFilled()
	{
		list = { "first","second","third" };
	}
	std::vector<std::string> expectedString = { "first", "second", "third" };
};/*
BOOST_FIXTURE_TEST_SUITE(InitialisedList, WasFilled)
	BOOST_AUTO_TEST_CASE(can_go_through_the_list_using_the_operators_start_and_end)
		{
			size_t index = 0;
			for (auto it = list.begin(); it != list.end(); ++it)
			{
				BOOST_CHECK(*it == expectedString[index]);
				++index;
			}
		}
	BOOST_AUTO_TEST_CASE(can_go_through_the_list_using_reverse_iterators)
	{
		size_t index = list.GetSize() - 1;
		for (auto iter = list.rbegin(); iter != list.rend(); --iter)
		{
			BOOST_CHECK(*iter == expectedString[index]);
			--index;
		}
		}
	BOOST_AUTO_TEST_CASE(can_get_access_to_elements_from_range_based_for)
	{
		size_t index = 0;
		for (auto str : list)
		{
			BOOST_CHECK(str == expectedString[index]);
			++index;
		}
	}
	BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		BOOST_CHECK(!list.IsEmpty());
		list.Clear();
		BOOST_CHECK(list.IsEmpty());

	}
	BOOST_AUTO_TEST_CASE(can_be_cleared_where_the_list_is_empty)
	{
		CStringList emptyList;

		BOOST_CHECK(emptyList.IsEmpty());
		emptyList.Clear();
		BOOST_CHECK(emptyList.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(can_insert_element_at_iterator_pos)
	{
		auto it = ++list.begin();
		list.Insert(it, "zero");
		BOOST_CHECK_EQUAL(*++list.begin(), "zero");
	
		list.Insert(list.begin(), "brazers");
		BOOST_CHECK_EQUAL(*list.begin(), "brazers");
	
		list.Insert(list.end(), "brazers");
	
		vector<string> expectedStrings = { "brazers", "first", "zero", "second", "third", "brazers" };
		size_t i = 0;
		for (auto str : list)
		{
			BOOST_CHECK_EQUAL(str, expectedStrings[i]);
			i++;
		}
	}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()*/