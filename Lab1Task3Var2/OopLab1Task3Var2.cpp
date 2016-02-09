//// OopLab1Task3Var2.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

const int sizeOfMatrix = 3;

struct DataProgram
{
	string nameImputFile;

	ifstream fileImput;

};

int ErrorExitProgram()
{
	exit(1);
}

void ErrorCheckingAndInitData(int argc, char** argv, DataProgram& dataProgram)
{
	struct stat fileSize;

	if (argc != 2) {
		cout << "Wrong amount of arguments was proposed" << endl;
		ErrorExitProgram();
	}
	dataProgram.nameImputFile = argv[1];

	stat(argv[1], &fileSize);
	if (fileSize.st_size > (2e+9))
	{
		cout << "file size larger than 1.6 GB" << endl;
		ErrorExitProgram();
	}

	dataProgram.fileImput.open(dataProgram.nameImputFile);
	if (!dataProgram.fileImput.is_open())
	{
		cout << "Failed to open " << dataProgram.nameImputFile << " for reading" << endl;
		ErrorExitProgram();
	}
}

double determ(double** matrixInt, int sizeOfMatrix)
{
	int i, j;
	double det = 0;
	double** matr;
	if (sizeOfMatrix == 1)
	{
		det = matrixInt[0][0];
	}
	else if (sizeOfMatrix == 2)
	{
		det = matrixInt[0][0] * matrixInt[1][1] - matrixInt[0][1] * matrixInt[1][0];
	}
	else
	{
		matr = new double*[sizeOfMatrix - 1];
		for (i = 0; i<sizeOfMatrix; ++i)
		{
			for (j = 0; j<sizeOfMatrix - 1; ++j)
			{
				if (j<i)
					matr[j] = matrixInt[j];
				else
					matr[j] = matrixInt[j + 1];
			}
			det += pow((double)-1, (i + j))*determ(matr, sizeOfMatrix - 1)*matrixInt[i][sizeOfMatrix - 1];
		}
		delete[] matr;
	}
	return det;
}

void BeginProgramm(DataProgram& dataProgram)
{
	string outPut;
	string lineStr;
	string matrixStr[sizeOfMatrix][sizeOfMatrix];
	double **matrixInt;
	matrixInt = new double*[sizeOfMatrix];
	for (int i = 0; i<sizeOfMatrix; ++i)
		matrixInt[i] = new double[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			dataProgram.fileImput >> matrixStr[i][j];
			matrixInt[i][j] = atof((matrixStr[i][j]).c_str());
			cout << matrixInt[i][j] << "  ";
		}
		cout << endl;
	}
	if (determ(matrixInt, sizeOfMatrix) > 0)
	{

	}
	else
	{
		cout << "The inverse matrix can not be found, since the determinant is equal to zero" << endl;
		ErrorExitProgram();
	}
	for (int i = 0; i < sizeOfMatrix; ++i)
		delete[] matrixInt[i];
	delete[] matrixInt;
	dataProgram.fileImput.close();
}

int main(int argc, char** argv)
{
	DataProgram dataProgram;
	ErrorCheckingAndInitData(argc, argv, dataProgram);
	BeginProgramm(dataProgram);
	system("pause");
	cout << "test passed successfully" << endl;
	return 0;
}