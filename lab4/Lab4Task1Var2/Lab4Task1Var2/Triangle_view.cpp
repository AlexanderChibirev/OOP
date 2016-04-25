#include "stdafx.h"
#include "Triangle_view.h"

CTriangleView::CTriangleView(const V2f &point1, const V2f &point2, const V2f &point3, ShapeColor const &lineColor, ShapeColor const &fillColor)
{
	m_triangle.setPointCount(3);
	m_triangle.setPoint(0, V2f(point1.x, point1.y));
	m_triangle.setPoint(1, V2f(point2.x, point2.y));
	m_triangle.setPoint(2, V2f(point3.x, point3.y));
	m_triangle.setOutlineColor(sf::Color(lineColor.RR, lineColor.GG, lineColor.BB));
	m_triangle.setOutlineThickness(2.f);
	m_triangle.setFillColor(sf::Color(fillColor.RR, fillColor.GG, fillColor.BB));
}

void CTriangleView::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	target.draw(m_triangle, states);
}
