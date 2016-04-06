#pragma once
#include "stdafx.h"


class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetAreaShape() const = 0;
	virtual double GetPerimeterShape() const = 0;
	virtual std::string GetNameShape() const = 0;
	virtual std::string GetLineColor() const = 0;
};

