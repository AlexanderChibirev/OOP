#pragma once
#include "stdafx.h"
#include "IShapeSet.h"


class IShape : public IShapeSet
{
public:
	virtual ~IShape() = default;
	virtual double GetShapeArea() const = 0;
	virtual double GetShapePerimeter() const = 0;
	virtual std::string GetShapeData() const = 0;
	virtual std::string GetLineColor() const = 0;
	virtual std::string GetInnerRegion() const = 0;
};

