#include "stdafx.h"
#include "DotView.h"


CDotView::CDotView(V2f const &cord)
{
	m_dot.setPosition({ cord.x, cord.y });
	m_dot.setRadius(1);
}

void CDotView::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_dot, states);
}
