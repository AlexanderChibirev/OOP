#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

using namespace std;
typedef sf::Vector2f V2f;

class CTriangle final : public ISolidShape
{
public:
	CTriangle(const V2f &point1, const V2f &point2, const V2f &point3, string const &lineColor, string const &fillColor);
	float GetShapeArea() const override;
	float GetShapePerimeter() const override;
	std::string ToString() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	std::string m_lineColor;
	std::string m_fillColor;
	V2f m_point1;
	V2f m_point2;
	V2f m_point3;
	
};

