#include "stdafx.h"
#include "Circle_view.h"

CCircleView::CCircleView(V2f const & pos, float radius, ShapeColor const & lineColor, ShapeColor const & fillColor)
{
	m_circle.setPosition({ pos.x - radius, pos.y - radius });
	m_circle.setRadius(radius);
	m_circle.setOutlineColor(sf::Color(lineColor.RR, lineColor.GG, lineColor.BB));
	m_circle.setOutlineThickness(2.f);
	m_circle.setFillColor(sf::Color(lineColor.RR, lineColor.GG, lineColor.BB));
}

void CCircleView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_circle, states);
}
