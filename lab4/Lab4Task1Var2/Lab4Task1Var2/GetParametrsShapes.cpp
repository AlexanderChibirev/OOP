#include "stdafx.h"
#include "GetParametrsShapes.h"
#include "ShapesContainer.h"

void HexToDecCodeColor(string const & colorHex, int &RR, int &GG, int &BB) 
{
	string dec = colorHex.substr(1,colorHex.size());
	dec.insert(2, " ");
	dec.insert(5, " ");
	std::stringstream ss;
	ss << std::hex << dec;
	ss >> RR;
	ss >> GG;
	ss >> BB;
}

CShapesContainer GetParametrsShapes(const string &dataShapes)
{
	CShapesContainer shapesContainer;
	//InfoAboutShapes vectors;
	istringstream ss(dataShapes);
	string nameShape;
	//int RR;
	//int GG;
	//int BB;

	while (ss)
	{
		ss >> nameShape;
		if (ss.eof())
		{
			break;
		}
		if (nameShape == "point")
		{
			float x;
			float y;
			ss >> x;
			ss >> y;
			shapesContainer.AddShape(V2f(x, y));
			/*vectors.informationAboutShape.push_back(make_shared<CDot>(V2f(x, y)));

			shared_ptr<sf::CircleShape> shape = make_shared<sf::CircleShape>();
			shape->setRadius(1);
			shape->setPosition(x, y);
			vectors.sfmlShapes.push_back(shape);*/
		}
		else if (nameShape == "lineSegment")
		{
			float x1;
			float y1;

			float x2;
			float y2;

			string lineColor;

			ss >> x1;
			ss >> y1;
			ss >> x2;
			ss >> y2;
			ss >> lineColor;
			shapesContainer.AddShape(V2f(x1, y1), V2f(x2, y2), lineColor);
			/*vectors.informationAboutShape.push_back(make_shared<CLineSegment>(V2f(x1, y1), (V2f(x2, y2)), lineColor));

			shared_ptr<sf::RectangleShape> shape = make_shared<sf::RectangleShape>();
			float lengthLineSegment = sqrt((pow((x2 - x1), 2)) + (pow((y2 - y1), 2)));
			double angleOfRotation = (atan((y2 - y1) / (x2 - x1))) * 180 / M_PI;
			shape->setSize(sf::Vector2f(float(lengthLineSegment), float(0.1)));
			shape->rotate(float(angleOfRotation));
			shape->setPosition(x1, y1);
			HexToDecCodeColor(lineColor, RR, GG, BB);
			shape->setOutlineThickness(1);
			shape->setOutlineColor(sf::Color(RR, GG, BB));
			vectors.sfmlShapes.push_back(shape);*/
		}
		else if (nameShape == "triangle")
		{
			float x1;
			float y1;
			ss >> x1;
			ss >> y1;

			float x2;
			float y2;
			ss >> x2;
			ss >> y2;

			float x3;
			float y3;
			ss >> x3;
			ss >> y3;

			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			shapesContainer.AddShape(V2f(x1, y1), V2f(x2, y2), V2f(x3, y3), lineColor, fillColor);
			/*	vectors.informationAboutShape.push_back(make_shared<CTriangle>(V2f(x1, y1), V2f(x2, y2), V2f(x3, y3), lineColor, fillColor));

				shared_ptr<sf::ConvexShape> shape = make_shared<sf::ConvexShape>();
				shape->setPointCount(3);
				shape->setPoint(0, sf::Vector2f(x1, y1));
				shape->setPoint(1, sf::Vector2f(x2 , y2));
				shape->setPoint(2, sf::Vector2f(x3 , y3));
				HexToDecCodeColor(fillColor, RR, GG, BB);
				shape->setFillColor(sf::Color(RR, GG, BB));
				HexToDecCodeColor(lineColor, RR, GG, BB);
				shape->setOutlineThickness(2);
				shape->setOutlineColor(sf::Color(RR, GG, BB));
				vectors.sfmlShapes.push_back(shape);*/
		}
		else if (nameShape == "circle")
		{
			float x1;
			float y1;
			ss >> x1;
			ss >> y1;
			float radius;
			ss >> radius;
			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			shapesContainer.AddShape(V2f(x1, y1), radius, lineColor, fillColor);
			/*vectors.informationAboutShape.push_back(make_shared<CCircle>(V2f(x1, y1), radius, lineColor, fillColor));
			
			shared_ptr<sf::CircleShape> shape = make_shared<sf::CircleShape>();
			shape->setRadius(radius);
			shape->setPosition(x1-radius, y1 - radius);
			HexToDecCodeColor(fillColor, RR, GG, BB);
			shape->setFillColor(sf::Color(RR, GG, BB));
			HexToDecCodeColor(lineColor, RR, GG, BB);
			shape->setOutlineThickness(2);
			shape->setOutlineColor(sf::Color(RR, GG, BB));
			vectors.sfmlShapes.push_back(shape);*/
		}
		else if (nameShape == "rectangle")
		{
			float x1;
			ss >> x1;
			float y1;
			ss >> y1;
			float wight;
			ss >> wight;
			float height;
			ss >> height;
			string lineColor;
			ss >> lineColor;
			string fillColor;
			ss >> fillColor;
			shapesContainer.AddShape(V2f(x1, y1), wight, height, lineColor, fillColor);
			/*vectors.informationAboutShape.push_back(make_shared<CRectangle>(V2f(x1, y1), wight, height, lineColor, fillColor));
			
			shared_ptr<sf::RectangleShape> shape = make_shared<sf::RectangleShape>();
			shape->setSize(sf::Vector2f(wight, height));
			shape->setPosition(x1, y1);
			HexToDecCodeColor(fillColor, RR, GG, BB);
			shape->setFillColor(sf::Color(RR, GG, BB));
			HexToDecCodeColor(lineColor, RR, GG, BB);
			shape->setOutlineThickness(2);
			shape->setOutlineColor(sf::Color(RR, GG, BB));
			vectors.sfmlShapes.push_back(shape);*///делаем обработку цвета в viewshape
		}
	}

	return shapesContainer;
}

