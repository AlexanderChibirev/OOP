#pragma once
#include "ISolidShape.h"
#include "Dot.h"
#include "LineSegment.h"

class CRectangle final :public ISolidShape
{
public:
	CRectangle(std::shared_ptr<CDot> &m_dotTopLeftCorner, std::shared_ptr<CLineSegment> &wight, std::shared_ptr<CLineSegment> &height, std::string const & lineColor, std::string const & fillColor);
	~CRectangle();

	double GetAreaShape() const override;
	double GetPerimeterShape() const override;
	std::string GetNameShape() const override;
	std::string GetLineColor() const override;
	std::string GetInnerRegion() const override;


private:
	std::shared_ptr<CDot> m_dotTopLeftCorner;
	std::shared_ptr<CLineSegment> m_wight;//������
	std::shared_ptr<CLineSegment> m_height;//������ ����� ���� ��������� ����
	std::string m_lineColor;
	std::string m_fillColor;
};

