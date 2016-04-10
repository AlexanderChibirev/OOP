#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(std::shared_ptr<CDot> &point1, std::shared_ptr<CDot> &point2, std::shared_ptr<CDot> &point3, std::string const & lineColor, std::string const & fillColor)
	:m_lineColor(lineColor),
	m_fillColor(fillColor),
	m_point1(point1),
	m_point2(point2),
	m_point3(point3)
{
}

double CTriangle::GetAreaShape() const
{
	return double(0.5)*((m_point1->GetCoordDot().x - m_point3->GetCoordDot().x) * (m_point2->GetCoordDot().y - m_point3->GetCoordDot().y) - \
		(m_point2->GetCoordDot().x - m_point3->GetCoordDot().x) * (m_point1->GetCoordDot().y - m_point3->GetCoordDot().y));
}

double CTriangle::GetPerimeterShape() const
{
	return sqrt(pow((m_point2->GetCoordDot().x - m_point1->GetCoordDot().x), 2) + pow((m_point2->GetCoordDot().y - m_point1->GetCoordDot().y), 2)) + \
		sqrt(pow((m_point3->GetCoordDot().x - m_point1->GetCoordDot().x), 2) + pow((m_point3->GetCoordDot().y - m_point1->GetCoordDot().y), 2)) + \
		sqrt(pow((m_point3->GetCoordDot().x - m_point2->GetCoordDot().x), 2) + pow((m_point3->GetCoordDot().y - m_point2->GetCoordDot().y), 2));
}
std::string CTriangle::GetNameShape() const
{
	return "Triangle";
}
std::string CTriangle::GetLineColor() const
{
	return m_lineColor;
}
std::string CTriangle::GetInnerRegion() const
{
	return m_fillColor;
}

CTriangle::~CTriangle()
{
}
