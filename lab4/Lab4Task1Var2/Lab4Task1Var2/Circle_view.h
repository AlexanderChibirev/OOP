#pragma once
#include "stdafx.h"
#include "IShapeView.h"
#include "Difinition.h"

using namespace std;
typedef sf::Vector2f V2f;

class CCircleView : public IShapeView
{
public:
	CCircleView(V2f const &pos, float radius, ShapeColor const &lineColor, ShapeColor const &fillColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::CircleShape m_circle;
};