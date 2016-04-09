#include "stdafx.h"
#include "WorkWithUI.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;

CWorkWithUI::CWorkWithUI(CCar & car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "EngineOn", bind(&CWorkWithUI::TurnOnEngine, this, _1) },
		{ "EngineOff", bind(&CWorkWithUI::TurnOffEngine, this, _1) },
		{ "SetGear", bind(&CWorkWithUI::SetGear, this, _1) },
		{ "SetSpeed", bind(&CWorkWithUI::SetSpeed, this, _1) },
		{ "Info", bind(&CWorkWithUI::Info, this, _1) },
})
{
}

bool CWorkWithUI::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}
	return false;
}

bool CWorkWithUI::TurnOnEngine(std::istream & /*args*/)
{
	m_car.TurnOnEngine();
	m_output << "Car engine is turned on\n";
	return true;
}

bool CWorkWithUI::TurnOffEngine(std::istream & /*args*/)
{
	m_car.TurnOffEngine();
	m_output << "Car engine is turned off\n";
	return true;
}
bool CWorkWithUI::Info(std::istream & /*args*/)
{
	cout << "Engine car state " + to_string(m_car.GetEngineState()) + "\n";
	switch (m_car.GetDirection())
	{
	case MOVE_UP:
		cout << "Car moving in towards move up\n";
		break;
	case STAYING:
		cout << "Car moving in towards stying\n";
		break;
	case MOVE_BACK:
		cout << "Car moving in towards move back\n";
		break;
	}
	cout << "Car have speed " + to_string(m_car.GetSpeed()) + " km/s" + "\n";
	cout << "Car have gearshift " + to_string(m_car.GetGear()) + "\n";
	return true;
}

bool  CWorkWithUI::SetGear(std::istream & args)
{
	string line;
	getline(args, line);
	if(!m_car.SetGear(stoi(line)))
	{
		cout << "You can not do gearshift\n";
		return false;
	}
	return true;
}

bool  CWorkWithUI::SetSpeed(std::istream & args)
{
	string line;
	getline(args, line);
	if(!m_car.SetSpeed(stoi(line)))
	{
		cout << "You can not change the speed\n";
		return false;
	}
	return true;
}

CWorkWithUI::~CWorkWithUI()
{
}
