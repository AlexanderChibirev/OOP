#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

using namespace std;
typedef sf::Vector2f V2f;

class CRectangle final :public ISolidShape
{
public:
	CRectangle(const V2f &m_dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	double GetShapeArea() const override;
	double GetShapePerimeter() const override;
	std::string ToString() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	V2f m_dotTopLeftCorner;
	double m_wight;
	double m_height;
	std::string m_lineColor;
	std::string m_fillColor;
};

