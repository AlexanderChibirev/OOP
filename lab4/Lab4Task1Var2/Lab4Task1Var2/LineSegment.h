#pragma once
#include "IShape.h"
#include "Dot.h"
using namespace std;
typedef sf::Vector2f V2f;

class CLineSegment : public IShape
{
public:
	CLineSegment(const V2f &dot1, const V2f &dot2, const string &lineColor);
	virtual std::string ToString() const override;
	virtual std::string GetLineColor() const override;
	virtual float GetShapeArea() const override;
	virtual float GetShapePerimeter() const override;
private:
	string m_lineColor;
	V2f  m_dot1;
	V2f  m_dot2;
};
