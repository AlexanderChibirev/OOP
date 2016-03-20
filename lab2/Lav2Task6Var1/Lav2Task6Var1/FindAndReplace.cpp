#include "stdafx.h"

#include "FindAndReplace.h"

std::string FindAndReplace(const std::string & tpl, const std::string & searchString, const std::string & replaceString)
{
	if (searchString.empty())
	{
		return tpl;
	}
	std::string newTpl;

	size_t position = 0;
	size_t afterChangingPosition = 0;

	while ((position = tpl.find(searchString, position)) != std::string::npos)
	{
		newTpl.append(tpl, afterChangingPosition, position - afterChangingPosition).append(replaceString);
		position += searchString.length();
		afterChangingPosition = position;
	}
	newTpl.append(tpl, afterChangingPosition);
	return newTpl;
}
