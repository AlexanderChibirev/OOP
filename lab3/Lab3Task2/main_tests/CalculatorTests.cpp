#include "stdafx.h"
#include "..\\Lab3Task2\Calculator.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include "..\\Lab3Task2\WorkWithUI.h"
#include "..\\Lab3Task2\Difinition.h"
#include "..\Lab3Task2\Difinition.h"


struct CalculatorFixture
{
	CCalculator calculator;
};

BOOST_FIXTURE_TEST_SUITE(VariableDeclarate, CalculatorFixture)
	BOOST_AUTO_TEST_CASE(Test_when_calc_can_declare_new_variable)
	{
		BOOST_CHECK(calculator.SetVariableIdentifier("a"));
	}
	BOOST_AUTO_TEST_CASE(Test_when_calc_cant_declare_repead_variable)
	{	
		BOOST_CHECK(calculator.SetVariableIdentifier("a"));
		BOOST_CHECK(!calculator.SetVariableIdentifier("a"));
	}
	BOOST_AUTO_TEST_CASE(Test_when_variable_does_not_declaret_functiom_GetValue_return_NULL)
	{
		BOOST_CHECK(!calculator.GetValue("b").is_initialized());
	}
	BOOST_AUTO_TEST_CASE(Test_when__function_GetValue_return_NAN)
	{
		BOOST_CHECK(calculator.SetVariableIdentifier("b"));
		BOOST_CHECK(std::isnan(calculator.GetValue("b").get()));
	}

	BOOST_FIXTURE_TEST_SUITE(SetVariable, CalculatorFixture)
		BOOST_AUTO_TEST_CASE(Test_when__function_GetValue_return_correctly_number)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 12));
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(),12);
		}
		BOOST_AUTO_TEST_CASE(Test_when_The_Identifier_assigned_old_variable)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 1.1));
			BOOST_CHECK(calculator.SetVariableValue("a", "b"));
			BOOST_CHECK_EQUAL(calculator.GetValue("a").get(), 1.1);
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(), 1.1);
		}
		BOOST_AUTO_TEST_CASE(Test_wnen_set_variable_double_value_fn_GetValue_return_correctly_numbers)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 1.1));
			BOOST_CHECK(calculator.SetVariableValue("a", 1.123));
			BOOST_CHECK(calculator.SetVariableValue("c", 1.3456345));
			BOOST_CHECK(calculator.SetVariableValue("e", 1231.6546));
			BOOST_CHECK_EQUAL(calculator.GetValue("a").get(), 1.123);
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(), 1.1);
			BOOST_CHECK_EQUAL(calculator.GetValue("c").get(), 1.3456345);
			BOOST_CHECK_EQUAL(calculator.GetValue("e").get(), 1231.6546);
		}
		BOOST_AUTO_TEST_CASE(Test_wnen_set_variable_int_value_fn_GetValue_return_correctly_numbers)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 1.1));
			BOOST_CHECK(calculator.SetVariableValue("a", 1.123));
			BOOST_CHECK(calculator.SetVariableValue("c", 1.3456345));
			BOOST_CHECK(calculator.SetVariableValue("e", 1231.6546));
			BOOST_CHECK_EQUAL(calculator.GetValue("a").get(), 1.123);
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(), 1.1);
			BOOST_CHECK_EQUAL(calculator.GetValue("c").get(), 1.3456345);
			BOOST_CHECK_EQUAL(calculator.GetValue("e").get(), 1231.6546);
		}
		BOOST_AUTO_TEST_CASE(Test_wnen_set_negative_value_fn_GetValue_return_correctly_numbers)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", -1.1));
			BOOST_CHECK(calculator.SetVariableValue("a", -1.123));
			BOOST_CHECK(calculator.SetVariableValue("c", -1.3456345));
			BOOST_CHECK(calculator.SetVariableValue("e", -1231.6546));
			BOOST_CHECK_EQUAL(calculator.GetValue("a"), -1.123);
			BOOST_CHECK_EQUAL(calculator.GetValue("b"), -1.1);
			BOOST_CHECK_EQUAL(calculator.GetValue("c"), -1.3456345);
			BOOST_CHECK_EQUAL(calculator.GetValue("e"), -1231.6546);
		}
	BOOST_AUTO_TEST_SUITE_END()
		BOOST_FIXTURE_TEST_SUITE(Names_functions_and_variables_placed_in_alphabetical_order, CalculatorFixture)
			BOOST_AUTO_TEST_CASE(Test_variables_placed_in_alphabetical_order)
			{
				BOOST_CHECK(calculator.SetVariableValue("c", 1));
				BOOST_CHECK(calculator.SetVariableValue("b", 2));
				BOOST_CHECK(calculator.SetVariableValue("e", 3));
				BOOST_CHECK(calculator.SetVariableValue("a", 4));
				map <string, double> m_variableNameList = { {"a",4},
															{ "b",2 },
															{ "e",3 },
															{ "c",1 } };
//				BOOST_CHECK(calculator.GetVariableList() == m_variableNameList);
			}
			BOOST_AUTO_TEST_CASE(Test_functions_placed_in_alphabetical_order)
			{
				BOOST_CHECK(calculator.SetVariableValue("c", -1.1));
				BOOST_CHECK(calculator.SetVariableValue("b", -1.123));
				BOOST_CHECK(calculator.SetVariableValue("e", -1.3456345));
				BOOST_CHECK(calculator.SetVariableValue("a", -1231.6546));
				BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::ADD, "b"));
				BOOST_CHECK(calculator.DefineFunction("x", "e", OperationType::ADD, "c"));
				map <string, OperationsFunction> m_functionNameList = { { "y",{ "a", OperationType::ADD , "b" }},
																		  {"x", {"e", OperationType::ADD, "c"}} };
			}
		BOOST_AUTO_TEST_SUITE_END()
			/*BOOST_FIXTURE_TEST_SUITE(MalovStyleInMicrosoftWordTxt, CalculatorFixture)
				BOOST_AUTO_TEST_SUITE(Test1_the_announcement_and_assignment_and_output_variables)
					BOOST_AUTO_TEST_CASE(declaring_var_and_get_value_NAN)
					{
						BOOST_CHECK(calculator.SetVariableIdentifier("x"));
						BOOST_CHECK(isnan(calculator.GetValue("x")));
					}
					BOOST_AUTO_TEST_CASE(set_variables_value_and_get_value_variables)
					{
						BOOST_CHECK(calculator.SetVariableValue("x", "42"));
						BOOST_CHECK_EQUAL(calculator.GetValue("x"), 42);
						BOOST_CHECK(calculator.SetVariableValue("x", "1.234"));
						BOOST_CHECK_EQUAL(calculator.GetValue("x"), 1.234);
						BOOST_CHECK(calculator.SetVariableValue("y", "x"));
						BOOST_CHECK(calculator.SetVariableValue("x", "99"));
					}
				BOOST_AUTO_TEST_SUITE_END()
				BOOST_AUTO_TEST_SUITE(Test2_declaring_functions)
					BOOST_AUTO_TEST_CASE(declare_variables_create_a_function_and_get_the_value_NAN)
					{
						BOOST_CHECK(calculator.SetVariableIdentifier("x"));
						BOOST_CHECK(calculator.SetVariableIdentifier("y"));
						BOOST_CHECK(calculator.SetFunction("XPlusY", "x", OperationType::ADD, "y"));
						BOOST_CHECK(isnan(calculator.GetValueFn("XPlusY")));
					}
					BOOST_AUTO_TEST_CASE(set_value_variables_after_calculate_the_functions_and_get_the_value_of_function)
					{
						BOOST_CHECK(calculator.SetVariableValue("x", "4"));
						BOOST_CHECK(calculator.SetVariableValue("y", "3"));
						BOOST_CHECK(calculator.SetFunction("XPlusY", "x", OperationType::ADD, "y"));
						BOOST_CHECK_EQUAL(calculator.GetValueFn("XPlusY"), 7);
						BOOST_CHECK(calculator.SetVariableValue("y", "10"));
						BOOST_CHECK_EQUAL(calculator.GetValueFn("XPlusY"), 14);
						BOOST_CHECK(calculator.SetVariableValue("z", "3.5"));
						BOOST_CHECK(calculator.SetFunction("XPlusYDivZ", "XPlusY", OperationType::DIV, "z"));
						BOOST_CHECK_EQUAL(calculator.GetValueFn("XPlusYDivZ"), 4);
					}
				BOOST_AUTO_TEST_SUITE_END()
					BOOST_AUTO_TEST_SUITE(Tests_Difference_Between_Fn_And_Let)
						BOOST_AUTO_TEST_CASE(When_change_a_variable_the_function_changes_the_value_of_this_variable)
						{
							BOOST_CHECK(calculator.SetVariableValue("v", "42"));
							BOOST_CHECK(calculator.SetVariableValue("variable", "3"));
							BOOST_CHECK(calculator.SetFunction("function", "v"));
							BOOST_CHECK_EQUAL(calculator.GetValueFn("function"), 42);
							BOOST_CHECK(calculator.SetVariableValue("v", "43"));
							BOOST_CHECK_EQUAL(calculator.GetValueFn("function"), 43);
						}
					BOOST_AUTO_TEST_SUITE_END()
					BOOST_AUTO_TEST_SUITE(Tests_Calculation_Area_Circle)
						BOOST_AUTO_TEST_CASE(Calculation_Process)
						{
							BOOST_CHECK(calculator.SetVariableIdentifier("radius"));
							BOOST_CHECK(calculator.SetVariableValue("pi", "3.14159265"));
							BOOST_CHECK(calculator.SetFunction("radiusSquared", "radius", OperationType::MUL, "radius"));
							BOOST_CHECK(calculator.SetFunction("circleArea", "pi", OperationType::MUL, "radiusSquared"));
							BOOST_CHECK(calculator.SetVariableValue("radius", "10"));
							BOOST_CHECK_CLOSE(calculator.GetValueFn("circleArea"), 314.15,1e-2);
							BOOST_CHECK(calculator.SetVariableValue("circle10Area", "circleArea"));
							BOOST_CHECK(calculator.SetVariableValue("radius", "20"));
							BOOST_CHECK(calculator.SetVariableValue("circle20Area", "circleArea"));
							BOOST_CHECK_CLOSE(calculator.GetValue("circle10Area"), 314.16, 1e-2);
							BOOST_CHECK_CLOSE(calculator.GetValue("pi"), 3.14, 1e-1);
							BOOST_CHECK_EQUAL(calculator.GetValue("radius"), 20);
							BOOST_CHECK_CLOSE(calculator.GetValue("circle20Area"), 1256.64, 1e-2);
						}
					BOOST_AUTO_TEST_SUITE_END()*/
			//BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()