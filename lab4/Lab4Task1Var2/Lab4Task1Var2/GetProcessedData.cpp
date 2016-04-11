#include "stdafx.h"
#include "GetProcessedData.h"
#include "IShape.h"

string GetProcessedData(vector<shared_ptr<IShape>> &informationAboutShape)
{
	vector< pair<double, string> > area;
	vector< pair<double, string> > perimeter;
	int count = 1;
	for (auto &it : informationAboutShape)
	{
		perimeter.push_back(pair<double, string>(it->GetPerimeterShape(), it->GetNameShape()));
		area.push_back(pair<double, string>(it->GetAreaShape(), it->GetNameShape()));
		count++;
	}
	string result;
	sort(area.begin(), area.end());
	for (auto &it : area)
	{
		result += it.second + ": area = " + to_string(it.first) + "\n";
	}
	result += "\n";
	sort(perimeter.rbegin(), perimeter.rend());
	for (auto &it :perimeter)
	{
		result += it.second + ": perimeter = " + to_string(it.first) + "\n";
	}
	return result;
}