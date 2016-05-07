#include "stdafx.h"
#include "../Lab6Task1Var7/HttpUrl.h"
#include "../Lab6Task1Var7/UrlParsingError.h"
#include <boost/test/unit_test.hpp>


struct url
{
	
};

BOOST_FIXTURE_TEST_SUITE(TestCHttpUrl, url)
	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_string)
		BOOST_AUTO_TEST_CASE(throws_exception_on_incorrect_scheme)
		{
			//BOOST_CHECK()
		}
		BOOST_AUTO_TEST_CASE(dont_throws_exception_on_correct_scheme)
		{
			//BOOST_CHECK()
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_components)
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_domain_name)
		{

		}
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_protocol)
		{

		}
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_port)
		{

		}
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_document)
		{

		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_get_document)
		{

		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_domain_name)
		{

		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_port)
		{

		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_protocol)
		{

		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()