// Lab3Task1Var2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include <map>
#include <algorithm>

using namespace std;

inline constexpr uint32_t fnv1a(const char* str, uint32_t hash = 2166136261UL) 
{
	return *str ? fnv1a(str + 1, (hash ^ *str) * 16777619ULL) : hash;
}

int GetNum(string const &nameOperation, string &inputStr)
{
	inputStr.erase(inputStr.find(nameOperation), nameOperation.length()+1);
	inputStr.erase(inputStr.find(">"), 1);
	inputStr.erase(inputStr.find("<"), 1);
	int numGear = atoi(inputStr.c_str());
	return numGear;
}

void WorkWithUser()
{
	CCar car;
	string inputStr;
	while ((cout << ">") && getline(cin, inputStr))
	{
		std::string::size_type sz;
		transform(inputStr.begin(), inputStr.end(), inputStr.begin(), ::tolower);
		if ( inputStr.find("setgear <") != std::string::npos)
		{
			if (!car.SetGear(GetNum("setgear", inputStr)))
			{
				cout << "You can not do gearshift\n";
			}
		}
		else if (inputStr.find("setspeed <") != std::string::npos)
		{
			if (!car.SetSpeed(GetNum("setspeed", inputStr)))
			{
				cout << "You can not change the speed\n";
			}
		}
		else
		{
			switch (fnv1a(inputStr.c_str()))
			{
				case fnv1a("info"): 
					//cout << car.GetInfo();
					//	info +=  "Engine car state " + GetEngineState() + "\n";
					//	info += "Car moving in towards " + GetDirection() + "\n";
					//	info += "Car have speed " + std::to_string(m_speed) + " km/s" + "\n";
					//	info += "Car have gearshift " + std::to_string(m_gearshift) + "\n";
					//	return info;
					break;
				case fnv1a("engineon"): 
					if (!car.TurnOnEngine())
					{
						cout << "The car's engine can not be started, becouse was already included\n";
					}
					break;
				case fnv1a("engineoff"):
					if (!car.TurnOffEngine())
					{
						cout << "The car's engine can not be off\n";
					}
					break;
				default:
					cout << "no command\n";
					break;
			};
		}
	}
}

int main()
{
	WorkWithUser();
    return 0;
}

