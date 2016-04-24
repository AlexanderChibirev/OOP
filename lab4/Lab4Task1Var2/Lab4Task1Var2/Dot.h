#pragma once
#include "IShape.h"

class CDot : public IShape
{
public:
	CDot(const sf::Vector2f &m_coordinates);
	virtual double GetShapeArea() const override;
	virtual double GetShapePerimeter() const override;
	virtual std::string GetShapeData() const override;
	virtual std::string GetLineColor() const override;
	sf::Vector2f GetCoordDot() const;
private://
	sf::Vector2f m_coordinates;
};

