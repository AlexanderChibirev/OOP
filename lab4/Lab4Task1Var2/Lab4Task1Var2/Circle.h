#pragma once
#include "ISolidShape.h"
#include "Dot.h"

class CCircle final : public ISolidShape
{
public:
	CCircle(std::shared_ptr<CDot> &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);

	double GetAreaShape() const override;
	double GetPerimeterShape() const override;
	std::string GetNameShape() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;

	~CCircle();


private:
	std::shared_ptr<CDot> m_centerCircle;
	double m_radius;
	std::string m_lineColor;
	std::string m_fillColor;
};

