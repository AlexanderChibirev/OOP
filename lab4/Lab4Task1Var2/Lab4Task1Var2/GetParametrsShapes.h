#pragma once
#include "LineSegment.h"
#include "Dot.h"
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ShapesContainer.h"

void HexToDecCodeColor(string const & colorHex, int &RR, int &GG, int &BB);
CShapesContainer GetParametrsShapes(const string &dataShapes);