#include "stdafx.h"
#include "Triangle.h"


CTriangle::CTriangle(std::shared_ptr<CLineSegment> &side1, std::shared_ptr<CLineSegment> &side2, std::shared_ptr<CLineSegment> &side3, std::string const & lineColor, std::string const & fillColor)
	:m_lineColor(lineColor),
	m_fillColor(fillColor),
	m_side1(side1),
	m_side2(side2),
	m_side3(side3)
{
}

double CTriangle::GetAreaShape() const
{
	return sqrt(GetPForHeronsFormula()*(GetPForHeronsFormula() - m_side1->GetLengthLine())*(GetPForHeronsFormula() - m_side2->GetLengthLine())*(GetPForHeronsFormula() - m_side3->GetLengthLine()));
}

double CTriangle::GetPForHeronsFormula() const
{
	return GetPerimeterShape() / double(2);
}
double CTriangle::GetPerimeterShape() const
{
	return m_side1->GetLengthLine() + m_side2->GetLengthLine() + m_side3->GetLengthLine();
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
