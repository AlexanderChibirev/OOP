#pragma once
#include "IShapeView.h"
#include "Difinition.h"

using namespace std;
typedef sf::Vector2f V2f;

class CTriangleView : public IShapeView
{
public:
	CTriangleView(const V2f &point1, const V2f &point2, const V2f &point3, ShapeColor const &lineColor, ShapeColor const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::ConvexShape m_triangle;
};
