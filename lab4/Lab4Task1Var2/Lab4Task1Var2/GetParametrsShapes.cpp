#include "stdafx.h"
#include "GetParametrsShapes.h"


vector<shared_ptr<IShape>> GetParametrsShapes(const string &dataShapes)
{
	vector<shared_ptr<IShape>> informationAboutShape;

	istringstream ss(dataShapes);
	string nameShape;

	while (ss)
	{
		ss >> nameShape;
		if (nameShape == "point")
		{
			float x;
			float y;
			ss >> x;
			ss >> y;
			informationAboutShape.push_back(make_shared<CDot>(V2f(x, y)));
		}
		else if (nameShape == "lineSegment")
		{
			float x1;
			float y1;

			float x2;
			float y2;

			string lineColor;

			ss >> x1;
			ss >> y1;
			ss >> x2;
			ss >> y2;
			ss >> lineColor;
			informationAboutShape.push_back(make_shared<CLineSegment>(make_shared<CDot>(V2f(10, 0)), (make_shared<CDot>(V2f(0, 10))), "#00ff00"));
		}
		else if (nameShape == "triangle")
		{
			float x1;
			float y1;
			ss >> x1;
			ss >> y1;

			float x2;
			float y2;
			ss >> x2;
			ss >> y2;

			float x3;
			float y3;
			ss >> x3;
			ss >> y3;

			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			informationAboutShape.push_back(make_shared<CTriangle>(make_shared<CDot>(V2f(x1, y1)), make_shared<CDot>(V2f(x2, y2)), make_shared<CDot>(V2f(x2, y2)), lineColor, fillColor));
		}
		else if (nameShape == "circle")
		{
			float x1;
			float y1;
			ss >> x1;
			ss >> y1;
			double radius;
			ss >> radius;
			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			informationAboutShape.push_back(make_shared<CCircle>(make_shared<CDot>(V2f(x1, y1)), radius, lineColor, fillColor));
		}
		else if (nameShape == "rectangle")
		{
			float x1;
			ss >> x1;

			float y1;
			ss >> y1;

			double wight;
			ss >> wight;

			double height;
			ss >> height;

			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			informationAboutShape.push_back(make_shared<CRectangle>(make_shared<CDot>(V2f(x1, y1)), wight, height, lineColor, fillColor));
		}
	}

	return informationAboutShape;
}

