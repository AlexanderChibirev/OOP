#pragma once
enum MoveDirection {
	MOVE_BACK,
	STAYING,
	MOVE_UP
};

class CCar
{
public:
	CCar();
	~CCar();

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool  SetSpeed(int speed);
	int GetGear() const;
	int GetSpeed() const;
	bool GetEngineState() const;
	MoveDirection GetDirection() const;
	
private:
	bool m_engineState;
	int	m_speed; 
	int m_gearshift;
	MoveDirection m_moveDirection;
};

