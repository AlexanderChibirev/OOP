#pragma once
#include "ISolidShape.h"
#include "Dot.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(const sf::Vector2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);

	double GetShapeArea() const override;
	double GetShapePerimeter() const override;
	std::string GetShapeData() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	sf::Vector2f m_centerCircle;
	double m_radius;
	std::string m_lineColor;
	std::string m_fillColor;
};

