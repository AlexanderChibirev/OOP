#include "stdafx.h"

#include "FindAndReplace.h"
std::string FindAndReplace(const std::string & tpl, const std::string & searchString, const std::string & replaceString, std::map < int, int > & positionUsedParams)
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
		bool wasShift = false;
		for (auto &it : positionUsedParams)
		{
		/*	if (size_t(it.first) > position)
			{
				it.first += 
			}*/
			if ((size_t(it.first) <= position) && (size_t(it.second) >= (position + searchString.length() - 1)))
			{	
				wasSet = true;
				break;
			}
		}
		
		if(!wasSet)
		{
			newText.clear();
			newText.append(leftPart).append(replaceString).append(rightPart);
			positionUsedParams[position] = position + replaceString.length() - 1;
			position = position + replaceString.length();
		}
		else
		{
			position = position + replaceString.length();
		}
		wasSet = false;
	}
	return newText;
}
