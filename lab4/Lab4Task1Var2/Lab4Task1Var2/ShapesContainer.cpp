#include "stdafx.h"
#include "ShapesContainer.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

void CShapesContainer::AddDot(V2f const & cord)
{
	m_shapes.push_back(make_pair(make_shared<CDot>(cord),
		make_shared<CDotView>(cord)));
}

void CShapesContainer::AddLineSegment(const V2f &dot1, const V2f &dot2, const string &lineColor)
{
	m_shapes.push_back(make_pair(make_shared<CLineSegment>(dot1, dot2, lineColor), 
		make_shared<CLineSegmentView>(dot1, dot2, HexToDecCodeColor(lineColor))));
}

void CShapesContainer::AddCircle(const V2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor)
{
	m_shapes.push_back(make_pair(make_shared<CCircle>(centerCircle, radius, lineColor, fillColor),
		make_shared<CCircleView>(centerCircle, radius, HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor))));
}

void CShapesContainer::AddRectangle(const V2f &cordTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor)
{
	m_shapes.push_back(make_pair(make_shared<CRectangle>(cordTopLeftCorner, wight, height, lineColor, fillColor),
		make_shared<CRectangleView>(cordTopLeftCorner, wight, height, HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor))));
}

void CShapesContainer::AddTriangle(const V2f &point1, const V2f &point2, const V2f &point3, string const &lineColor, string const &fillColor)
{
	m_shapes.push_back(make_pair(make_shared<CTriangle>(point1, point2, point3, lineColor, fillColor),
		make_shared<CTriangleView>(point1, point2, point3, HexToDecCodeColor(lineColor), HexToDecCodeColor(fillColor))));
}

vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> CShapesContainer::GetShapes() const
{
	return m_shapes;
}

ShapeColor CShapesContainer::HexToDecCodeColor(string const & colorHex)
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