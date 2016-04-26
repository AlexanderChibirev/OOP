#pragma once
#include "IShape.h"
using namespace std;
typedef sf::Vector2f V2f;

class CDot : public IShape
{
public:
	CDot(const V2f &coordinates);
	virtual float GetShapeArea() const override;
	virtual float GetShapePerimeter() const override;
	virtual std::string ToString() const override;
	virtual std::string GetLineColor() const override;
	V2f GetCoordDot() const;
private:
	V2f m_coordinates;
};

