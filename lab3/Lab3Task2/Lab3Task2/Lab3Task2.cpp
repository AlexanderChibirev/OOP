// Lab3Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include "Calculator.h"
#include <map>
#include <algorithm>
#include "WorkWithUI.h"
#include <string>
#include <set>
#include <map>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;



int main()
{
	CCalculator calculator;
	CWorkWithUI workWithUI(calculator, cin, cout);
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!workWithUI.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
    return 0;
}

