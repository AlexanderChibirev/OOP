#pragma once
#include "IShape.h"
#include "Dot.h"


class CLineSegment : public IShape
{
public:
	CLineSegment(const sf::Vector2f &dot1, const sf::Vector2f &dot2, const string &lineColor);
	virtual std::string GetShapeData() const override;
	virtual std::string GetLineColor() const override;
	virtual double GetShapeArea() const override;
	virtual double GetShapePerimeter() const override;
	double GetLengthLine() const;
private:
	string m_lineColor;
	sf::Vector2f  m_dot1;
	sf::Vector2f  m_dot2;
};
//Надо принять их по shared ptr в конструктор
//твои точки как это сделать? первый раз у меня))

//У меня тоже)))) ахах мб так ?мда)
