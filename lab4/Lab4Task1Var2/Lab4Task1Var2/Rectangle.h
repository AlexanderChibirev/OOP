#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

class CRectangle final :public ISolidShape
{
public:
	CRectangle(const sf::Vector2f &m_dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	double GetShapeArea() const override;
	double GetShapePerimeter() const override;
	std::string GetShapeData() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	sf::Vector2f m_dotTopLeftCorner;
	double m_wight;//ширина
	double m_height;//высота давно пора запомнить пидр
	std::string m_lineColor;
	std::string m_fillColor;
};

