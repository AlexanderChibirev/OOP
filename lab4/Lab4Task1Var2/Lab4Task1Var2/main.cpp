// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LineSegment.h"
#include "Dot.h"
#include "IShape.h"
#include "Rectangle.h"
#include <istream>
#include <sstream>
#include <memory>

using namespace std;
typedef sf::Vector2f V2f;
string WriteDataOfFile (string & inputFileName)
{

	ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "Failed to open input file for reading\n";
	}
	string data;
	while (!inputFile.eof())
	{
		getline(inputFile, data);
	}
	return data;
}

int main(int argc, char** argv)
{
	if (argc != 3)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file>'";
		return 1;
	}
	string inputFileName = argv[1];
	//string outputFileName = argv[2];

	vector<shared_ptr<IShape>> workWithUI;
	string lineUser = "rectangle 20 30 17 25 #ff0000 #00ff00";
	istringstream ss(lineUser);
	string options;
	CLineSegment line1(make_shared<CDot>(V2f(10, 0)), make_shared<CDot>(V2f(0, 10)), "black"); //так уже лучше)	
	CLineSegment line2(make_shared<CDot>(V2f(10, 6)), make_shared<CDot>(V2f(1, 10)), "black"); //так уже лучше)
	while(ss)
	{
		ss >> options;
		if(options == "rectangle")
		{
			//CRectangle(std::shared_ptr<CDot> &m_dotTopLeftCorner, std::shared_ptr<CLineSegment> &wight, std::shared_ptr<CLineSegment> &height, std::string const & lineColor, std::string const & fillColor);
			//workWithUI.push_back(make_shared<CRectangle>(make_shared<CDot>(V2f(0, 10)), line1, line2, "asd", "sa"));
		}
	}
	
	workWithUI.push_back(make_shared<CDot>(V2f(10, 0)));
	
//	CLineSegment line1(make_shared<CDot>(V2f(10, 0)), make_shared<CDot>(V2f(0, 10)), "black");
//	CLineSegment line2(make_shared<CDot>(V2f(10, 6)), make_shared<CDot>(V2f(1, 10)), "black");
	std::cout << line1.GetLengthLine() << std::endl;
	std::cout << line2.GetLengthLine();
    return 0;
}

