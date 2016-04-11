#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

class CTriangle final : public ISolidShape
{
public:
	CTriangle(shared_ptr<CDot> &point1, shared_ptr<CDot> &point2, shared_ptr<CDot> &point3, string const &lineColor, string const &fillColor);
	~CTriangle();
	double GetAreaShape() const override;
	double GetPerimeterShape() const override;
	std::string GetNameShape() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;
private:
	std::string m_lineColor;
	std::string m_fillColor;
	std::shared_ptr<CDot> m_point1;
	std::shared_ptr<CDot> m_point2;
	std::shared_ptr<CDot> m_point3;
	
};

