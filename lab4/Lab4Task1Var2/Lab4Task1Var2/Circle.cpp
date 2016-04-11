#include "stdafx.h"
#include "Circle.h"


CCircle::CCircle(std::shared_ptr<CDot> &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor)
	:m_centerCircle(centerCircle),
	m_radius(radius),
	m_lineColor(lineColor),
	m_fillColor(fillColor)
{
}

double CCircle::GetAreaShape() const
{
	return  fabs(M_PI * pow(m_radius, 2));
}
double CCircle::GetPerimeterShape() const
{
	return fabs(double(2) * M_PI * m_radius);
}
std::string CCircle::GetNameShape() const
{
	return "circle";
}
std::string CCircle::GetLineColor() const
{
	return m_lineColor;
}
std::string CCircle::GetInnerRegion() const 
{
	return m_fillColor;
}
CCircle::~CCircle()
{
}
