#include "stdafx.h"
#include "WriteInString.h"
#include "WriteInOutputFile.h"
#include "FindAndReplace.h"
using namespace std;

struct ByLength : public std::binary_function<string, string, bool>
{
	bool operator()(const string& lhs, const string& rhs) const
	{
		if (lhs.length() == rhs.length())
		{
			return lhs > rhs;
		}
		return lhs.length() > rhs.length();
	}
};


typedef map<string, string, ByLength> lenmap;

std::string ExpandTemplate(std::string const& tpl, lenmap params)
{
	std::string newTpl;
	std::string tplTemp;
	std::istringstream iss(tpl);
	int count = 0;
	int iteratorTpl = 0;

	while (!iss.eof())
	{
		iss >> tplTemp;
		iteratorTpl += tplTemp.size();
		string spaceTpl;
		for (size_t i = iteratorTpl; i < tpl.size(); ++i)
		{
			if (tpl[i] == ' ' || tpl[i] == '\n')
			{
				spaceTpl += tpl[i];
				iteratorTpl++;
			}
			else
			{
				break;
			}
		}
		bool wasFind = false;
		//если че тут просто потом добавить еще цикл, по длине TplTemp, если без нее норм, то убрать wasFind, поставить break;
		for (auto it = params.begin(); it != params.end(); ++it)
		{
			std::string checkTpl = FindAndReplace(tplTemp, it->first, it->second);
			if (checkTpl == "" && count == params.size() - 1 && !wasFind)
			{
				newTpl += tplTemp + spaceTpl;
				wasFind = true;
			}
			else if (checkTpl != "")
			{
				newTpl += checkTpl + spaceTpl;
			}
			count++;
		}
		count = 0;
	}
	return newTpl;
}


int main(int argc, char** argv)
{

	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc < 5 || argc % 2 == 0)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file> <search string> <replace string> ....'";
		return 1;
	}

	string inputFileName = argv[1];
	string tpl;
	if (WriteInString(inputFileName, tpl))
	{
		cout << "error with opening " << inputFileName << " file\n";
		return 1;
	}

	lenmap params;
	
	for (int i = 3; i < argc - 1; i = i + 2)
	{
		params[argv[i]] = argv[i + 1];
	}

	tpl = ExpandTemplate(tpl, params);

	string outputFileName = argv[2];
	if (WriteInOutputFile(outputFileName, tpl))
	{
		cout << "error with opening " << outputFileName << " file\n";
		return 1;
	}

	return 0;
}
