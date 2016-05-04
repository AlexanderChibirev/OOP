#include "stdafx.h"
#include "CreateShape.h"
#include "ShapesContainer.h"



CShapesContainer CreateShape(const string &dataShapes)
{
	CShapesContainer shapesContainer;
	istringstream ss(dataShapes);
	string nameShape;
	while (ss)
	{
		ss >> nameShape;
		if (ss.eof())
		{
			break;
		}
		if (nameShape == "point")
		{
			float x;
			float y;
			ss >> x;
			ss >> y;
			shapesContainer.AddDot(V2f(x, y));
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
			shapesContainer.AddLineSegment(V2f(x1, y1), V2f(x2, y2), lineColor);
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
			shapesContainer.AddTriangle(V2f(x1, y1), V2f(x2, y2), V2f(x3, y3), lineColor, fillColor);
		}
		else if (nameShape == "circle")
		{
			float x1;
			float y1;
			ss >> x1;
			ss >> y1;
			float radius;
			ss >> radius;
			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			shapesContainer.AddCircle(V2f(x1, y1), radius, lineColor, fillColor);
		}
		else if (nameShape == "rectangle")
		{
			float x1;
			ss >> x1;
			float y1;
			ss >> y1;
			float wight;
			ss >> wight;
			float height;
			ss >> height;
			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			shapesContainer.AddRectangle(V2f(x1, y1), wight, height, lineColor, fillColor);
		}
	}

	return shapesContainer;
}

