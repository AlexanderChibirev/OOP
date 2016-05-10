#include "stdafx.h"
#include "CreateShape.h"

ShapeColor HexToDecCodeColor(string const & colorHex)
{
	ShapeColor color;
	string dec = colorHex.substr(1, colorHex.size());
	dec.insert(2, " ");
	dec.insert(5, " ");
	std::stringstream ss;
	ss << std::hex << dec;
	ss >> color.RR;
	ss >> color.GG;
	ss >> color.BB;
	return color;
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreatePoint(istringstream &ss)
{
	float x;
	float y;
	ss >> x;
	ss >> y;
	return make_pair(make_shared<CDot>(V2f(x, y)),
		make_shared<CDotView>(V2f(x, y)));
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateLineSegment(istringstream &ss)
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
	return make_pair(make_shared<CLineSegment>(V2f(x1, y1), V2f(x2, y2), lineColor),
		make_shared<CLineSegmentView>(V2f(x1, y1), V2f(x2, y2), HexToDecCodeColor(lineColor)));
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateLineTriangle(istringstream &ss)
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
	return make_pair(make_shared<CTriangle>(V2f(x1, y1), V2f(x2, y2), V2f(x3, y3), lineColor, fillColor),
		make_shared<CTriangleView>(V2f(x1, y1), V2f(x2, y2), V2f(x3, y3), HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor)));
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateCircle(istringstream &ss)
{
	float x;
	float y;
	ss >> x;
	ss >> y;
	float radius;
	ss >> radius;
	string lineColor;
	ss >> lineColor;
	string fillColor;
	ss >> fillColor;
	return make_pair(make_shared<CCircle>(V2f(x, y), radius, lineColor, fillColor),
		make_shared<CCircleView>(V2f(x, y), radius, HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor)));
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateRectangle(istringstream &ss)
{
	float x;
	ss >> x;
	float y;
	ss >> y;
	float width;
	ss >> width;
	float height;
	ss >> height;
	string lineColor;
	ss >> lineColor;
	string fillColor;
	ss >> fillColor;
	return make_pair(make_shared<CRectangle>(V2f(x, y), width, height, lineColor, fillColor),
		make_shared<CRectangleView>(V2f(x, y), width, height, HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor)));
}

pair<shared_ptr<IShape>, shared_ptr<IShapeView>> CreateShape(const string &dataShapes)
{
	pair<shared_ptr<IShape>, shared_ptr<IShapeView>> emptyPointers;
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
			return CreatePoint(ss);
		}
		else if (nameShape == "lineSegment")
		{
			return CreateLineSegment(ss);
		}
		else if (nameShape == "triangle")
		{
			return CreateLineTriangle(ss);
		}
		else if (nameShape == "circle")
		{
			return CreateCircle(ss);
		}
		else if (nameShape == "rectangle")
		{
			return CreateRectangle(ss);
		}
	}
	return emptyPointers;
}

