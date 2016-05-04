// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetInformationAboutShapesFromFile.h"
#include "CreateShape.h"
#include "WriteResultInOutputFile.h"
#include "GetProcessedData.h"

void PrintHelp()
{
	cout << "�����������! ���������� ������ ������ � �������� �� �������, ����� ������,\n";
	cout << "���� lineColor � fillColor ������ ���������� � ������� ������ ���� �#RRGGBB�,��� RR, GG � BB � ������ ����� � ����������������� ������� ���������,\n�������� ������������� �������, ������� � ����� ������������\n";
	cout << "��� �� ����������� ������� ���� !\n������:\n";
	cout << "������ ������:\n-��� �����: point x y\n";
	cout << "-��� �����: lineSegment x1 y1 x2 y2 lineColor\n";
	cout << "-��� �����: circle x1 y1 radius lineColor fillColor\n";
	cout << "-��� ��������������: rectangle  x1 y1 wight height lineColor fillColor\n";
	cout << "-��� ������������: triangle  x1 y1 x2 y2 x3 y3 lineColor fillColor \n";
	cout << "����� ����� ������ ������ ����� enter � ������� ������ ��� �������� ������,\n����� ��������� ���� ������, ������� ��� �����(...)\n���� ��� �������, ������ ��������, �����!\n>";
}

vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> GetInformationAboutShapesFromUser()
{
	PrintHelp();
	string lineStr;
	string result;
	vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> shapes;
	while (getline(cin, lineStr) )
	{
		cout << ">";
		if (lineStr == "...") 
		{
			break;
		}
		auto shape = CreateShape(lineStr);
		shapes.push_back(move(shape));
	}
	return shapes;
}

void DrawShapes(const vector<pair<shared_ptr<IShape>, shared_ptr<IShapeView>>> & informationAboutShape)
{
	sf::View view;
	sf::RenderWindow window(sf::VideoMode(800, 700), "SFML Shape");
	view.reset(sf::FloatRect(0, 0, 800, 700));
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
		for (auto &it : informationAboutShape)
		{
			window.draw(*it.second);
		}
		window.display();
	}
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	if (argc != 3)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input file> <output file>'";
		return 1;
	}
	string inputFileName = argv[1];
	bool wasError = false;
	auto shapes = GetInformationAboutShapesFromFile(inputFileName, wasError);
	if (wasError)
	{
		cout << "Failed to open input file for reading\n";
		return 1;
	}
	//auto shapes = GetInformationAboutShapesFromUser();
	string resultForWriteInFile = GetSortedData(shapes);
	string outputFileName = argv[2];
	if (!WriteResultInOutputFile(resultForWriteInFile, outputFileName))
	{
		cout << "Failed to open output file for reading\n";
		return 1;
	}
	DrawShapes(shapes);
	return 0;
}

