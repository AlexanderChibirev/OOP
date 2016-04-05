#include "stdafx.h"
#include "..\\Lab3Task2\Calculator.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>



BOOST_AUTO_TEST_SUITE(Calculator_class)
	BOOST_AUTO_TEST_SUITE(VariableDeclarate)
	BOOST_AUTO_TEST_CASE(TestsIncorrectVariable)
	{
		CCalculator IncorrectVariable;
		BOOST_CHECK(IncorrectVariable.DeclareVariable("1213") == FIRST_SYMBOL_IS_NOT_LETTER);
		BOOST_CHECK(IncorrectVariable.DeclareVariable("b1213") == IS_ALL_OK);
		BOOST_CHECK(IncorrectVariable.DeclareVariable("b1213") == VAR_HAS_ALREADY_BEEN_DECLARED);
	}
	BOOST_AUTO_TEST_CASE(TestsCorrectVariable)
	{
		CCalculator CorrectVariable;
		BOOST_CHECK(CorrectVariable.DeclareVariable("Var1") == IS_ALL_OK);
	}
	BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(SetValueForVariable)//variable definition
		BOOST_AUTO_TEST_SUITE(WhenAVariableIsAFloatingPointNumberIncorrect)
		BOOST_AUTO_TEST_CASE(TestsWhenPointInBeginning)
			{
				CCalculator IncorrectVariable;
				string variable = "Var1";
				string value = ".1";
				BOOST_CHECK_EQUAL(IncorrectVariable.PutInfoInVariableList(variable, value), INCORRECT_ENTER);
			}
			BOOST_AUTO_TEST_CASE(TestsWhenPointInInTheEnd)
			{
				CCalculator IncorrectVariable;
				string variable = "Var1";
				string value = "1.";
				BOOST_CHECK_EQUAL(IncorrectVariable.PutInfoInVariableList(variable, value), INCORRECT_ENTER);
			}
			BOOST_AUTO_TEST_CASE(TestsWhenMoreThanOnePoint)
			{
				CCalculator IncorrectVariable;
				string variable = "Var1";
				string value = "1.1.3232";
				BOOST_CHECK_EQUAL(IncorrectVariable.PutInfoInVariableList(variable, value), INCORRECT_ENTER);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(WhenAVariableIsAFloatingPointNumberCorrect)
			BOOST_AUTO_TEST_CASE(TestsWhenAllRight)
			{
				CCalculator correctVariable;
				BOOST_CHECK_EQUAL((correctVariable.PutInfoInVariableList("Var1", "1.1")), IS_ALL_OK);
				BOOST_CHECK_EQUAL(correctVariable.GetVariableValue("Var1"), "1.1");
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(WhenTheIdentifierHasAlreadyBeenDeclared)
			BOOST_AUTO_TEST_CASE(TestsSimple)
			{
				CCalculator alreadyBeenDeclared;
				alreadyBeenDeclared.DeclareVariable("Var1");
				BOOST_CHECK_EQUAL((alreadyBeenDeclared.PutInfoInVariableList("Var2", "1.1")), IS_ALL_OK);
				BOOST_CHECK_EQUAL((alreadyBeenDeclared.PutInfoInVariableList("Var1", "Var2")), VAR_HAS_ALREADY_BEEN_DECLARED);
				BOOST_CHECK_EQUAL(alreadyBeenDeclared.GetVariableValue("Var1"), "1.1");
				BOOST_CHECK_EQUAL(alreadyBeenDeclared.GetVariableValue("Var2"), "1.1");
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(TestPrintFunction)
			BOOST_AUTO_TEST_CASE(WhenUserIntroducedIntegerValue)
			{
				CCalculator calculatorIntValue;
				string variable = "Var1";
				string value = "1";
				BOOST_CHECK_EQUAL((calculatorIntValue.PutInfoInVariableList(variable, value)), IS_ALL_OK);
			}
			BOOST_AUTO_TEST_CASE(WhenTheIdentifierIsNotDefined)
				{
					CCalculator calculatorNotDefined;
					string variable = "Var1";
					BOOST_CHECK(calculatorNotDefined.DeclareVariable(variable) == IS_ALL_OK);
				}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(TestPrintVarsFunction)
			BOOST_AUTO_TEST_CASE(WhenVariableListEmpty)
			{
				CCalculator variableListEmpty;
				BOOST_CHECK(variableListEmpty.CheckVarOnCoincidence("s"));
			}
			BOOST_AUTO_TEST_CASE(WhenVariableSortAlphabetically)
			{
				CCalculator variableSortAlphabetically;
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("a", "12"), IS_ALL_OK);
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("bBb", "157"), IS_ALL_OK);
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("bB", "157"), IS_ALL_OK);
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("b", "1.4"), IS_ALL_OK);
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("cV", "1.4"), IS_ALL_OK);
				BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("c", "1.4"), IS_ALL_OK);
				variableSortAlphabetically.PrintVars();
			}
			BOOST_AUTO_TEST_CASE(WhenValueOfTheVariableIsNotDefined)
			{
				CCalculator valueNan;
				string variable = "B";
				BOOST_CHECK(valueNan.DeclareVariable(variable)== IS_ALL_OK);
				valueNan.PrintVars();
			}
			
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(TestsMalov)
		BOOST_AUTO_TEST_CASE(Test1TheAnnouncementAndAssignmentAndOutputVariables)
		{
			CCalculator calculation;
			BOOST_CHECK(calculation.DeclareVariable("x") == IS_ALL_OK);
			BOOST_CHECK_EQUAL(calculation.GetVariableValue("x"), "nan");//проверяем
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "42"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.GetVariableValue("x"),"42");//проверка
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "1.234"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.CheckValueForPrint("x");//вывод в cout
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("y", "x"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "99"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.PrintVars();
		}
		BOOST_AUTO_TEST_CASE(Test2DeclaringFunctions)
		{
			CCalculator calculation;
			BOOST_CHECK(calculation.DeclareVariable("x") == IS_ALL_OK);
			BOOST_CHECK(calculation.DeclareVariable("y") == IS_ALL_OK);
			BOOST_CHECK(calculation.CheckNameFn("XPlusY", "x", "+", "y") == true);
			calculation.CheckValueForPrint("XPlusY");//nan
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "3"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("y", "4"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.CheckValueForPrint("XPlusY");//7.00
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "10"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.CheckValueForPrint("XPlusY");//14.00
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("z", "3.5"), IS_ALL_OK);
			BOOST_CHECK(calculation.CheckNameFn("XPlusYDivZ", "XPlusY", "/", "z") == true);
			calculation.CheckValueForPrint("XPlusY");//7.00
			calculation.Printfns();//не по алфавиту подправить
		}
		BOOST_AUTO_TEST_CASE(TestsDifferenceBetweenFnAndLet)
		{
			CCalculator calculation;
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("v", "42"), IS_ALL_OK);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("variable", "v"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK(calculation.CheckNameFn("function", "v", "funWithOneValue", "v") == true);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("v", "43"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.GetVariableValue("variable"), "42");//проверка
			BOOST_CHECK_EQUAL(calculation.GetFn("function"), "43");//проверка
		}
		BOOST_AUTO_TEST_CASE(TestsCalculationAreaCircle)
		{
			CCalculator calculation;
			calculation.DeclareVariable("radius");
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("pi", "3.14159265"), IS_ALL_OK);
			BOOST_CHECK(calculation.CheckNameFn("radiusSquared", "radius", "*", "radius") == true);
			BOOST_CHECK(calculation.CheckNameFn("circleArea", "pi", "*", "radiusSquared") == true);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("radius", "10"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.CheckValueForPrint("circleArea");
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("circle10Area", "circleArea"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("radius", "20"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("circle20Area", "circleArea"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculation.Printfns();
			calculation.PrintVars();

		}
		BOOST_AUTO_TEST_CASE(TestsCalculationFibonacciSequence)
		{
			CCalculator calculationFibonacci;
			BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v0", "0"), IS_ALL_OK);
			BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v1", "1"), IS_ALL_OK);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib0", "v0", "funWithOneValue", "v0") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib1", "v1", "funWithOneValue", "v1") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib2", "fib1", "+", "fib0") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib3", "fib2", "+", "fib1") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib4", "fib3", "+", "fib2") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib5", "fib4", "+", "fib3") == true);
			BOOST_CHECK(calculationFibonacci.CheckNameFn("fib6", "fib5", "+", "fib4") == true);
			calculationFibonacci.Printfns();
			cout << endl;
			BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v0", "1"), VAR_HAS_ALREADY_BEEN_DECLARED);
			BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v1", "1"), VAR_HAS_ALREADY_BEEN_DECLARED);
			calculationFibonacci.Printfns();
			cout << endl;
		}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()