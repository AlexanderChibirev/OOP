#include "stdafx.h"
#include "GetProcessedData.h"
#include "IShape.h"

string GetProcessedData(vector<shared_ptr<IShape>> &informationAboutShape)
{
	map <double, string> area;
	map <double, string> perimeter;
	for (auto &it : informationAboutShape)
	{
		perimeter[it->GetPerimeterShape()] = it->GetNameShape();
		area[it->GetAreaShape()] = it->GetNameShape();
	}
	string result;
	for (auto &it : area)
	{
		result += it.second + ": area = " + to_string(it.first) + "\n";
	}
	result += "\n";
	for (auto it = perimeter.rbegin(); it != perimeter.rend(); ++it)
	{
		result += it->second + ": perimeter = " + to_string(it->first) + "\n";
	}
	return result;
}