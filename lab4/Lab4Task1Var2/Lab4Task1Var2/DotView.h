#pragma once
#include "stdafx.h"
#include "IShapeView.h"

using namespace std;
typedef sf::Vector2f V2f;

class CDotView: public IShapeView
{
public:
	CDotView(V2f const &pos);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::CircleShape m_dot;
};

