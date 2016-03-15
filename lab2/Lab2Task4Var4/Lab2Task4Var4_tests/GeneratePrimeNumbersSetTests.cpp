#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "..\\Lab2Task4Var4\GeneratePrimeNumbersSet.h"


BOOST_AUTO_TEST_SUITE(GeneratePrimeNumbersSet_function)
	BOOST_AUTO_TEST_CASE(NO_PRIME_NUMBERS)
	{
		std::set<int> primeSet = GeneratePrimeNumbersSet(1);
		BOOST_CHECK(primeSet.size() == 0);
	}

	BOOST_AUTO_TEST_CASE(SOME_PRIME_NUMBERS)
	{
		std::set<int> primeSet = GeneratePrimeNumbersSet(9);
		std::set<int> checkPrimeSet = { 2, 3, 5, 7 };
		BOOST_CHECK(primeSet == checkPrimeSet);
	}

	BOOST_AUTO_TEST_CASE(HUNDRED_MILLION_COUNT_OF_PRIME_NUMBERS)
	{
		std::set<int> primeSet = GeneratePrimeNumbersSet(100000000);
		BOOST_CHECK(primeSet.size() == 5761455);
	}
BOOST_AUTO_TEST_SUITE_END()