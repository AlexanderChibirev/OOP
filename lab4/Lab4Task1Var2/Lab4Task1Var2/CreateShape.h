#pragma once

#include "IShape.h"
#include "IShapeView.h"

#include "LineSegment.h"
#include "LineSegment_view.h"

#include "Dot.h"
#include "DotView.h"

#include "Rectangle.h"
#include "Rectangle_view.h"

#include "Triangle.h"
#include "Triangle_view.h"

#include "Circle.h"
#include "Circle_view.h"

#include "Difinition.h"

ShapeColor HexToDecCodeColor(string const & colorHex);
pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateShape(const string &dataShapes);