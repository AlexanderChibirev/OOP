#pragma once
#include "ISolidShape.h"
#include "Dot.h"
using namespace std;
typedef sf::Vector2f V2f;

class CCircle final : public ISolidShape
{
public:
	CCircle(const V2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);

	double GetShapeArea() const override;
	double GetShapePerimeter() const override;
	std::string ToString() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	V2f m_centerCircle;
	double m_radius;
	std::string m_lineColor;
	std::string m_fillColor;
};

