#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(const sf::Vector2f &point1, const sf::Vector2f &point2, const sf::Vector2f &point3, string const &lineColor, string const &fillColor);
	double GetShapeArea() const override;
	double GetShapePerimeter() const override;
	std::string GetShapeData() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	std::string m_lineColor;
	std::string m_fillColor;
	sf::Vector2f m_point1;
	sf::Vector2f m_point2;
	sf::Vector2f m_point3;
	
};

