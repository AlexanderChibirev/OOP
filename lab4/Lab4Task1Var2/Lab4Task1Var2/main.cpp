// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetDataFromFile.h"
#include "GetParametrsShapes.h"
#include "WriteResultInOutputFile.h"
#include "GetProcessedData.h"



int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file>'";
		return 1;
	}
	string inputFileName = argv[1];	
	string dataShapes = GetDataFromFile(inputFileName);
	vector<shared_ptr<IShape>> informationAboutShape = GetParametrsShapes(dataShapes);
	string result = GetProcessedData(informationAboutShape);
	string outputFileName = argv[2];
	if (!WriteResultInOutputFile(result, outputFileName))
	{
		return 1;
	}
    return 0;
}

