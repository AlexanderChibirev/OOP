#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

using namespace std;
typedef sf::Vector2f V2f;

class CRectangle final :public ISolidShape
{
public:
	CRectangle(const V2f &cordTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	float GetShapeArea() const override;
	float GetShapePerimeter() const override;
	std::string ToString() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	V2f m_dotTopLeftCorner;
	float m_wight;
	float m_height;
	std::string m_lineColor;
	std::string m_fillColor;
};

