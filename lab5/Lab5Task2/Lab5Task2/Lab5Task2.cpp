// Lab5Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <vector>

int main()
{
	CMyString myString("Clear", 5);
	myString.Clear();
	string d;
	d.clear();
	auto x = d[0];
	
	
	//CMyString str1(move(myString.GetStringData())); // �����������, ���������������� ������ ������� ������. � ����������� ������� ��������
	
	//CMyString str("x");
	//str.Clear();
	//str[0] = 'x';
	//CMyString str("asd");
	//size_t i = str.GetLength() - 1;
	//for (CMyString::iterator it = str.rbegin(); it != str.rend(); ++it)
	//{
	//	auto x = str[i];
	//	auto y = *it;
	//	i--;
	//}
//	vector<char> str2 = {'1'};
//	auto y = str2[0];
	//str2.clear();
	//y = str2[0];
	//str2[0] = 'y';
	//str.clear();
	//str[0] = 'x';
//	CMyString myString("S");
//	myString.Clear();
//	auto x = myString[0];
	//CMyString ss(myString.GetStringData());
//	myString = myString + myString;
    return 0;
}

