#pragma once
#include "IShapeView.h"
#include "Difinition.h"

using namespace std;
typedef sf::Vector2f V2f;

class CRectangleView: public IShapeView
{
public:
	CRectangleView(V2f const &cordTopLeftPointPos,const float &wight,const float &height, ShapeColor const &lineColor, ShapeColor const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::RectangleShape m_rectangle;
};
