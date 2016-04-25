#include "stdafx.h"
#include "LineSegment_view.h"

CLineSegmentView::CLineSegmentView(V2f const & dot1, V2f const & dot2, ShapeColor const & lineColor)
{
	m_line[0].position = V2f(dot1.x, dot1.y);
	m_line[1].position = V2f(dot2.x, dot2.y);
	m_line[0].color = sf::Color(lineColor.RR, lineColor.GG, lineColor.BB);
	m_line[1].color = sf::Color(lineColor.RR, lineColor.GG, lineColor.BB);
}
void CLineSegmentView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_line, 3, sf::Lines, states);
}
