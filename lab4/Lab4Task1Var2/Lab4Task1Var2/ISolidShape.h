#pragma once
#include "stdafx.h"
#include "IShape.h"

class ISolidShape: public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual std::string GetInnerRegion() const = 0;
};

