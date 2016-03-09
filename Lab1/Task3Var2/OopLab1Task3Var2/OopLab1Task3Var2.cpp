//// OopLab1Task3Var2.cpp: определяет точку входа для консольного приложения.
////
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>

using namespace std;

const int sizeOfMatrix = 3;

typedef array<array<double, 3>, 3> Matrix;

void PrintMatrix(double (&matrixInt)[sizeOfMatrix][sizeOfMatrix])
{
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			if (j!=2)
			{
				cout << setprecision(3) << matrixInt[i][j] << " ";
			}
			else
			{
				cout << setprecision(3) << matrixInt[i][j];
			}
		}
		if (i != 2)
		{
		cout << endl;
		}
	}
}

double CalculateDeterminant(double (&matrixInt)[sizeOfMatrix][sizeOfMatrix])
{
	double det = 0;
	double result1;
	double result2;
	double result3;
	result1 = matrixInt[0][0] * ((matrixInt[1][1] * matrixInt[2][2]) - (matrixInt[1][2] * matrixInt[2][1]));
	result2 = matrixInt[0][1] * ((matrixInt[1][0] * matrixInt[2][2]) - (matrixInt[1][2] * matrixInt[2][0]));
	result3 = matrixInt[0][2] * ((matrixInt[1][0] * matrixInt[2][1]) - (matrixInt[1][1] * matrixInt[2][0]));
	det = result1 - result2 + result3;
	return det;
}

Matrix GetIdentityMatrix()
{
	Matrix identityMatrix;
	for (int i = 0; i < sizeOfMatrix; ++i)
	{
		for (int j = 0; j < sizeOfMatrix; ++j)
		{
			identityMatrix[i][j] = 0.0;
			if (i == j)
				identityMatrix[i][j] = 1.0;
		}
	}
	return identityMatrix;
}
void InverseMatrix(double (&matrixInt)[sizeOfMatrix][sizeOfMatrix])
{
	double resultOfDivision;
	Matrix identityMatrix = GetIdentityMatrix();
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
	//result | 1 0 0| = |1, -2 ,3 |;
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			matrixInt[i][j] = identityMatrix[i][j];
		}
	}
}

enum ERROR_CODE { ALL_IS_OK ,CANT_OPEN_FILE, EMPTY_FILE, INVALID_CHARACTER, WRONG_SIZE, MATRIX_CAN_NOT_BE_FOUND};

ERROR_CODE ProcessMatrix(const string &nameInputFile)
{
	ifstream inputFile;
	inputFile.seekg(0, std::ios::end);
	inputFile.open(nameInputFile);
	if (!inputFile.is_open())
	{
		return ERROR_CODE::CANT_OPEN_FILE;
	}
	string check;
	string matrixStr[sizeOfMatrix][sizeOfMatrix];
	double matrixInt[sizeOfMatrix][sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{ 
			inputFile >> matrixStr[i][j];
			if (matrixStr[i][j] == "")
			{
				return ERROR_CODE::EMPTY_FILE;
			}
			if (matrixStr[i][j] == "0" )
			{
				matrixInt[i][j] = double(atof((matrixStr[i][j]).c_str()));
			}
			else if (atoi((matrixStr[i][j]).c_str()) == 0)
			{
				return ERROR_CODE::INVALID_CHARACTER;
			}
			matrixInt[i][j] = double(atof((matrixStr[i][j]).c_str()));
		}
	}
	inputFile >> check;
	if (check != "")
	{
		return ERROR_CODE::WRONG_SIZE;
	}
	if (CalculateDeterminant(matrixInt) != 0)
	{
		InverseMatrix(matrixInt);
		PrintMatrix(matrixInt);
	}
	else
	{
		return ERROR_CODE::MATRIX_CAN_NOT_BE_FOUND;
	}

inputFile.close();
return ERROR_CODE::ALL_IS_OK;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input.txt> ";
		return 1;
	}
	string nameInputFile = argv[1];
	switch (ProcessMatrix(nameInputFile))
	{
		case 0:
			return 0;
		case 1:
			cout << "Failed to open input.txt for reading\n";
			return 1;
		case 2:
			cout << "Your file empty";
			return 1;
		case 3:
			cout << "File contains an invalid character";
			return 1;
		case 4:
			cout << "Matrix is the wrong size, matrix must be 3x3 size";
			return 1;
		case 5:
			cout << "The inverse matrix can not be found, since the determinant is equal to zero";
			return 1;
	}

}