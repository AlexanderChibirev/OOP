// Lab3Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include <map>
#include <algorithm>
#include "WorkWithUI.h"
using namespace std;

int main()
{
	CCar car;
	CWorkWithUI remoteControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
    return 0;
}

