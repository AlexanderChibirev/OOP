#include "stdafx.h"
#include "LineSegment.h"
#include "Dot.h"

CLineSegment::CLineSegment(shared_ptr<CDot> &dot1, shared_ptr<CDot> &dot2, const string &lineColor)
	:m_lineColor(lineColor),
	m_dot1(dot1),
	m_dot2(dot2)
{//да не ладно оставим так, потом молов прокомментирует и поймем уже как лучше
}
string CLineSegment::GetNameShape() const 
{
	return "lineSegment";
}
string CLineSegment::GetLineColor() const 
{
	return m_lineColor;
}
double CLineSegment::GetAreaShape() const 
{
	return double(0);
}
double CLineSegment::GetPerimeterShape() const
{
	return GetLengthLine();
}
double CLineSegment::GetLengthLine() const
{
	return fabs(sqrt( (pow((m_dot2->GetCoordDot().x - m_dot1->GetCoordDot().x),2)) + (pow((m_dot2->GetCoordDot().y - m_dot1->GetCoordDot().y), 2))));
}

CLineSegment::~CLineSegment()
{
}
