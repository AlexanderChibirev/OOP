// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetInformationAboutShapesFromFile.h"
#include "GetParametrsShapes.h"
#include "WriteResultInOutputFile.h"
#include "GetProcessedData.h"
#include "Definition.h"


void PrintHelp()
{
	cout << "�����������! ���������� ������ ������ � �������� �� �������, ����� ������,\n";
	cout << "���� lineColor � fillColor ������ ���������� � ������� ������ ���� �#RRGGBB�,��� RR, GG � BB � ������ ����� � ����������������� ������� ���������,\n�������� ������������� �������, ������� � ����� ������������\n";
	cout << "��� �� ����������� ������� ���� !\n������:\n";
	cout << "������ ������ ��� �����: point x y\n";
	cout << "������ ������:\n-��� �����: lineSegment x1 y1 x2 y2 lineColor\n";
	cout << "-��� �����: circle x1 y1 radius lineColor fillColor\n";
	cout << "-��� ��������������: rectangle  x1 y1 wight height lineColor fillColor\n";
	cout << "-��� ������������: triangle  x1 y1 x2 y2 x3 y3 lineColor fillColor \n";
	cout << "����� ����� ������ ������ ����� enter � ������� ������ ��� �������� ������,\n����� ��������� ���� ������, ������� ��� �����(...)\n���� ��� �������, ������ ��������, �����!\n>";
}
//
//std::stringstream ss;
//ss << std::hex << "ff";
//ss >> x;
//
//std::cout << x << std::endl;

string GetInformationAboutShapesFromUser()
{
	PrintHelp();
	string lineStr;
	string result;
	while (getline(cin, lineStr) )
	{
		cout << ">";
		if (lineStr == "...") 
		{
			break;
		}
		result += lineStr += "\n";
	}
	return result;
}

//vector<shared_ptr<sf::Shape>> GetDrawing(const vector<shared_ptr<IShape>> &informationAboutShape, const string &dataShapes)
//{
//	vector<shared_ptr<sf::Shape>> sfmlShapes;
//	
//	
//	for (auto &it : informationAboutShape)
//	{
//		if (it->GetNameShape() == "circle")
//		{
//			shared_ptr<sf::CircleShape> shape = make_shared<sf::CircleShape>();
//			//shape->setRadius(it->);
//			sfmlShapes.push_back(move(shape));
//		}
//	}
//}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//if (argc != 3)
	//{
	//	cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file>'";
	//	return 1;
	//}

	//string inputFileName = argv[1];
	//bool wasError = false;
	//string dataShapes = GetInformationAboutShapesFromFile(inputFileName, wasError);
	//if (wasError)
	//{

	//	cout << "Failed to open input file for reading\n";
	//	return 1;
	//}
	string dataShapes = GetInformationAboutShapesFromUser();
	InfoAboutShapes informationAboutShape = GetParametrsShapes(dataShapes);
	string resultForWriteInFile = GetProcessedData(informationAboutShape.informationAboutShape);
	string outputFileName = argv[2];
	if (!WriteResultInOutputFile(resultForWriteInFile, outputFileName))
	{

		cout << "Failed to open output file for reading\n";
		return 1;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	sf::View view;
	sf::RenderWindow window(sf::VideoMode(700, 600), "SFML Shape");
	view.reset(sf::FloatRect(0, 0, 700, 600));
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Int64 time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 200;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		if (localPosition.x < 20) { view.move(float(-0.2*time), 0); }
		if (size_t(localPosition.x) > window.getSize().x - 20) { view.move(float(0.2*time), 0); }
		if (size_t(localPosition.y) > window.getSize().y - 20) { view.move(0, float(0.2*time)); }
		if (localPosition.y < 20) { view.move(0, float(-0.2*time)); }

		window.setView(view);
		window.clear(sf::Color::White);
		for (auto &it : informationAboutShape.sfmlShapes)
		{
			window.draw(*it);
		}
		window.display();
	}
	//////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}

