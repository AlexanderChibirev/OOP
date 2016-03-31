#include "stdafx.h"
#include "Car.h"


CCar::CCar()
	:m_engineState(false)
	, m_gearshift(0)
	, m_moveDirection(STAYING)
	, m_speed(0)
{

}


CCar::~CCar()
{
}

int CCar::GetGear() const
{
	return m_gearshift;
}

int  CCar::GetSpeed() const
{
	return m_speed;
}
MoveDirection CCar::GetDirection() const
{
	return m_moveDirection;
}

bool  CCar::GetEngineState() const
{
	return m_engineState;
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
	if ((m_engineState) && (m_gearshift == 0) && (m_moveDirection == STAYING) && (m_speed == 0))
	{
		m_engineState = false;
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
	bool wasChange = false;
	if (m_engineState)
	{
		if (gear == m_gearshift)
		{
			wasChange = true;
		}
		else if ((gear == -1) && ((m_gearshift == 0) || (m_gearshift == 1 && m_speed == 0))|| (gear == 0) && m_gearshift == 0)
		{
			m_gearshift = gear;
			m_moveDirection = STAYING;
			wasChange = true;
		}
		else if ((gear == 0) && m_gearshift < 0)
		{
			m_moveDirection = MOVE_BACK;
			m_gearshift = gear;
			wasChange = true;
		}
		else if ((gear == 1) && (m_speed > 0 && m_speed <= 30) && m_gearshift != -1 ||
			((gear == 1) && (m_speed == 0)) ||
			((gear == 2) && (m_speed >= 20 && m_speed <= 50) && m_gearshift != -1)||
			(gear == 3) && (m_speed >= 30 && m_speed <= 60)||
			(gear == 4) && (m_speed >= 40 && m_speed <= 90)||
			(gear == 5) && (m_speed >= 50 && m_speed <= 150)|| 
			((gear == 0) && m_gearshift > 0))
		{
			m_moveDirection = MOVE_UP;
			m_gearshift = gear;
			wasChange = true;
		}
	}
	return wasChange;
}

bool  CCar::SetSpeed(int speed)
{
	bool wasChange = false;
	if (m_engineState)
	{
		if (speed <= 0)
		{
			m_moveDirection = STAYING;
			m_speed = 0;
			wasChange = true;
		}
		else if(speed == m_speed )
		{
			wasChange = true;
		}
		else if(m_gearshift == 0 && m_moveDirection == STAYING)
		{
			m_speed = speed;
			wasChange = true;
		}
		else if ((m_gearshift == 0) && (speed > 0 && speed <= 150) && m_moveDirection == STAYING)
		{
			m_speed = speed;
			m_moveDirection = STAYING;
			wasChange = true;
		}
		else if ((m_gearshift == -1) && (speed > 0 && speed <= 20))
		{
			m_speed = speed;
			m_moveDirection = MOVE_BACK;
			wasChange = true;
		}
		
		else if ((m_gearshift == 1) && (speed > 0 && speed <= 30)||
			((m_gearshift == 2) && (speed >= 20 && speed <= 50))||
			((m_gearshift == 3) && (speed >= 30 && speed <= 60))||
			((m_gearshift == 4) && (speed >= 40 && speed <= 90))||
			((m_gearshift == 5) && (speed >= 50 && speed <= 150)))
		{
			m_moveDirection = MOVE_UP;
			m_speed = speed;
			wasChange = true;
		}
	}
	return wasChange;
}
