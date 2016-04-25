#pragma once
#include "IShape.h"
#include "ShapesContainer.h"


void MergeData(vector<shared_ptr<IShape>> const &informationAboutShape, string &data);
string GetSortedData(CShapesContainer &informationAboutShape);