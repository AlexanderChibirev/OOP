#include "stdafx.h"

#include "FindAndReplace.h"
std::string FindAndReplace( std::string tpl, const std::string & searchString, const std::string & replaceString, std::vector<std::pair<size_t, size_t>> &positionUsedParams)
{
	if (searchString.empty())
	{
		return tpl;
	}
	size_t position = 0;
	bool wasSet = false;
	while ((position = tpl.find(searchString, position)) != std::string::npos)
	{
		std::string leftPart = tpl.substr(0, position);;
		std::string rightPart = tpl.substr(leftPart.size() + searchString.size(), tpl.size());
		for (auto &it : positionUsedParams)
		{
			if ((size_t(it.first) <= position) && (size_t(it.second) >= (position + searchString.length() - 1)))
			{
				wasSet = true;
				break;
			}
			if (position < size_t(it.first))
			{
				it.first += replaceString.length() - 1;
				it.second += replaceString.length() - 1;
			}
		}
		if(!wasSet)
		{
			tpl.clear();
			tpl.append(leftPart).append(replaceString).append(rightPart);
			positionUsedParams.push_back(std::make_pair(position, position + replaceString.length() - 1));
			position = position + replaceString.length();
		}
		else
		{
			position++;
		}
		wasSet = false;
	}
	return tpl;
}
