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
	void AddShape(V2f const &pos);
	void  AddShape(const V2f &dot1, const V2f &dot2, const string &lineColor);
	void  AddShape(const V2f &centerCircle, float &radius, std::string const & lineColor, std::string const & fillColor);
	void  AddShape(const V2f &dotTopLeftCorner, float wight, float height, std::string const & lineColor, std::string const & fillColor);
	void  AddShape(const V2f &point1, const V2f &point2, const V2f &point3, string const &lineColor, string const &fillColor);
	vector<shared_ptr<IShape>> GetShapes()const;
	vector<shared_ptr<IShapeView>> GetShapesView() const;
private:
	ShapeColor HexToDecCodeColor(string const & colorHex);
	vector<shared_ptr<IShape>> m_shapes;
	vector<shared_ptr<IShapeView>> m_shapesView;
};

