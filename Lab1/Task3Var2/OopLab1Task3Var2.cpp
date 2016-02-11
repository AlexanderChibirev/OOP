//// OopLab1Task3Var2.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

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
	if (fileSize.st_size > 0 && fileSize.st_size < 2147483648)
	{
		cout << "file size larger than 2 GB" << endl;
		ErrorExitProgram();
	}

	dataProgram.fileImput.open(dataProgram.nameImputFile);
	if (!dataProgram.fileImput.is_open())
	{
		cout << "Failed to open " << dataProgram.nameImputFile << " for reading" << endl;
		ErrorExitProgram();
	}
}

float Determ(float** matrixInt, int sizeOfMatrix)
{
	int i, j;
	float det = 0;
	float** matr;
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
		matr = new float*[sizeOfMatrix - 1];
		for (i = 0; i<sizeOfMatrix; ++i)
		{
			for (j = 0; j<sizeOfMatrix - 1; ++j)
			{
				if (j<i)
					matr[j] = matrixInt[j];
				else
					matr[j] = matrixInt[j + 1];
			}
			det += pow((float)-1, (i + j))*Determ(matr, sizeOfMatrix - 1)*matrixInt[i][sizeOfMatrix - 1];
		}
		delete[] matr;
	}
	return det;
}

void InverseMatrix(float** matrixInt, int sizeOfMatrix)
{
	float resultOfDivision;

	float **identityMatrix = new float *[sizeOfMatrix];

	for (int i = 0; i < sizeOfMatrix; i++)
		identityMatrix[i] = new float[sizeOfMatrix];

	for (int i = 0; i < sizeOfMatrix; i++)
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			identityMatrix[i][j] = 0.0;

			if (i == j)
				identityMatrix[i][j] = 1.0;
		}

	for (int k = 0; k < sizeOfMatrix; k++)
	{
		resultOfDivision = matrixInt[k][k];

		for (int j = 0; j < sizeOfMatrix; j++)
		{
			matrixInt[k][j] /= resultOfDivision;
			identityMatrix[k][j] /= resultOfDivision;
		}

		for (int i = k + 1; i < sizeOfMatrix; i++)
		{
			resultOfDivision = matrixInt[i][k];

			for (int j = 0; j < sizeOfMatrix; j++)
			{
				matrixInt[i][j] -= matrixInt[k][j] * resultOfDivision;
				identityMatrix[i][j] -= identityMatrix[k][j] * resultOfDivision;
			}
		}
	}

	for (int k = sizeOfMatrix - 1; k > 0; k--)
	{
		for (int i = k - 1; i >= 0; i--)
		{
			resultOfDivision = matrixInt[i][k];

			for (int j = 0; j < sizeOfMatrix; j++)
			{
				matrixInt[i][j] -= matrixInt[k][j] * resultOfDivision;
				identityMatrix[i][j] -= identityMatrix[k][j] * resultOfDivision;
			}
		}
	}

	for (int i = 0; i < sizeOfMatrix; i++)
		for (int j = 0; j < sizeOfMatrix; j++)
			matrixInt[i][j] = identityMatrix[i][j];

	for (int i = 0; i < sizeOfMatrix; i++)
		delete[] identityMatrix[i];

	delete[] identityMatrix;
}

void BeginProgramm(DataProgram& dataProgram)
{
	string outPut;
	string lineStr;
	string matrixStr[sizeOfMatrix][sizeOfMatrix];
	float **matrixInt;
	matrixInt = new float*[sizeOfMatrix];
	for (int i = 0; i<sizeOfMatrix; ++i)
		matrixInt[i] = new float[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			dataProgram.fileImput >> matrixStr[i][j];
			if (matrixStr[i][j] == "" ) {
				cout << "Your file empty" << endl;
				ErrorExitProgram();
			}
			matrixInt[i][j] = float(atof((matrixStr[i][j]).c_str()));
			//cout << matrixInt[i][j] << "  ";
		}
		//cout << endl;
	}
	if (Determ(matrixInt, sizeOfMatrix) > 0)
	{
		InverseMatrix(matrixInt, sizeOfMatrix);
		for (int i = 0; i < sizeOfMatrix; i++)
		{
			for (int j = 0; j < sizeOfMatrix; j++)
			{
				cout << setprecision(3) << matrixInt[i][j] << "  ";
			}
			cout << endl;
		}
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
	return 0;
}