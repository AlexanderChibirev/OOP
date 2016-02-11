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


void ErrorExitProgram(string const &textError, bool &error)
{
	cout << textError << endl;
	error = true;
}


float Determ(float** matrixInt, int sizeOfMatrix)
{
	float det = 0;
	float result1;
	float result2;
	float result3;
	result1 = matrixInt[0][0] * ((matrixInt[1][1] * matrixInt[2][2]) - (matrixInt[1][2] * matrixInt[2][1]));
	result2 = matrixInt[0][1] * ((matrixInt[1][0] * matrixInt[2][2]) - (matrixInt[1][2] * matrixInt[2][0]));
	result3 = matrixInt[0][2] * ((matrixInt[1][0] * matrixInt[2][1]) - (matrixInt[1][1] * matrixInt[2][0]));
	det = result1 - result2 + result3;
	cout << det;
	return det;
}

void InverseMatrix(float** matrixInt, int sizeOfMatrix)
{
	float resultOfDivision;

	float **identityMatrix = new float *[sizeOfMatrix];

	for (int i = 0; i < sizeOfMatrix; i++)
		identityMatrix[i] = new float[sizeOfMatrix];
	//делаем еденичную матрицу////////////////////
	for (int i = 0; i < sizeOfMatrix; i++)
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			identityMatrix[i][j] = 0.0;
			if (i == j)
				identityMatrix[i][j] = 1.0;
		}
	/////////////////////////////////////////////
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

void BeginProgramm(const string &nameImputFile, bool &error)
{
	ifstream fileImput;

	fileImput.open(nameImputFile);
	if (!fileImput.is_open())
	{
		ErrorExitProgram("Failed to open input.txt for reading\n", error);
	}
	if (!error)
	{
		string outPut;
		string lineStr;
		string matrixStr[sizeOfMatrix][sizeOfMatrix];
		float **matrixInt;
		matrixInt = new float*[sizeOfMatrix];
		for (int i = 0; i<sizeOfMatrix; ++i)
		{
			matrixInt[i] = new float[sizeOfMatrix];
		}
		for (int i = 0; i < sizeOfMatrix; i++)
		{
			for (int j = 0; j < sizeOfMatrix; j++)
			{
				fileImput >> matrixStr[i][j];
				if (matrixStr[i][j] == ""  && !error)
				{
					ErrorExitProgram("Your file empty", error);
				}
				matrixInt[i][j] = float(atof((matrixStr[i][j]).c_str()));
			}
		}
		if(!error)
		{
			if (Determ(matrixInt, sizeOfMatrix) == 0)
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
				ErrorExitProgram("The inverse matrix can not be found, since the determinant is equal to zero", error);
			}
		}
		for (int i = 0; i < sizeOfMatrix; ++i)
			delete[] matrixInt[i];
		delete[] matrixInt;
	}
	fileImput.close();
}

int main(int argc, char** argv)
{
	bool error = false;
	string nameImputFile = argv[1];
	if (argc != 2)
	{
		ErrorExitProgram("Wrong amount of arguments was proposed\nEnter a correct arguments amount please, for example:\n'OopLab1Task3Var7.exe <input.txt> ", error);
		return 1;
	}
	if (!error) 
	{
		BeginProgramm(nameImputFile, error);
	}
	if (error)
	{
		return 1;
	}
	return 0;
}