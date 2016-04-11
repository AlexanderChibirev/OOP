// Lab4Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GetInformationAboutShapesFromFile.h"
#include "GetParametrsShapes.h"
#include "WriteResultInOutputFile.h"
#include "GetProcessedData.h"



void PrintHelp()
{
	cout << "Здравстуйте! Пожалуйста пишите данные в точности по примеру, через пробел,\n";
	cout << "Цвет lineColor и fillColor должен задаваться в формате строки вида “#RRGGBB”,где RR, GG и BB – тройки чисел в шестнадцатеричной системе счисления,\nзадающие интенсивность красной, зеленой и синей составляющих\n";
	cout << "Так же учитывается регистр букв !\nПример:\n";
	cout << "Формат записи для точки: point x y\n";
	cout << "Формат записи:\n-для линии: lineSegment x1 y1 x2 y2 lineColor\n";
	cout << "-для круга: circle x1 y1 radius lineColor fillColor\n";
	cout << "-для прямоугольника: rectangle  x1 y1 wight height lineColor fillColor\n";
	cout << "-для треугольника: triangle  x1 y1 x2 y2 x3 y3 lineColor fillColor \n";
	cout << "после ввода данных фигуры жмите enter и вводите данные для седующей фигуры,\nчтобы закончить ввод данных, введите три точки(...)\nЕсли все понятно, можете начинать, удачи!\n>";
}

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
	string dataShapes = GetInformationAboutShapesFromFile(inputFileName, wasError);
	if (wasError)
	{

		cout << "Failed to open input file for reading\n";
		return 1;
	}
	//string dataShapes = GetInformationAboutShapesFromUser();
	vector<shared_ptr<IShape>> informationAboutShape = GetParametrsShapes(dataShapes);
	string result = GetProcessedData(informationAboutShape);
	string outputFileName = argv[2];
	if (!WriteResultInOutputFile(result, outputFileName))
	{

		cout << "Failed to open output file for reading\n";
		return 1;
	}
    return 0;
}

