#include "stdafx.h"
#include "ExpandTemplate.h"
#include "FindAndReplace.h"


std::string ExpandTemplate(std::string const& tpl, std::map< std::string, std::string> const& params)
{
	std::vector <std::string> paramsFirstKey;
	
	for (auto it = params.begin(); it != params.end(); ++it)///вывод на экран
	{
		paramsFirstKey.push_back(it->first);
	}

	sort(paramsFirstKey.begin(), paramsFirstKey.end(),
		[](const std::string & first, const std::string & second) -> bool
	{
		return first.size() > second.size();
	});
	
	std::string newTpl = tpl;
	for (size_t i = 0; i < paramsFirstKey.size(); ++i)
	{
		for (auto it = params.begin(); it != params.end(); ++it)///вывод на экран
		{
			if (it->first == paramsFirstKey[i])
			{
				newTpl = FindAndReplace(newTpl, it->first, it->second);
			}
		}
	}
	return newTpl;
}
