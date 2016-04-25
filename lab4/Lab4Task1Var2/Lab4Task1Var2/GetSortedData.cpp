#include "stdafx.h"
#include "GetProcessedData.h"
#include "IShape.h"


void MergeData(vector<shared_ptr<IShape>> const &informationAboutShape, string &data) 
{
	for (auto it : informationAboutShape)
	{
		data += it->ToString();
	}
}

string GetSortedData(CShapesContainer &informationAboutShape)
{
	string data;
	auto repositoryAuxiliary = informationAboutShape.GetShapes();
	sort(repositoryAuxiliary.begin(), repositoryAuxiliary.end(), [](shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapeArea() < shape2->GetShapeArea();
	});
	MergeData(informationAboutShape.GetShapes(), data);
	data += "\n\n\n\n";
	sort(repositoryAuxiliary.begin(), repositoryAuxiliary.end(), [](shared_ptr<IShape> const &shape1, shared_ptr<IShape> const &shape2)
	{
		return shape1->GetShapePerimeter() > shape2->GetShapePerimeter();
	});
	MergeData(informationAboutShape.GetShapes(), data);
	return data;
}