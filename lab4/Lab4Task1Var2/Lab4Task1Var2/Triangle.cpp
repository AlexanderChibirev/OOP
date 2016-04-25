#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(const V2f &point1, const V2f &point2, const V2f &point3, string const &lineColor, string const &fillColor)
	:m_lineColor(lineColor),
	m_fillColor(fillColor),
	m_point1(point1),
	m_point2(point2),
	m_point3(point3)
{
}

double CTriangle::GetShapeArea() const
{
	return fabs(double(0.5)*((m_point1.x - m_point3.x) * (m_point2.y - m_point3.y) - \
		(m_point2.x - m_point3.x) * (m_point1.y - m_point3.y)));
}

double CTriangle::GetShapePerimeter() const
{
	return fabs(sqrt(pow((m_point2.x - m_point1.x), 2) + pow((m_point2.y - m_point1.y), 2)) + \
		sqrt(pow((m_point3.x - m_point1.x), 2) + pow((m_point3.y - m_point1.y), 2)) + \
		sqrt(pow((m_point3.x - m_point2.x), 2) + pow((m_point3.y - m_point2.y), 2)));
}
std::string CTriangle::ToString() const
{
	return "Triangle: Coordinates point first<" + to_string(m_point1.x) + ", " + to_string(m_point1.y) \
		+ ">, Coordinates point second<" + to_string(m_point2.x) + ", " + to_string(m_point2.y) \
		+ ">, Coordinates point third <" + to_string(m_point3.x) + ", " + to_string(m_point3.y) \
		+ ", LineColor = " + GetLineColor() + ", InnerRegion = " + GetInnerRegion() \
		+ ", P = " + to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}
std::string CTriangle::GetLineColor() const
{
	return m_lineColor;
}
std::string CTriangle::GetInnerRegion() const
{
	return m_fillColor;
}
