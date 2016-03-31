#include "stdafx.h"
#include "..\\Lab3Task1Var2\Car.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE (Car_class)


	BOOST_AUTO_TEST_CASE(BeginState)
	{
		CCar beginStateCar;//�������� ��������� ���������
		BOOST_CHECK(beginStateCar.GetEngineState() == false);
		BOOST_CHECK_EQUAL(beginStateCar.GetGear(), 0);
		BOOST_CHECK_EQUAL(beginStateCar.GetDirection(), STAYING);
		BOOST_CHECK_EQUAL(beginStateCar.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCantBeSetingSpeedThenEngineOff)
	{
		CCar validSetParametrsCar;//�������� �� ����� ���� ��������, ����� ��������� ��������
		BOOST_CHECK(validSetParametrsCar.SetSpeed(10) == false);
		BOOST_CHECK_EQUAL(validSetParametrsCar.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCantBeSetingGearThenEngineOff)
	{
		CCar validSetParametrsCar;;//�������� �� ����� ���� ��������, ����� ��������� ��������
		BOOST_CHECK(validSetParametrsCar.SetGear(1) == false);
		BOOST_CHECK_EQUAL(validSetParametrsCar.GetGear(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCanBeEngineOnThenEngineOff) 
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.GetEngineState() == false);//���������� ��������
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
		BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//����� �������

	}
	BOOST_AUTO_TEST_CASE(TestEngineOffThenEngineOff)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.GetEngineState() == false);//���������� ��������
		BOOST_CHECK(validEngineOnCar.TurnOffEngine() == false);//�� ����������� ��� ��� ��� ��������
	}
	BOOST_AUTO_TEST_SUITE(TestMiniSwichForZeroGearBackGearFirtGear)
		BOOST_AUTO_TEST_CASE(Switching)
		{
			CCar SetParametrsCar;
			SetParametrsCar.TurnOnEngine();
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(),0);//�������� �� ������� ��������
			BOOST_CHECK_EQUAL(SetParametrsCar.GetSpeed(), 0);//�������� �� ������� ��������
			BOOST_CHECK(SetParametrsCar.SetGear(-1));//����� ������������ ��� ������� ��������
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(), -1);//�������� ��� �� ���
			SetParametrsCar.SetGear(0);
			SetParametrsCar.SetSpeed(10);
			BOOST_CHECK(SetParametrsCar.SetGear(-1));//������ ������������ ��� �������� ���� ����
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(), -1);//�������� ��� �� ���
		}
	BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(ActionsEngineOn)
			BOOST_AUTO_TEST_CASE(TestCanBeSetingSpeedThenEngineOn)
			{
				CCar successSetParametrsCar;
				BOOST_CHECK(successSetParametrsCar.TurnOnEngine() == true);
				BOOST_CHECK(successSetParametrsCar.SetSpeed(10) == true);
				BOOST_CHECK_EQUAL(successSetParametrsCar.GetSpeed(), 10);
			};
			BOOST_AUTO_TEST_CASE(TestCanBeSetingFirstGearThenEngineOn)
			{
				CCar successSetParametrsCar;
				BOOST_CHECK(successSetParametrsCar.TurnOnEngine() == true);
				BOOST_CHECK(successSetParametrsCar.SetGear(1) == true);
				BOOST_CHECK_EQUAL(successSetParametrsCar.GetGear(), 1);
				
			};
			BOOST_AUTO_TEST_CASE(TestCanBeSetingBackGearThenEngineOn)
			{
				CCar successSetParametrsCar;
				BOOST_CHECK(successSetParametrsCar.TurnOnEngine() == true);
				BOOST_CHECK(successSetParametrsCar.SetGear(-1) == true);
				BOOST_CHECK_EQUAL(successSetParametrsCar.GetGear(), -1);
				
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOffThen1Gear)
			{
				CCar validSetParametrsCar;
				validSetParametrsCar.TurnOnEngine();
				validSetParametrsCar.SetGear(1);
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == false);//������ ��������� ��������� �� ������ ��������
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == true);//��������, ��� ��������� ��� �������
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOffThenNeutralGear)
			{
				CCar validSetParametrsCar;
				validSetParametrsCar.TurnOnEngine();			
				validSetParametrsCar.SetGear(0);
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == true);//����� ��������� �� ����������� ��������
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == false); //�������� state
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOffThenReversGear)
			{
				CCar validSetParametrsCar;
				validSetParametrsCar.TurnOnEngine();
				validSetParametrsCar.SetGear(-1);
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == false);//������ ��������� ��������� �� ������ ��������
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == true); //�������� state
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOnThenEngineOn)
			{
				CCar validEngineOnCar;
				BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
				BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//��������, ��� ���������
				BOOST_CHECK(validEngineOnCar.TurnOnEngine() == false);
				BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//��������, ��� ��� ��� �������
			}
		BOOST_AUTO_TEST_SUITE_END()
			BOOST_AUTO_TEST_SUITE(TestForChangeDirection)
				BOOST_AUTO_TEST_CASE(TestDirectionsInfo)
				{
					CCar directionsCar;
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(),STAYING);
					directionsCar.TurnOnEngine();
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), STAYING);
					directionsCar.SetSpeed(10);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), STAYING);
					directionsCar.SetGear(1);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(),MOVE_UP);
					directionsCar.SetGear(0);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), MOVE_UP);
					directionsCar.SetSpeed(0);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), STAYING);
					directionsCar.SetGear(-1);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), STAYING);
					directionsCar.SetSpeed(1);
					BOOST_CHECK_EQUAL(directionsCar.GetDirection(), MOVE_BACK);
				}
		BOOST_AUTO_TEST_SUITE_END()
	void CheckGearAndSpeedRange(int const gear, int minSpeed, int maxSpeed)
	{
		CCar setParametrsCar;
		setParametrsCar.TurnOnEngine();
		BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed));//������ ����������� ��������
		BOOST_CHECK(setParametrsCar.SetGear(gear));//������ ��������
		BOOST_CHECK(!setParametrsCar.SetSpeed(maxSpeed + 1)); //������ ������ ������������ �������� �� ������ 20+1 �.�.�.
		if (minSpeed = 0)
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));//�������� ����� ��������
		}
		else
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));//�������� ����� ��������
		}
		BOOST_CHECK(setParametrsCar.SetSpeed(maxSpeed)); //������� �� ���� ������� ��� ��������
		BOOST_CHECK(setParametrsCar.SetGear(0) == true); //�� ���� ���������, ��������� ������� �� ����������� ��������
	}


		BOOST_AUTO_TEST_SUITE(NeutralGearDuringMovement)
			BOOST_AUTO_TEST_CASE(CantBeIncreasedSpeed)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//���������, ��� ���� ��������� � ��������
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(100) ==  false);//������ ��������
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//���������, ��� �������� �������� ���������
			}
			BOOST_AUTO_TEST_CASE(ReducesTheRateOrTheSameSpeed)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//���������, ��� ���� ��������� � ��������
				
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(10) == true);//��������� �������� ��������
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//���������, ��� �������� �������� ���������
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(10) == true);//��������� ����� �� ��������� ��������
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//���������, ��� �������� �����������
			}
			BOOST_AUTO_TEST_CASE(DoesNotAllowTheEngineToSwitchOff)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//���������, ��� ���� ��������� � ��������
				BOOST_CHECK(validIncreasedSpeedCar.GetEngineState() == true);//���������, ��� ��������� �������
				BOOST_CHECK(validIncreasedSpeedCar.TurnOffEngine() == false);//�������� ��� ���������
				BOOST_CHECK(validIncreasedSpeedCar.GetEngineState() == true);//���������, ��� �� ������ ���������
			}
			BOOST_AUTO_TEST_CASE(DoesNotAllowTheEngineToSwitchReversGear)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//���������, ��� ���� ��������� � ��������
				validIncreasedSpeedCar.SetGear(-1);//������ ��������
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetGear(), 0);//���������, ��� �������� �������� ��������
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), 0);
			}
			
		BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()