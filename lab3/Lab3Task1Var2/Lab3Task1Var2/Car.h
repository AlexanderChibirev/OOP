#pragma once
class CCar
{
public:
	CCar();
	~CCar();

	std::string GetInfo() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool  SetSpeed(int speed);
	
private:
	bool m_engineState;
	int	m_speed; 
	int m_gearshift ; //��������
	int m_moveDirection; //����������� ��������

	std::string GetDirection() const;
	std::string GetEngineState() const;
};

