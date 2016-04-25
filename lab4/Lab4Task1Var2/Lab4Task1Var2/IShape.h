#pragma once
#include "stdafx.h"


class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetShapeArea() const = 0;
	virtual double GetShapePerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetLineColor() const = 0;
};