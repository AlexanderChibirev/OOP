#include "stdafx.h"
#include "WriteInOutputFile.h"


 
bool WriteInOutputFile(std::string const &outputFileName, const std::string & tpl)
{
	std::ofstream output(outputFileName);

	if (!output.is_open())
	{
		return true;
	}
	else
	{
		output << tpl;
	}
	return false;
}
