#pragma once
#include "IShape.h"
#include "IShapeView.h"


void MergeData(vector<shared_ptr<IShape>> const &informationAboutShape, string &data);
string GetSortedData(vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> &informationAboutShape);