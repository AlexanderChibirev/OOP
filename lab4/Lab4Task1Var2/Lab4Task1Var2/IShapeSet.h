#pragma once
#include "stdafx.h"


class IShapeSet
{
public:
	virtual ~IShapeSet() = default;
	virtual std::string SetInnerRegion() const = 0;
	virtual double SetShapeArea() const = 0;
	virtual double SetShapePerimeter() const = 0;
	virtual std::string SetShapeData() const = 0;
	virtual std::string SetLineColor() const = 0;
};
