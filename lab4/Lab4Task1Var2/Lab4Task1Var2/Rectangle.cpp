#include "stdafx.h"
#include "Rectangle.h"


CRectangle::CRectangle(const V2f &cordTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor)
	:m_dotTopLeftCorner(cordTopLeftCorner),
	m_fillColor(fillColor),
	m_height(height),
	m_lineColor(lineColor),
	m_wight(wight)
	
{

}

double CRectangle::GetShapeArea() const
{
	return fabs(m_wight * m_height);
}
double CRectangle::GetShapePerimeter() const
{
	return  fabs(double(2) * (m_wight + m_height));
}
std::string CRectangle::ToString() const 
{
	return "Rectangle: Coordinates <" + to_string(m_dotTopLeftCorner.x) + ", " + to_string(m_dotTopLeftCorner.y) \
		+ "> Wight = " + to_string(m_wight) + ", Height = " + to_string(m_height) + ", LineColor = " + GetLineColor() + "InnerRegion = "+ GetInnerRegion() \
		+ ", P = "+ to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}
std::string CRectangle::GetLineColor() const
{
	return m_lineColor;
}
std::string CRectangle::GetInnerRegion() const
{
	return m_fillColor;
}


