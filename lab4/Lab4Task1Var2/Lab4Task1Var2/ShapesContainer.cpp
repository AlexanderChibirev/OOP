#include "stdafx.h"
#include "ShapesContainer.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void CShapesContainer::AddShape(Vector2f const & cord)
{
	m_shapes.push_back(make_shared<CDot>(cord));
}

void CShapesContainer::AddShape(const sf::Vector2f &dot1, const sf::Vector2f &dot2, const string &lineColor)
{
	m_shapes.push_back(make_shared<CLineSegment>(dot1, dot2, lineColor));
}

void CShapesContainer::AddShape(const sf::Vector2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor)
{
	m_shapes.push_back(make_shared<CCircle>(centerCircle, radius, lineColor, fillColor));
}

void CShapesContainer::AddShape(const sf::Vector2f &dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor)
{
	m_shapes.push_back(make_shared<CRectangle>(dotTopLeftCorner, wight, height,lineColor, fillColor));
}

void CShapesContainer::AddShape(const sf::Vector2f &point1, const sf::Vector2f &point2, const sf::Vector2f &point3, string const &lineColor, string const &fillColor)
{
	m_shapes.push_back(make_shared<CTriangle>(point1, point2, point3, lineColor, fillColor));
}

vector<shared_ptr<IShape>> CShapesContainer::GetShapes() const
{
	return m_shapes;
}