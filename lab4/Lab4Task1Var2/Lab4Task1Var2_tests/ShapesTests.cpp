#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include "../Lab4Task1Var2/Circle.h"
#include "../Lab4Task1Var2/Dot.h"
#include "../Lab4Task1Var2/LineSegment.h"
#include "../Lab4Task1Var2/Triangle.h"
#include "../Lab4Task1Var2/Rectangle.h"

using namespace std;
typedef sf::Vector2f V2f;


struct DotFixture
{
	CDot dot;
	DotFixture()
		: dot({ 1, 2 })
	{};
};

BOOST_FIXTURE_TEST_SUITE(Dot, DotFixture)

BOOST_AUTO_TEST_CASE(must_return_coord_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(dot.GetCoordDot().y, 2);
		BOOST_CHECK_EQUAL(dot.GetCoordDot().x, 1);
	}
	BOOST_AUTO_TEST_CASE(has_zero_perimeter)
	{
		BOOST_CHECK_EQUAL(dot.GetShapePerimeter(), 0);
	}
	BOOST_AUTO_TEST_CASE(has_zero_area)
	{
		BOOST_CHECK_EQUAL(dot.GetShapeArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(has_black_color)
	{
		BOOST_CHECK_EQUAL(dot.GetLineColor(), "#000000");
	}
	BOOST_AUTO_TEST_CASE(has_a_string_representation)
	{
		BOOST_CHECK_EQUAL(dot.ToString(), "Point: Coordinates <1.000000, 2.000000> P = 0.000000, S = 0.000000\n");
	}
BOOST_AUTO_TEST_SUITE_END()

struct LineSegmentFixture
{
	CLineSegment lineSegment;
	LineSegmentFixture()
		:lineSegment( { 274,286 }, { 303, 286 }, "#6495ed")
	{};
};

BOOST_FIXTURE_TEST_SUITE(LineSegment, LineSegmentFixture)
	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		BOOST_CHECK_EQUAL(lineSegment.GetShapePerimeter(), 29);
	}
	BOOST_AUTO_TEST_CASE(has_zero_area)
	{
		BOOST_CHECK_EQUAL(lineSegment.GetShapeArea(), 0);
	}
	BOOST_AUTO_TEST_CASE(must_return_color_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(lineSegment.GetLineColor(), "#6495ed");
	}
	BOOST_AUTO_TEST_CASE(has_a_string_representation)
	{
		BOOST_CHECK_EQUAL(lineSegment.ToString(), "LineSegment: Coordinates begin <274.000000, 286.000000>, Coordinates end <303.000000, 286.000000, LineColor = #6495ed, P = 29.000000, S = 0.000000\n");
	}

BOOST_AUTO_TEST_SUITE_END()

struct CircleFixture
{
	V2f cordCenterCircle = { 0, 1 };
	float radius = 50;
	CCircle circle;
	CircleFixture()
		: circle( cordCenterCircle, radius, "#000000", "#ffffff")
	{};
};

BOOST_FIXTURE_TEST_SUITE(Circle, CircleFixture)
	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		BOOST_CHECK_CLOSE(circle.GetShapePerimeter(), 314.15927, 1e-5);
	}
	BOOST_AUTO_TEST_CASE(has_area)
	{
		BOOST_CHECK_CLOSE(circle.GetShapeArea(), 7853.98145, 1e-5);
	}
	BOOST_AUTO_TEST_CASE(must_return_line_color_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(circle.GetLineColor(), "#000000");
	}
	BOOST_AUTO_TEST_CASE(must_return_fill_color_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(circle.GetInnerRegion(), "#ffffff");
	}
	BOOST_AUTO_TEST_CASE(has_a_string_representation)
	{
		BOOST_CHECK_EQUAL(circle.ToString(), "Circle: Coordinates center circle <0.000000, 1.000000> Radius = 50.000000, LineColor = #000000, InnerRegion = #ffffff, P = 314.159271, S = 7853.981445\n");
	}
BOOST_AUTO_TEST_SUITE_END()

struct TriangleFixture
{
	CTriangle triangle;
	TriangleFixture()
		: triangle( { 184, 600 }, { 274, 501 }, { 259, 645 }, "#6495ed", "#6495ed")
	{};
};

BOOST_FIXTURE_TEST_SUITE(Triangle, TriangleFixture)
	BOOST_AUTO_TEST_CASE(has_perimeter)
	{
		BOOST_CHECK_CLOSE(triangle.GetShapePerimeter(), 366.03802, 1e-5);
	}
	BOOST_AUTO_TEST_CASE(has_area)
	{
		BOOST_CHECK_CLOSE(triangle.GetShapeArea(), 5737.50000, 1e-5);
	}
	BOOST_AUTO_TEST_CASE(must_return_line_color_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(triangle.GetLineColor(), "#6495ed");
	}
	BOOST_AUTO_TEST_CASE(must_return_fill_color_specified_in_the_constructor)
	{
		BOOST_CHECK_EQUAL(triangle.GetInnerRegion(), "#6495ed");
	}
	BOOST_AUTO_TEST_CASE(has_a_string_representation)
	{
		BOOST_CHECK_EQUAL(triangle.ToString(), "Triangle: Coordinates point first<184.000000, 600.000000>, Coordinates point second<274.000000, 501.000000>, Coordinates point third <259.000000, 645.000000, LineColor = #6495ed, InnerRegion = #6495ed, P = 366.038025, S = 5737.500000\n");
	}
BOOST_AUTO_TEST_SUITE_END()


struct RectangleFixture
{
	CRectangle rectangle;
	RectangleFixture()
		: rectangle({ 258, 363 }, 124, 185, "#901981", "#901981")
	{};
};

BOOST_FIXTURE_TEST_SUITE(Rect, RectangleFixture)
BOOST_AUTO_TEST_CASE(has_perimeter)
{
	BOOST_CHECK_CLOSE(rectangle.GetShapePerimeter(), 618.00000, 1e-5);
}
BOOST_AUTO_TEST_CASE(has_area)
{
	BOOST_CHECK_CLOSE(rectangle.GetShapeArea(), 22940.00000, 1e-5);
}
BOOST_AUTO_TEST_CASE(must_return_line_color_specified_in_the_constructor)
{
	BOOST_CHECK_EQUAL(rectangle.GetLineColor(), "#901981");
}
BOOST_AUTO_TEST_CASE(must_return_fill_color_specified_in_the_constructor)
{
	BOOST_CHECK_EQUAL(rectangle.GetInnerRegion(), "#901981");
}
BOOST_AUTO_TEST_CASE(has_a_string_representation)
{
	BOOST_CHECK_EQUAL(rectangle.ToString(), "Rectangle: Coordinates <258.000000, 363.000000> Wight = 124.000000, Height = 185.000000, LineColor = #901981, InnerRegion = #901981, P = 618.000000, S = 22940.000000\n");
}
BOOST_AUTO_TEST_SUITE_END()









