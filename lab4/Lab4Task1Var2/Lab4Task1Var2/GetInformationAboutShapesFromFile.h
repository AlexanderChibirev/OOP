#pragma once

#include "CreateShape.h"

vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> GetInformationAboutShapesFromFile(string & inputFileName, bool &wasError);