#include "stdafx.h"
#include "..\\Lab3Task2\Calculator.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include "..\\Lab3Task2\WorkWithUI.h"
#include "..\\Lab3Task2\Difinition.h"

struct CalculatorFixture
{
	CCalculator calculator;
};

BOOST_FIXTURE_TEST_SUITE(Calculator, CalculatorFixture)
	BOOST_AUTO_TEST_CASE(Does_not_provide_a_non_existent_variable)
	{
		BOOST_CHECK(!calculator.GetValue("b").is_initialized());
	}
	BOOST_AUTO_TEST_SUITE(When_declaring_a_variable)
		BOOST_AUTO_TEST_CASE(Sets_the_value_of_nan)
		{
			BOOST_CHECK(calculator.SetVariableIdentifier("b"));
			BOOST_CHECK(std::isnan(calculator.GetValue("b").get()));
		}
		BOOST_AUTO_TEST_CASE(Does_not_allow_to_set_a_variable_to_an_existing_name)
		{	
			BOOST_CHECK(calculator.SetVariableIdentifier("a"));
			BOOST_CHECK(!calculator.SetVariableIdentifier("a"));
		}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_FIXTURE_TEST_SUITE(Allows_you_to_define_a_variable_value, CalculatorFixture)
		BOOST_AUTO_TEST_CASE(May_identify_an_integer_number)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 12));
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(),12);
		}
		BOOST_AUTO_TEST_CASE(May_identify_an_double_number)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 1.1));
			BOOST_CHECK_EQUAL(calculator.GetValue("b").get(), 1.1);
		}
		BOOST_AUTO_TEST_CASE(May_identify_an_negative_number)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", -1.1));
			BOOST_CHECK_EQUAL(calculator.GetValue("b"), -1.1);			
		}
		BOOST_AUTO_TEST_CASE(Allows_you_to_specify_a_value_to_another_variable)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", -1.1));
			BOOST_CHECK(calculator.SetVariableValue("a", "b"));
			BOOST_CHECK_EQUAL(calculator.GetValue("a"), -1.1);
			BOOST_CHECK_EQUAL(calculator.GetValue("b"), -1.1);
		}
		BOOST_AUTO_TEST_CASE(Allows_you_to_specify_the_value_of_the_function)
		{
			BOOST_CHECK(calculator.SetVariableValue("a", 1));
			BOOST_CHECK(calculator.DefineFunction("y", "a"));
			BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 1);
		}
	BOOST_AUTO_TEST_SUITE_END()
		BOOST_FIXTURE_TEST_SUITE(Allows_you_to_declare_a_function, CalculatorFixture)
		BOOST_AUTO_TEST_CASE(Which_returns_the_value_of_an_existing_variable)
		{
			BOOST_CHECK(calculator.SetVariableValue("a", 1));
			BOOST_CHECK(calculator.DefineFunction("y", "a"));
			BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 1);
		}
		BOOST_AUTO_TEST_CASE(Which_returns_the_value_of_an_existing_function)
		{
			BOOST_CHECK(calculator.SetVariableValue("b", 1));
			BOOST_CHECK(calculator.SetVariableValue("a", 1));
			BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::ADD, "b"));
			BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 2);
		}
		BOOST_AUTO_TEST_CASE(changes_the_value_of_the_function_when_the_value_of_the_variable)
		{
			BOOST_CHECK(calculator.SetVariableValue("v", 42));
			BOOST_CHECK(calculator.DefineFunction("function", "v"));
			BOOST_CHECK_EQUAL(calculator.GetValueFn("function"), 42);
			BOOST_CHECK(calculator.SetVariableValue("v", 43));
			BOOST_CHECK_EQUAL(calculator.GetValueFn("function"), 43);
		}
		BOOST_AUTO_TEST_SUITE_END()


			BOOST_FIXTURE_TEST_SUITE(which_returns_the_result_of_a_binary_operation, CalculatorFixture)
				BOOST_AUTO_TEST_CASE(Adding_the_values_of_the_two_identifiers)
				{
					BOOST_CHECK(calculator.SetVariableValue("b", 1));
					BOOST_CHECK(calculator.SetVariableValue("a", 1));
					BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::ADD, "b"));
					BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 2);
				}
				BOOST_AUTO_TEST_CASE(Subtracting_the_values_of_the_two_identifiers)
				{
					BOOST_CHECK(calculator.SetVariableValue("b", 2));
					BOOST_CHECK(calculator.SetVariableValue("a", 1));
					BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::SUB, "b"));
					BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), -1);
				}
				BOOST_AUTO_TEST_CASE(Multiplying_the_values_of_the_two_identifiers)
				{
					BOOST_CHECK(calculator.SetVariableValue("b", 4));
					BOOST_CHECK(calculator.SetVariableValue("a", 1));
					BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::MUL, "b"));
					BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 4);
				}
				BOOST_AUTO_TEST_CASE(Divide_the_values_of_the_two_identifiers)
				{
					BOOST_CHECK(calculator.SetVariableValue("b", 4));
					BOOST_CHECK(calculator.SetVariableValue("a", 1));
					BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::DIV, "b"));
					BOOST_CHECK_EQUAL(calculator.GetValue("y").get(), 0.25);
				}
			BOOST_AUTO_TEST_SUITE_END()
		BOOST_FIXTURE_TEST_SUITE(Allows_to_obtain_values_of_the_functions_in_alphabetical_order, CalculatorFixture)
			BOOST_AUTO_TEST_CASE(returns_the_value_of_the_variable_in_alphabetical_order)
			{
				BOOST_CHECK(calculator.SetVariableValue("c", 3));
				BOOST_CHECK(calculator.SetVariableValue("b", 2));
				BOOST_CHECK(calculator.SetVariableValue("e", 1));
				BOOST_CHECK(calculator.SetVariableValue("a", 4));
				map <string, double> variableList = { {"a",4},
															{ "b",2 },
															{ "c",3 },
															{ "e",1 } };
				map <string, double> variableListTest;

				for (CCalculator::ConstIteratorForVariablesList iter = calculator.BeginItForVariablesList(); iter != calculator.EndItForVariablesList(); ++iter)
				{
					variableListTest[iter->first] = iter->second;
				}
				BOOST_CHECK(variableListTest == variableList);
			}
			BOOST_AUTO_TEST_CASE(returns_the_value_of_the_function_in_alphabetical_order)
			{
				BOOST_CHECK(calculator.SetVariableValue("c", 1));
				BOOST_CHECK(calculator.SetVariableValue("b", 1));
				BOOST_CHECK(calculator.SetVariableValue("e", 1));
				BOOST_CHECK(calculator.SetVariableValue("a", 3));
				BOOST_CHECK(calculator.DefineFunction("y", "a", OperationType::ADD, "b"));
				BOOST_CHECK(calculator.DefineFunction("x", "e", OperationType::ADD, "c"));
				map <string, double> functionListTest = { { "x", 2 }, { "y",4} };
				map <string, double> functionList;
				for (CCalculator::ConstIteratorForFunctionsList iter = calculator.BeginItForFunctionList(); iter != calculator.EndItForFunctionList(); ++iter)
				{
					functionList[iter->first] = calculator.GetValueFn(iter->first);
				}
				BOOST_CHECK(functionList == functionListTest);
			}
		BOOST_AUTO_TEST_SUITE_END()
			BOOST_AUTO_TEST_SUITE(May_Calculation_Area_Circle)
				BOOST_AUTO_TEST_CASE(Calculation_Process)
					{
						BOOST_CHECK(calculator.SetVariableIdentifier("radius"));
						BOOST_CHECK(calculator.SetVariableValue("pi", 3.14159265));
						BOOST_CHECK(calculator.DefineFunction("radiusSquared", "radius", OperationType::MUL, "radius"));
						BOOST_CHECK(calculator.DefineFunction("circleArea", "pi", OperationType::MUL, "radiusSquared"));
						BOOST_CHECK(calculator.SetVariableValue("radius", 10));
						BOOST_CHECK_CLOSE(calculator.GetValueFn("circleArea"), 314.15, 1e-2);
					}
					BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()