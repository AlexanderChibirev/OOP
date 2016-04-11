#pragma once
#include "stdafx.h"
#include "IShape.h"

struct InfoAboutShapes
{
	vector<shared_ptr<IShape>> informationAboutShape;
	vector<shared_ptr<sf::Shape>> sfmlShapes;
};