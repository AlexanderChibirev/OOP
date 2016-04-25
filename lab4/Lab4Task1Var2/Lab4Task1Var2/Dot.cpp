#include "stdafx.h"
#include "Dot.h"
CDot::CDot(const V2f &coordinates)
	:m_coordinates({ coordinates.x, coordinates.y })
{

}
double CDot::GetShapeArea() const
{
	return double(0);
}

double CDot::GetShapePerimeter() const
{
	return double(0);
}

std::string CDot::ToString() const
{
	return "Point: Coordinates <" + to_string(m_coordinates.x) + ", " + to_string(m_coordinates.y) + ">" \
		+ " P = " + to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}

V2f CDot::GetCoordDot() const
{
	return m_coordinates;
}

std::string CDot::GetLineColor() const
{
	return "Black";
}
