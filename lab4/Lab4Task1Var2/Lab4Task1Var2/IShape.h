#pragma once
#include "stdafx.h"


class IShape
{
public:
	virtual ~IShape() = default;
	virtual float GetShapeArea() const = 0;
	virtual float GetShapePerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetLineColor() const = 0;
};