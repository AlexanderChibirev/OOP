#pragma once
#include "IShape.h"
#include "Dot.h"


class CLineSegment : public IShape
{
public:
	CLineSegment(std::shared_ptr<CDot> dot1, std::shared_ptr<CDot> dot2, const std::string &lineColor);
	virtual std::string GetNameShape() const override;
	virtual std::string GetLineColor() const override;
	virtual double GetAreaShape() const override;
	virtual double GetPerimeterShape() const override;
	double GetLengthLine() const;
	~CLineSegment();
private:
	std::string m_lineColor;
	std::shared_ptr<CDot> m_dot1;
	std::shared_ptr<CDot> m_dot2;
};
//Надо принять их по shared ptr в конструктор
//твои точки как это сделать? первый раз у меня))

//У меня тоже)))) ахах мб так ?мда)
