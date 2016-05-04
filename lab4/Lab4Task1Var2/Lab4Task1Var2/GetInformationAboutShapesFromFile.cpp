#include "stdafx.h"
#include "GetInformationAboutShapesFromFile.h"

vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> GetInformationAboutShapesFromFile(string & inputFileName, bool &wasError)
{
	ifstream inputFile;
	inputFile.open(inputFileName);
	string line;
	string result;
	vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> shapes;
	if (!inputFile.is_open())
	{
		wasError = true;
	}
	else
	{
		while (!inputFile.eof())
		{
			getline(inputFile, line);
			auto shape = CreateShape(line);
			shapes.push_back(move(shape));
		}
		
	}
	return shapes;
}
