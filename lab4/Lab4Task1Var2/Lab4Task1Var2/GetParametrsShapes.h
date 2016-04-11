#pragma once
#include "LineSegment.h"
#include "Dot.h"
#include "IShape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Definition.h"

void HexToDecCodeColor(string const & colorHex, int &RR, int &GG, int &BB);
InfoAboutShapes GetParametrsShapes(const string &dataShapes);