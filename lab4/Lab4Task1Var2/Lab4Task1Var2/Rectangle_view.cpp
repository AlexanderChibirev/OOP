#include "stdafx.h"
#include "Rectangle_view.h"


CRectangleView::CRectangleView(V2f const &cordTopLeftPointPos, const float &wight, const float &height, ShapeColor const &lineColor, ShapeColor const &fillColor)
{
	m_rectangle.setPosition({ cordTopLeftPointPos.x, cordTopLeftPointPos.y });
	m_rectangle.setSize({ wight, height });
	m_rectangle.setOutlineColor(sf::Color(lineColor.RR, lineColor.GG, lineColor.BB));
	m_rectangle.setOutlineThickness(2.f);
	m_rectangle.setFillColor(sf::Color(fillColor.RR, fillColor.GG, fillColor.BB));
}

void CRectangleView::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
}
