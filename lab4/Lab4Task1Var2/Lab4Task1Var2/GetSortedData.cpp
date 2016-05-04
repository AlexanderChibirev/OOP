#include "stdafx.h"
#include "GetProcessedData.h"
#include "IShape.h"


void MergeData(vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> const &informationAboutShape, string &data)
{
	for (auto it : informationAboutShape)
	{
		data += it.first->ToString();
	}
}

string GetSortedData(CShapesContainer &informationAboutShape)
{
	string data;
	auto repositoryAuxiliary = informationAboutShape.GetShapes();
	sort(repositoryAuxiliary.begin(), repositoryAuxiliary.end(), [](pair<shared_ptr<IShape>, shared_ptr<IShapeView>> const &shape1,
		pair<shared_ptr<IShape>, shared_ptr<IShapeView>> const &shape2)
	{
		return shape1.first->GetShapeArea() < shape2.first->GetShapeArea();
	});
	MergeData(informationAboutShape.GetShapes(), data);
	data += "\n\n\n\n";

	sort(repositoryAuxiliary.begin(), repositoryAuxiliary.end(), [](pair<shared_ptr<IShape>, shared_ptr<IShapeView>> const &shape1,
		pair<shared_ptr<IShape>, shared_ptr<IShapeView>> const &shape2)
	{
		return shape1.first->GetShapePerimeter() < shape2.first->GetShapePerimeter();
	});
	MergeData(informationAboutShape.GetShapes(), data);
	return data;
}