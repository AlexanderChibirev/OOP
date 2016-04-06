#pragma once
#include "IShape.h"

class CDot : public IShape
{
public:
	CDot(const sf::Vector2f &m_coordinates);
	virtual double GetAreaShape() const override;
	virtual double GetPerimeterShape() const override;
	virtual std::string GetNameShape() const override;
	virtual std::string GetLineColor() const override;
	sf::Vector2f GetCoordDot() const;
	~CDot();
private://
	sf::Vector2f m_coordinates;
};

