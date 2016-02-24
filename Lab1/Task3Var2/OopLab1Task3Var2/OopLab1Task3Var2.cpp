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

double Determ(double (&matrixInt)[sizeOfMatrix][sizeOfMatrix])
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

array<array<double, 3>, 3> GetIdentityMatrix()
{
	std::array<std::array<double, 3>, 3> identityMatrix;
	for (int i = 0; i < sizeOfMatrix; i++)
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			identityMatrix[i][j] = 0.0;
			if (i == j)
				identityMatrix[i][j] = 1.0;
		}
	return identityMatrix;
}
void InverseMatrix(double (&matrixInt)[sizeOfMatrix][sizeOfMatrix])
{
	double resultOfDivision;
	array<array<double, 3>, 3> identityMatrix = GetIdentityMatrix();
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

bool BeginProgramm(const string &nameInputFile)
{
	ifstream fileImput;
	fileImput.seekg(0, std::ios::end);
	int length = fileImput.tellg();
	bool wasError = false;
	fileImput.open(nameInputFile);
	if (!fileImput.is_open())
	{
		cout << "Failed to open input.txt for reading\n";
		wasError = true;
	}
	if (!wasError)
	{
		string check;
		string matrixStr[sizeOfMatrix][sizeOfMatrix];
		double matrixInt[sizeOfMatrix][sizeOfMatrix];
		for (int i = 0; i < sizeOfMatrix; i++)
		{
			for (int j = 0; j < sizeOfMatrix; j++)
			{ 
				fileImput >> matrixStr[i][j];
				if (matrixStr[i][j] == "" && !wasError)
				{
					cout << "Your file empty";
					wasError = true;
				}
				if (matrixStr[i][j] == "0" )
				{
					matrixInt[i][j] = double(atof((matrixStr[i][j]).c_str()));
				}
				else if (atoi((matrixStr[i][j]).c_str()) == 0 && !wasError)
				{
					cout << "File contains an invalid character";
					wasError = true;
				}
				matrixInt[i][j] = double(atof((matrixStr[i][j]).c_str()));
			}
		}
		fileImput >> check;
		if (check != "")
		{
			cout << "Matrix is the wrong size, matrix must be 3x3 size";
			wasError = true;
		}
		if(!wasError)
		{
			if (Determ(matrixInt) != 0)
			{
				InverseMatrix(matrixInt);
				PrintMatrix(matrixInt);
			}
			else
			{
				cout << "The inverse matrix can not be found, since the determinant is equal to zero";
				wasError = true;
			}
		}
	}
	fileImput.close();
	return wasError;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		cout << "Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n' <input.txt> ";
		return 1;
	}
	string nameInputFile = argv[1];
	if (BeginProgramm(nameInputFile))
	{
		return 1;
	}
	return 0;
}