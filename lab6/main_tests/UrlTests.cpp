#include "stdafx.h"
#include "../Lab6Task1Var7/HttpUrl.h"
#include "../Lab6Task1Var7/UrlParsingError.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestCHttpUrl)
	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_string)
		BOOST_AUTO_TEST_CASE(dont_throws_exception_on_correct_scheme)
		{
			BOOST_REQUIRE_NO_THROW(CHttpUrl("https://github.com//OOP/"));
		}
		BOOST_AUTO_TEST_CASE(when_the_port_is_not__set_and_the_protocol_is_http_then_fun_GetPort_return_80)
		{
			CHttpUrl url("http://github.com//OOP/");
			BOOST_CHECK_EQUAL(url.GetPort(), 80);
		}
		BOOST_AUTO_TEST_CASE(when_the_port_is_not__set_and_the_protocol_is_https_then_fun_GetPort_return_443)
		{
			CHttpUrl url("https://github.com//OOP/");
			BOOST_CHECK_EQUAL(url.GetPort(), 443);
		}
		BOOST_AUTO_TEST_CASE(when_document_is_empty_function_GetDocument_return_solidus)
		{
			CHttpUrl url("https://github.com");
			BOOST_CHECK_EQUAL(url.GetDocument(), "/");
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(when_initialized_with_url_components)
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_domain_name)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("https", "", 80, "//OOP/"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_protocol)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("asasdhttps", "github.com", 80, "//OOP/"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(throws_exception_on_invalid_port)
		{
			BOOST_REQUIRE_THROW(CHttpUrl url("asasdhttps", "github.com", -80, "//OOP/"), CUrlParsingError);
		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_get_document)
		{
			CHttpUrl url("https", "github.com", 80, "//OOP/");
			BOOST_REQUIRE_NO_THROW(url.GetDocument());
		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_domain_name)
		{
			CHttpUrl url("https", "github.com", 80, "//OOP/");
			BOOST_REQUIRE_NO_THROW(url.GetDomain());

		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_port)
		{
			CHttpUrl url("https", "github.com", 80, "//OOP/");
			BOOST_REQUIRE_NO_THROW(url.GetPort());
		}
		BOOST_AUTO_TEST_CASE(then_correct_url_components_can_return_protocol)
		{
			CHttpUrl url("https", "github.com", 80, "//OOP/");
			BOOST_REQUIRE_NO_THROW(url.GetProtocol());
		}
	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()