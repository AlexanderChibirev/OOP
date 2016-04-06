#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(std::shared_ptr<CDot> &dotTopLeftCorner, std::shared_ptr<CLineSegment> &wight, std::shared_ptr<CLineSegment> &height, std::string const & lineColor, std::string const & fillColor)
	:m_fillColor(fillColor),
	m_height(height),
	m_lineColor(lineColor),
	m_wight(wight),
	m_dotTopLeftCorner(dotTopLeftCorner)
{

}

double CRectangle::GetAreaShape() const
{
	return m_wight->GetLengthLine() * m_height->GetLengthLine();
}
double CRectangle::GetPerimeterShape() const
{
	return  double(2) * (m_wight->GetLengthLine() + m_height->GetLengthLine());
}
std::string CRectangle::GetNameShape() const 
{
	return "Rectangle";
}
std::string CRectangle::GetLineColor() const
{
	return m_lineColor;
}
std::string CRectangle::GetInnerRegion() const
{
	return m_fillColor;
}


CRectangle::~CRectangle()
{
}
