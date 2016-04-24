#include "stdafx.h"
#include "LineSegment.h"
#include "Dot.h"

CLineSegment::CLineSegment(const sf::Vector2f &dot1, const sf::Vector2f &dot2, const string &lineColor)
	:m_lineColor(lineColor),
	m_dot1(dot1),
	m_dot2(dot2)
{//да не ладно оставим так, потом молов прокомментирует и поймем уже как лучше
}
string CLineSegment::GetShapeData() const 
{
	return "LineSegment: Coordinates begin <" + to_string(m_dot1.x) + ", " + to_string(m_dot1.y) \
		+ ">" + ", Coordinates end <" + to_string(m_dot2.x) + ", " + to_string(m_dot2.y) \
		+ ", LineColor = " + GetLineColor() + ", Length Line = " + to_string(GetLengthLine()) \
		+ ", P = " + to_string(GetShapePerimeter()) + ", S = " + to_string(GetShapeArea()) + "\n";
}
string CLineSegment::GetLineColor() const 
{
	return m_lineColor;
}
double CLineSegment::GetShapeArea() const 
{
	return double(0);
}
double CLineSegment::GetShapePerimeter() const
{
	return GetLengthLine();
}
double CLineSegment::GetLengthLine() const
{
	return fabs(sqrt( (pow((m_dot2.x - m_dot1.x),2)) + (pow((m_dot2.y - m_dot1.y), 2))));
}

