#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(std::shared_ptr<CLineSegment> &side1, std::shared_ptr<CLineSegment> &side2, std::shared_ptr<CLineSegment> &side3, std::string const & lineColor, std::string const & fillColor);

	double GetAreaShape() const override;
	double GetPerimeterShape() const override;
	std::string GetNameShape() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;


private:
	double CTriangle::GetPForHeronsFormula() const;
	std::string m_lineColor;
	std::string m_fillColor;
	std::shared_ptr<CLineSegment> m_side1;
	std::shared_ptr<CLineSegment> m_side2;
	std::shared_ptr<CLineSegment> m_side3;
	~CTriangle();
};

