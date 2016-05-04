#pragma once

std::string FindAndReplace(std::string tpl, const std::string & searchString, const std::string & replaceString, std::vector<std::pair<size_t, size_t>> &positionUsedParamsP);
