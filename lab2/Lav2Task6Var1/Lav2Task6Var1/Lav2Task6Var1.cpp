#include "stdafx.h"
#include "WriteInString.h"
#include "ExpandTemplate.h"
#include "WriteInOutputFile.h"

using namespace std;

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
		cout << "error with opening "<< inputFileName <<" file\n";
		return 1;
	}
	
	map <string, string> params;
	vector <string> paramsFirstKey;

	for (int i = 3; i < argc - 1; i = i + 2)
	{
		string search = argv[i];
		string reaplace = argv[i + 1];
		params.insert(pair <string, string> ( search, reaplace ) );
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
