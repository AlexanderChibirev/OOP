#include "stdafx.h"
#include "..\\Lab3Task2\Calculator.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include "..\\Lab3Task2\WorkWithUI.h"


BOOST_AUTO_TEST_SUITE(Calculator_class)
	//BOOST_AUTO_TEST_SUITE(VariableDeclarate)
	BOOST_AUTO_TEST_CASE(TestsIncorrectVariable)
	{
		CCalculator IncorrectVariable;
		BOOST_CHECK(IncorrectVariable.IsDeclareVariable("b1213") == false);
		BOOST_CHECK(IncorrectVariable.IsDeclareVariable("b1213") == true);
	}
	//BOOST_AUTO_TEST_CASE(TestsCorrectVariable)
	//{
	//	CCalculator CorrectVariable;
	//	BOOST_CHECK(!CorrectVariable.IsDeclareVariable("Var1"));
	//}
	//BOOST_AUTO_TEST_SUITE_END()
	//BOOST_AUTO_TEST_SUITE(SetValueForVariable)//variable definition
	//	BOOST_AUTO_TEST_SUITE_END()
	//	BOOST_AUTO_TEST_SUITE(WhenAVariableIsAFloatingPointNumberCorrect)
	//		BOOST_AUTO_TEST_CASE(TestsWhenAllRight)
	//		{
	//			CCalculator correctVariable;
	//			BOOST_CHECK_EQUAL((correctVariable.PutInfoInVariableList("Var1", "1.1")), true);
	//			BOOST_CHECK_EQUAL(correctVariable.GetVariableValue("Var1"), "1.1");
	//		}
	//	BOOST_AUTO_TEST_SUITE_END()
	//	BOOST_AUTO_TEST_SUITE(WhenTheIdentifierHasAlreadyBeenDeclared)
	//		BOOST_AUTO_TEST_CASE(TestsSimple)
	//		{
	//			CCalculator alreadyBeenDeclared;
	//			alreadyBeenDeclared.IsDeclareVariable("Var1");
	//			BOOST_CHECK_EQUAL((alreadyBeenDeclared.PutInfoInVariableList("Var2", "1.1")), true);
	//			BOOST_CHECK_EQUAL((alreadyBeenDeclared.PutInfoInVariableList("Var1", "Var2")), true);
	//			BOOST_CHECK_EQUAL(alreadyBeenDeclared.GetVariableValue("Var1"), "1.1");
	//			BOOST_CHECK_EQUAL(alreadyBeenDeclared.GetVariableValue("Var2"), "1.1");
	//		}
	//	BOOST_AUTO_TEST_SUITE_END()
	//	BOOST_AUTO_TEST_SUITE(TestPrintFunction)
	//		BOOST_AUTO_TEST_CASE(WhenUserIntroducedIntegerValue)
	//		{
	//			CCalculator calculatorIntValue;
	//			string variable = "Var1";
	//			string value = "1";
	//			BOOST_CHECK_EQUAL((calculatorIntValue.PutInfoInVariableList(variable, value)), true);
	//		}
	//		BOOST_AUTO_TEST_CASE(WhenTheIdentifierIsNotDefined)
	//			{
	//				CCalculator calculatorNotDefined;
	//				string variable = "Var1";
	//				BOOST_CHECK(!calculatorNotDefined.IsDeclareVariable(variable));
	//			}
	//	BOOST_AUTO_TEST_SUITE_END()
	//	BOOST_AUTO_TEST_SUITE(TestPrintVarsFunction)
	//		BOOST_AUTO_TEST_CASE(WhenVariableSortAlphabetically)
	//		{
	//			CCalculator variableSortAlphabetically;
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("a", "12"), true);
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("bBb", "157"), true);
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("bB", "157"), true);
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("b", "1.4"), true);
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("cV", "1.4"), true);
	//			BOOST_CHECK_EQUAL(variableSortAlphabetically.PutInfoInVariableList("c", "1.4"), true);
	//			variableSortAlphabetically.PrintVars();
	//		}
	//		BOOST_AUTO_TEST_CASE(WhenValueOfTheVariableIsNotDefined)
	//		{
	//			CCalculator valueNan;
	//			string variable = "B";
	//			BOOST_CHECK(!valueNan.IsDeclareVariable(variable));
	//			valueNan.PrintVars();
	//		}
	//		
	//	BOOST_AUTO_TEST_SUITE_END()
	//BOOST_AUTO_TEST_SUITE_END()
	//	BOOST_AUTO_TEST_SUITE(TestsMalov)
	//	BOOST_AUTO_TEST_CASE(Test1TheAnnouncementAndAssignmentAndOutputVariables)
	//	{
	//		CCalculator calculation;
	//		BOOST_CHECK(!calculation.IsDeclareVariable("x"));
	//		BOOST_CHECK_EQUAL(calculation.GetVariableValue("x"), "nan");//проверяем
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "42"), true);
	//		BOOST_CHECK_EQUAL(calculation.GetVariableValue("x"),"42");//проверка
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "1.234"), true);
	//		calculation.CheckValueForPrint("x");//вывод в cout
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("y", "x"), true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "99"), true);
	//		calculation.PrintVars();
	//	}
	//	BOOST_AUTO_TEST_CASE(Test2DeclaringFunctions)
	//	{
	//		CCalculator calculation;
	//		BOOST_CHECK(!calculation.IsDeclareVariable("x"));
	//		BOOST_CHECK(!calculation.IsDeclareVariable("y"));
	//		BOOST_CHECK(calculation.CheckNameFn("XPlusY", "x", "+", "y") == true);
	//		calculation.CheckValueForPrint("XPlusY");//nan
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "3"), true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("y", "4"), true);
	//		calculation.CheckValueForPrint("XPlusY");//7.00
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("x", "10"), true);
	//		calculation.CheckValueForPrint("XPlusY");//14.00
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("z", "3.5"), true);
	//		BOOST_CHECK(calculation.CheckNameFn("XPlusYDivZ", "XPlusY", "/", "z") == true);
	//		calculation.CheckValueForPrint("XPlusY");//7.00
	//		calculation.Printfns();//не по алфавиту подправить
	//	}
	//	BOOST_AUTO_TEST_CASE(TestsDifferenceBetweenFnAndLet)
	//	{
	//		CCalculator calculation;
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("v", "42"), true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("variable", "v"), true);
	//		BOOST_CHECK(calculation.CheckNameFn("function", "v", "funWithOneValue", "v") == true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("v", "43"), true);
	//		BOOST_CHECK_EQUAL(calculation.GetVariableValue("variable"), "42");//проверка
	//		BOOST_CHECK_EQUAL(calculation.GetFn("function"), "43");//проверка
	//	}
	//	BOOST_AUTO_TEST_CASE(TestsCalculationAreaCircle)
	//	{
	//		CCalculator calculation;
	//		calculation.IsDeclareVariable("radius");
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("pi", "3.14159265"), true);
	//		BOOST_CHECK(calculation.CheckNameFn("radiusSquared", "radius", "*", "radius") == true);
	//		BOOST_CHECK(calculation.CheckNameFn("circleArea", "pi", "*", "radiusSquared") == true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("radius", "10"), true);
	//		calculation.CheckValueForPrint("circleArea");
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("circle10Area", "circleArea"), true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("radius", "20"), true);
	//		BOOST_CHECK_EQUAL(calculation.PutInfoInVariableList("circle20Area", "circleArea"), true);
	//		calculation.Printfns();
	//		calculation.PrintVars();

	//	}
	//	BOOST_AUTO_TEST_CASE(TestsCalculationFibonacciSequence)
	//	{
	//		CCalculator calculationFibonacci;
	//		BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v0", "0"), true);
	//		BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v1", "1"), true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib0", "v0", "funWithOneValue", "v0") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib1", "v1", "funWithOneValue", "v1") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib2", "fib1", "+", "fib0") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib3", "fib2", "+", "fib1") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib4", "fib3", "+", "fib2") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib5", "fib4", "+", "fib3") == true);
	//		BOOST_CHECK(calculationFibonacci.CheckNameFn("fib6", "fib5", "+", "fib4") == true);
	//		calculationFibonacci.Printfns();
	//		cout << endl;
	//		BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v0", "1"), true);
	//		BOOST_CHECK_EQUAL(calculationFibonacci.PutInfoInVariableList("v1", "1"), true);
	//		calculationFibonacci.Printfns();
	//		cout << endl;
	//	}
		BOOST_AUTO_TEST_SUITE_END()