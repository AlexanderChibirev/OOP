#pragma once

std::string FindAndReplace(const std::string & tpl, const std::string & searchString, const std::string & replaceString, std::vector<std::pair<int, int>> &positionUsedParamsP);
