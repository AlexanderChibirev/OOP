// Lab6Task1Var7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HttpUrl.h"

using namespace std;

int main()
{
	string url = "https://github.com//OOP/";
	//CHttpUrl urls(url);
	CHttpUrl  urls("http", "github.com", 80, "OOP");
	return 0;
}

