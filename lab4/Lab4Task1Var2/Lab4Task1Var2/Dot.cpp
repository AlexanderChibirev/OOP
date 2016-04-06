#include "stdafx.h"
#include "Dot.h"
CDot::CDot(const sf::Vector2f &coordinates)
	:m_coordinates({ coordinates.x, coordinates.y })
{

}
double CDot::GetAreaShape() const
{
	return double(0);
}

double CDot::GetPerimeterShape() const
{
	return double(0);
}

std::string CDot::GetNameShape() const
{
	return "Dot";
}

sf::Vector2f CDot::GetCoordDot() const
{
	return m_coordinates;
}

std::string CDot::GetLineColor() const
{
	return "Black";
}

CDot::~CDot()//заеб
{
}
