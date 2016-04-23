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
BOOST_AUTO_TEST_SUITE(TestUnaryPlusReturnsTheResultOfAdditionTwo)
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

// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
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
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	(7*2) / 3     = (14/3)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
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
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////



BOOST_AUTO_TEST_SUITE_END()
