#include "stdafx.h"
#include "LineSegment.h"
#include "Dot.h"

CLineSegment::CLineSegment(const V2f &dot1, const V2f &dot2, const string &lineColor)
	:m_lineColor(lineColor),
	m_dot1(dot1),
	m_dot2(dot2)
{
}
string CLineSegment::ToString() const 
{
	return "LineSegment: Coordinates begin <" + to_string(m_dot1.x) + ", " + to_string(m_dot1.y) \
		+ ">" + ", Coordinates end <" + to_string(m_dot2.x) + ", " + to_string(m_dot2.y) \
		+ ", LineColor = " + GetLineColor()\
		+ ", P = " + to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}
string CLineSegment::GetLineColor() const 
{
	return m_lineColor;
}
float CLineSegment::GetShapeArea() const 
{
	return float(0);
}
float CLineSegment::GetShapePerimeter() const
{
	return fabs(sqrt((pow((m_dot2.x - m_dot1.x), 2)) + (pow((m_dot2.y - m_dot1.y), 2))));

}

