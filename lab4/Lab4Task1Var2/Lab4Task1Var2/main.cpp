// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LineSegment.h"
#include "Dot.h"
#include "IShape.h"

using namespace std;


int main()
{
	//vector<string> workWithUI(istream_iterator<string>(cin), (istream_iterator<string>()));
	//vector<string> workWithUI;
	std::vector<shared_ptr<IShape>> workWithUI;
	CLineSegment line1(std::make_shared<CDot>(sf::Vector2f(10, 0)), std::make_shared<CDot>(sf::Vector2f(0, 10)), "black"); //так уже лучше)	
	CLineSegment line2(std::make_shared<CDot>(sf::Vector2f(10, 6)), std::make_shared<CDot>(sf::Vector2f(1, 10)), "black"); //так уже лучше)
	std::cout << line1.GetLengthLine() << std::endl;
	std::cout << line2.GetLengthLine();
    return 0;
}

