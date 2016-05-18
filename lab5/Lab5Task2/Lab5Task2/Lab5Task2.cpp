// Lab5Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>

int main()
{
	//CMyString s("StringWithValueAndLen");
//	string s = "abz";
	//string s1 = "abcd";

	CMyString str("heyCopy");
	CMyString str1(str);
	//auto x = s.GetLength();
	//auto n = s2.GetLength();
	//if(s >= s2)
	//{
	//	cout << "1";
	//}
	//CMyString d("FeEld", 5);
	//CMyString b("F", 1);
	//d += b;
	////auto x  = d.GetStringData();
	///*string str = "FeEld";
	//str = str[7];
	//auto x = str.substr(3,53);
	//x = str.substr(1, 1);
	//x = str.substr(2, 1);*/
    return 0;
}

