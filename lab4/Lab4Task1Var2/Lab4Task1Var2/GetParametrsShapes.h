#pragma once
#include "LineSegment.h"
#include "Dot.h"
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"


vector<shared_ptr<IShape>> GetParametrsShapes(const string &dataShapes);