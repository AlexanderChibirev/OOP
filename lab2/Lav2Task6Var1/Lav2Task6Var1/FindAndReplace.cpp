#include "stdafx.h"

#include "FindAndReplace.h"
std::string FindAndReplace(const std::string & tpl, const std::string & searchString, const std::string & replaceString, std::vector<std::pair<int, int>> &positionUsedParamsP)
{
	if (searchString.empty())
	{
		return tpl;
	}
	std::string newText = tpl;
	size_t position = 0;
	bool wasSet = false;
	while ((position = newText.find(searchString, position)) != std::string::npos)
	{
		std::string leftPart;
		std::string rightPart;
		
		for (size_t i = 0; i < position; i++)
		{
			leftPart += newText[i];
		}

		for (size_t i = leftPart.size() + searchString.size(); i < newText.size(); ++i)
		{
			rightPart += newText[i];
		}

		for (auto &it : positionUsedParamsP)
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
			newText.clear();
			newText.append(leftPart).append(replaceString).append(rightPart);
			positionUsedParamsP.push_back(std::make_pair(position, position + replaceString.length() - 1));
			position = position + replaceString.length();
		}
		else
		{
			position++;
		}
		wasSet = false;
	}
	return newText;
}
