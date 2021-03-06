#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(const V2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor)
	:m_centerCircle(centerCircle),
	m_radius(radius),
	m_lineColor(lineColor),
	m_fillColor(fillColor)
{
}

float CCircle::GetShapeArea() const
{
	return  float(fabs(M_PI * pow(m_radius, 2)));
}
float CCircle::GetShapePerimeter() const
{
	return float(fabs(float(2) * M_PI * m_radius));
}
std::string CCircle::ToString() const
{
	return "Circle: Coordinates center circle <" + to_string(m_centerCircle.x) + ", " + to_string(m_centerCircle.y) \
		+ "> Radius = " + to_string(m_radius) + ", LineColor = " + GetLineColor() + ", InnerRegion = " + GetInnerRegion() \
		+ ", P = " + to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}
std::string CCircle::GetLineColor() const
{
	return m_lineColor;
}
std::string CCircle::GetInnerRegion() const 
{
	return m_fillColor;
}