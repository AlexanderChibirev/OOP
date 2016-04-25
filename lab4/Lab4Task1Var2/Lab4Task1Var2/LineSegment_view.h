#pragma once
#include "IShapeView.h"
#include "Difinition.h"

using namespace std;
typedef sf::Vector2f V2f;

class CLineSegmentView : public IShapeView
{
public:
	CLineSegmentView(V2f const &dot1, V2f const &dot2, ShapeColor const &lineColor);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
private:
	sf::Vertex m_line[2];
};