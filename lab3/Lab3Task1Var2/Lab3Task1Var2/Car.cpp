#include "stdafx.h"
#include "Car.h"


CCar::CCar()
	:m_engineState(false)
	,m_gearshift(0)
	,m_moveDirection(0)
	,m_speed(0)
{

}


CCar::~CCar()
{
}


bool CCar::TurnOnEngine()
{
	if (!m_engineState)
	{
		m_engineState = true;
		return true;
	}
	else
	{
		return false;
	}
}

bool CCar::TurnOffEngine()
{
	if ( (m_engineState) && (m_gearshift == 0) && (m_moveDirection == 0) && (m_speed == 0 ))
	{
		m_engineState = false;
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
	bool wasChange = false;
	if(m_engineState)
	{
		if (gear == m_gearshift)
		{
			wasChange = true;
		}
		else if ( (gear == -1) && ( (m_gearshift == 0) || (m_gearshift == 1 && m_speed == 0 ) ) )
		{
			m_gearshift = gear;
			m_moveDirection = 0;
			wasChange = true;
		}
		else if ((gear == 0) && m_gearshift > 0)
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 0) && m_gearshift < 0)
		{
			m_moveDirection = -1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 0) && m_gearshift == 0)
		{
			m_moveDirection = 0;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 1) && (m_speed > 0 && m_speed <= 30) && m_gearshift != -1)
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ( (gear == 1) && m_speed == 0)
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 2) && (m_speed >= 20 && m_speed <= 50) && m_gearshift != -1)
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 3) && (m_speed >= 30 && m_speed <= 60))
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 4) && (m_speed >= 40 && m_speed <= 90))
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 5) && (m_speed >= 50 && m_speed <= 150))
		{
			m_moveDirection = 1;
			m_gearshift = gear;
			wasChange = true;
		}
	}
	return wasChange;
}

bool  CCar::SetSpeed(int speed)
{
	bool wasChange = false;
	if(m_engineState)
	{
		if (speed <= 0)
		{
			m_moveDirection = 0;
			m_speed = 0;
			wasChange = true;
		}
		else if ((m_gearshift == -1) && (speed > 0 && speed <= 20))
		{
			m_speed = speed;
			m_moveDirection = -1;
			wasChange = true;
		}
		else if ((m_gearshift == 0) && (speed > 0 && speed <= 150))
		{
			m_speed = speed;
			m_moveDirection = 0;
			wasChange = true;
		}
		else if ((m_gearshift == 1) && (speed > 0 && speed <= 30))
		{
			m_moveDirection = 1;
			m_speed = speed;
			wasChange = true;
		}
		else if ((m_gearshift == 2) && (speed >= 20 && speed <= 50))
		{
			m_moveDirection = 1;
			m_speed = speed;
			wasChange = true;
		}
		else if ((m_gearshift == 3) && (speed >= 30 && speed <= 60))
		{
			m_moveDirection = 1;
			m_speed = speed;
			wasChange = true;
		}
		else if ((m_gearshift == 4) && (speed >= 40 && speed <= 90))
		{
			m_moveDirection = 1;
			m_speed = speed;
			wasChange = true;
		}
		else if ((m_gearshift == 5) && (speed >= 50 && speed <= 150))
		{
			m_moveDirection = 1;
			m_speed = speed;
			wasChange = true;
		}
	}
	return wasChange;
}

std::string CCar::GetDirection() const
{
	std::string directionCar;
	switch(m_moveDirection)
	{
		case -1:
			directionCar = "Move Back";
			break;
		case 0:
			directionCar = "staying";
			break;
		case 1:
			directionCar = "Move Up";
			break;
	}
	return directionCar;
}

std::string CCar::GetEngineState() const
{
	std::string engineState = "off";
	if (m_engineState)
	{
		engineState = "on";
	}
	return engineState;
}

std::string CCar::GetInfo() const
{
	std::string info;
	info +=  "Engine car state " + GetEngineState() + "\n";
	info += "Car moving in towards " + GetDirection() + "\n";
	info += "Car have speed " + std::to_string(m_speed) + " km/s" + "\n";
	info += "Car have gearshift " + std::to_string(m_gearshift) + "\n";
	return info;
}
