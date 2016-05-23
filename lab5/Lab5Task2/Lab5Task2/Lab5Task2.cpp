// Lab5Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <vector>

int main()
{
	//CMyString str("x");
	//str.Clear();
	//str[0] = 'x';
	
	string str;
	auto x = str[0];
	str[0] = 'x';

	vector<char> str2 = {'1'};
	auto y = str2[0];
	str2.clear();
	y = str2[0];
	str2[0] = 'y';
	//str.clear();
	//str[0] = 'x';
//	CMyString myString("S");
//	myString.Clear();
//	auto x = myString[0];
	//CMyString ss(myString.GetStringData());
//	myString = myString + myString;
    return 0;
}

