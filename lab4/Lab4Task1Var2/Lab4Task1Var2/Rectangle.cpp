#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(std::shared_ptr<CDot> &dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor)
	:m_dotTopLeftCorner(dotTopLeftCorner),
	m_fillColor(fillColor),
	m_height(height),
	m_lineColor(lineColor),
	m_wight(wight)
	
{

}

double CRectangle::GetAreaShape() const
{
	return fabs(m_wight * m_height);
}
double CRectangle::GetPerimeterShape() const
{
	return  fabs(double(2) * (m_wight + m_height));
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
