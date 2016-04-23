// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task1/Rational.h"

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}



/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}



	
//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
BOOST_AUTO_TEST_SUITE(DivisionDoubleNumbers)
	BOOST_AUTO_TEST_CASE(TestThenRaditionalNum)
	{
		CRational r(3, 5);
		BOOST_CHECK_CLOSE(r.ToDouble(), 0.6, 1e-10);
	}
	BOOST_AUTO_TEST_CASE(TestThenNumerationIsZero)
	{
		CRational r(0, 4);
		BOOST_CHECK_CLOSE(r.ToDouble(), 0, 1e-10);
	}
	BOOST_AUTO_TEST_CASE(TestThenResultMustBeRational)
	{
		CRational r(1, 3);
		BOOST_CHECK_CLOSE(r.ToDouble(), 0.333333, 1e-1);

	}
	BOOST_AUTO_TEST_CASE(cant_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
BOOST_AUTO_TEST_SUITE(TestUnaryMinusReturnsTheDifferenceOfTwoRationalNumbers)
	BOOST_AUTO_TEST_CASE(rational_number_and_integer)
	{
		VerifyRational(+CRational(2, 3), 2, 3);
	}
	BOOST_AUTO_TEST_CASE(rational_number_with_integer)
	{
		VerifyRational(+CRational(-2, 3), -2, 3);
	}
	BOOST_AUTO_TEST_CASE(integer_and_rational)
	{
		VerifyRational(+CRational(2, -3), -2, 3);
	}
BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(TestUnaryPlusReturnsTheResultOfAdditionTwoNum)
	BOOST_AUTO_TEST_CASE(rational_numbers)
	{
		VerifyRational(+CRational(2, 3), 2, 3);
	}
	BOOST_AUTO_TEST_CASE(rational_number_with_integer)
	{
		VerifyRational(+CRational(-2, 3), -2, 3);
	}
	BOOST_AUTO_TEST_CASE(integer_nuber_with_rational)
	{
		VerifyRational(+CRational(2, -3), -2, 3);
	}
BOOST_AUTO_TEST_SUITE_END()
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
BOOST_AUTO_TEST_SUITE(TestBinaryPlusReturnsTheResultOfAdditionTwoNum)
	BOOST_AUTO_TEST_CASE(rational_numbers)
	{
		VerifyRational(CRational(1, 2) + CRational(1, 6), 2, 3);
	}

	BOOST_AUTO_TEST_CASE(rational_number_with_integer)
	{
		VerifyRational(CRational(1, 2) + 1, 3, 2);
	}
	BOOST_AUTO_TEST_CASE(integer_nuber_with_rational)
	{
		VerifyRational(1 + CRational(1, 2), 3, 2);
	}
	BOOST_AUTO_TEST_CASE(does_not_changed_when_zero_is_added)
	{
		VerifyRational(CRational(1, 2) + CRational(), 1, 2);
		VerifyRational(CRational(1, 2) + 0, 1, 2);
		VerifyRational(0 + CRational(1, 2), 1, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
BOOST_AUTO_TEST_SUITE(TestBinaryMinusReturnsTheResultDifferenceTtwoRationalNumbers)
	BOOST_AUTO_TEST_CASE(rational_numbers)
	{
		VerifyRational(CRational(1, 2) - CRational(1, 6), 1, 3);
	}

	BOOST_AUTO_TEST_CASE(rational_number_and_integer)
	{
		VerifyRational(1 - CRational(1, 2), 1, 2);
	}
	BOOST_AUTO_TEST_CASE(integer_nuber_and_rational)
	{
		VerifyRational(CRational(1, 2) - 1, -1, 2);
	}
	BOOST_AUTO_TEST_CASE(does_not_changed_when_subtracts_zero)
	{
		VerifyRational(CRational(1, 2) - CRational(), 1, 2);
		VerifyRational(CRational(1, 2) - 0, 1, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
BOOST_AUTO_TEST_SUITE(TestUnaryPlus)
	BOOST_AUTO_TEST_CASE(addition_floating_point_integer)
	{
		CRational rational = CRational(1, 2);
		rational += CRational(1, 6);
		VerifyRational(rational, 2, 3);
	}
	BOOST_AUTO_TEST_CASE(addition_integer)
	{
		CRational rational = CRational(1, 2);
		rational += 1;
		VerifyRational(rational, 3, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
BOOST_AUTO_TEST_SUITE(TestUnaryMinus)
	BOOST_AUTO_TEST_CASE(subtract_floating_point_integer)
	{
		CRational minuend(1, 2);
		minuend -= CRational(1, 6);
		VerifyRational(minuend, 1, 3);
	}
	BOOST_AUTO_TEST_CASE(subtract_integer)
	{
		CRational minuend = CRational(1, 2);
		minuend -= 1;
		VerifyRational(minuend, -1, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
BOOST_AUTO_TEST_SUITE(TestMultiplicationReturnsTheResultTheProduct)
	BOOST_AUTO_TEST_CASE(rational_num)
	{
		VerifyRational( (CRational(1, 2) * CRational(2, 3)), 1, 3);
	}

	BOOST_AUTO_TEST_CASE(rational_and_integer)
	{
		VerifyRational( (CRational(1, 2) * CRational(-3)), -3, 2);
	}

	BOOST_AUTO_TEST_CASE(integer_and_rational)
	{
		VerifyRational( (CRational(7) *  CRational(2) / CRational(3)), 14, 3);
	}
BOOST_AUTO_TEST_SUITE_END()
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	(7*2) / 3     = (14/3)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
BOOST_AUTO_TEST_SUITE(TestDevisionReturnsTheResultQuotientOfTwoNum)
	BOOST_AUTO_TEST_CASE(rational_num)
	{
		VerifyRational((CRational(1, 2) / CRational(2, 3)), 3, 4);
	}

	BOOST_AUTO_TEST_CASE(rational_and_integer)
	{
		VerifyRational( (CRational(1, 2) / CRational(5)), 1, 10);
	}

	BOOST_AUTO_TEST_CASE(integer_and_rational)
	{
		VerifyRational( (CRational(7) / CRational(1, 2)), 14, 1);
	}
	BOOST_AUTO_TEST_CASE(can_not_divide_by_zero)
	{
		BOOST_REQUIRE_THROW(CRational(1, 2) / CRational(0, 1), std::invalid_argument);
		BOOST_REQUIRE_THROW(CRational(1, 2) / CRational(0), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
BOOST_AUTO_TEST_SUITE(TestMultiplication)
	BOOST_AUTO_TEST_CASE(multiplication_floating_point_integer)
	{		
		VerifyRational( (CRational(1, 2) *= CRational(2, 3)), 1, 3);
	}
	BOOST_AUTO_TEST_CASE(multiplication_integer)
	{
		VerifyRational((CRational(1, 2) *= 3), 3, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
BOOST_AUTO_TEST_SUITE(TestDevision)
	BOOST_AUTO_TEST_CASE(division_floating_point_integer)
	{
		VerifyRational( (CRational(1, 2) /= CRational(2, 3)), 3, 4);
	}
	BOOST_AUTO_TEST_CASE(division_integer)
	{
		VerifyRational((CRational(1, 2) /= 3), 1, 6);
	}
	BOOST_AUTO_TEST_CASE(can_not_divide_rational_and_zero)
	{
		BOOST_REQUIRE_THROW(CRational(1, 2) / CRational(0,1), std::invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
BOOST_AUTO_TEST_SUITE(CheckEqualityAndInequalityTwoNum)
	BOOST_AUTO_TEST_CASE(rational)
	{
		BOOST_CHECK(CRational(1, 2) == CRational(1, 2));
		BOOST_CHECK(!(CRational(1, 2) == CRational(2, 3)));
	}
	BOOST_AUTO_TEST_CASE(rational_and_integer)
	{
		BOOST_CHECK(CRational(4, 1) == CRational(4));
		BOOST_CHECK(!(CRational(1, 2) == CRational(7)));
	}
	BOOST_AUTO_TEST_CASE(integer_and_rational)
	{
		BOOST_CHECK(CRational(4) == CRational(4, 1));
		BOOST_CHECK(!(CRational(3) == CRational(2,3)));
	}
BOOST_AUTO_TEST_SUITE_END()
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
BOOST_AUTO_TEST_SUITE(OperatorLarger)
	BOOST_AUTO_TEST_CASE(larger_rational)
	{
		BOOST_CHECK(CRational(2, 1) > CRational(1, 2));
	}
	BOOST_AUTO_TEST_CASE(larger_rational_and_integer)
	{
		BOOST_CHECK(CRational(4, 1) > CRational(3));
	}
	BOOST_AUTO_TEST_CASE(larger_integer_and_rational)
	{
		BOOST_CHECK(CRational(3) > CRational(2, 3));
	}
BOOST_AUTO_TEST_SUITE_END()
/////////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(OperatorLess)
	BOOST_AUTO_TEST_CASE(less_rational)
	{
		BOOST_CHECK(CRational(1, 2) < CRational(2, 1));
	}
	BOOST_AUTO_TEST_CASE(less_rational_and_integer)
	{
		BOOST_CHECK(!(CRational(4, 1) < CRational(1)));
	}
	BOOST_AUTO_TEST_CASE(less_integer_and_rational)
	{
		BOOST_CHECK(!(CRational(4) < CRational(1, 4)));
	}
BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(OperatorLessOrEquality)
	BOOST_AUTO_TEST_CASE(Less_or_equality_rational)
	{
		BOOST_CHECK(!(CRational(1, 2) <= CRational(1, 3)));
	}
	BOOST_AUTO_TEST_CASE(Less_or_equality_rational_and_integer)
	{
		BOOST_CHECK(CRational(3) <= CRational(7,2));
	}
	BOOST_AUTO_TEST_CASE(Less_or_equality_integer_and_rational)
	{
		BOOST_CHECK(!(CRational(7,2) <= CRational(3)));
	}
BOOST_AUTO_TEST_SUITE_END()
///////////////////////////////////////////////////
BOOST_AUTO_TEST_SUITE(OperatorLargerOrEquality)
	BOOST_AUTO_TEST_CASE(larger_or_equality_rational)
	{
		BOOST_CHECK(CRational(1, 2) >= CRational(1, 3));
	}
BOOST_AUTO_TEST_CASE(larger_or_equality_rational_and_integer)
	{
		BOOST_CHECK(CRational(8, 2) >= CRational(3));
	}
	BOOST_AUTO_TEST_CASE(larger_or_equality_integer_and_rational)
	{
		BOOST_CHECK(!(CRational(3) >= CRational(8, 2)));
	}
BOOST_AUTO_TEST_SUITE_END()
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
BOOST_AUTO_TEST_SUITE(TestOutstream)
BOOST_AUTO_TEST_CASE(can_write_into_output_stream)
{
	std::ostringstream outstream = std::ostringstream();
	outstream << CRational(7, 15);
	BOOST_CHECK_EQUAL(outstream.str(), "7/15");
}
BOOST_AUTO_TEST_SUITE_END()
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15

//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
BOOST_AUTO_TEST_SUITE(TestInstream)
BOOST_AUTO_TEST_CASE(can_read_from_input_stream)
{
	std::istringstream instream = std::istringstream("7/15");
	CRational rational;
	instream >> rational;
	VerifyRational(rational, 7, 15);
}
BOOST_AUTO_TEST_SUITE_END()
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////



BOOST_AUTO_TEST_SUITE_END()
