#pragma once
#include "IShape.h"
#include "IShapeView.h"
#include <vector>
#include <memory>
#include "Difinition.h"
#include "DotView.h"
#include "LineSegment_view.h"
#include "Circle_view.h"
#include "Rectangle_view.h"
#include "Triangle_view.h"



class CShapesContainer
{
public:
	void AddDot(V2f const &pos);
	void  AddLineSegment(const V2f &dot1, const V2f &dot2, const string &lineColor);
	void  AddCircle(const V2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);
	void  AddRectangle(const V2f &dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	void  AddTriangle(const V2f &point1, const V2f &point2, const V2f &point3, string const &lineColor, string const &fillColor);
	vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> GetShapes() const;
private:
	ShapeColor HexToDecCodeColor(string const & colorHex);
	vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> m_shapes;
};

