#include "stdafx.h"
#include "..\\Lab3Task1Var2\Car.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE (Car_class)


	BOOST_AUTO_TEST_CASE(BeginState)
	{
		CCar beginStateCar;//проверка начальных состояний
		BOOST_CHECK(beginStateCar.GetEngineState() == false);
		BOOST_CHECK_EQUAL(beginStateCar.GetGear(), 0);
		BOOST_CHECK_EQUAL(beginStateCar.GetDirection(), STAYING);
		BOOST_CHECK_EQUAL(beginStateCar.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCantBeSetingSpeedThenEngineOff)
	{
		CCar validSetParametrsCar;//скорость не может быть изменена, когда двигатель выключен
		BOOST_CHECK(validSetParametrsCar.SetSpeed(10) == false);
		BOOST_CHECK_EQUAL(validSetParametrsCar.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCantBeSetingGearThenEngineOff)
	{
		CCar validSetParametrsCar;;//передача не может быть изменена, когда двигатель выключен
		BOOST_CHECK(validSetParametrsCar.SetGear(1) == false);
		BOOST_CHECK_EQUAL(validSetParametrsCar.GetGear(), 0);
	}
	BOOST_AUTO_TEST_CASE(TestCanBeEngineOnThenEngineOff) 
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.GetEngineState() == false);//изначально выключен
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
		BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//после включен

	}
	BOOST_AUTO_TEST_CASE(TestEngineOffThenEngineOff)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.GetEngineState() == false);//изначально выключен
		BOOST_CHECK(validEngineOnCar.TurnOffEngine() == false);//не выключается так как уже выключен
	}
	BOOST_AUTO_TEST_SUITE(TestMiniSwichForZeroGearBackGearFirtGear)
		BOOST_AUTO_TEST_CASE(Switching)
		{
			CCar SetParametrsCar;
			SetParametrsCar.TurnOnEngine();
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(),0);//проверка на нулевую передачу
			BOOST_CHECK_EQUAL(SetParametrsCar.GetSpeed(), 0);//проверка на нулевую скорость
			BOOST_CHECK(SetParametrsCar.SetGear(-1));//можно переключится при нулевой скорости
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(), -1);//проверка так ли это
			SetParametrsCar.SetGear(0);
			SetParametrsCar.SetSpeed(10);
			BOOST_CHECK(SetParametrsCar.SetGear(-1));//нельзя переключится при скорости выше нуля
			BOOST_CHECK_EQUAL(SetParametrsCar.GetGear(), -1);//проверка так ли это
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
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == false);//нельзя выключить двигатель на первой передаче
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == true);//проверка, что двигатель еще включен
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOffThenNeutralGear)
			{
				CCar validSetParametrsCar;
				validSetParametrsCar.TurnOnEngine();			
				validSetParametrsCar.SetGear(0);
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == true);//можно выключить на нейтральной передаче
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == false); //проверка state
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOffThenReversGear)
			{
				CCar validSetParametrsCar;
				validSetParametrsCar.TurnOnEngine();
				validSetParametrsCar.SetGear(-1);
				BOOST_CHECK(validSetParametrsCar.TurnOffEngine() == false);//нельзя выключить двигатель на задней передаче
				BOOST_CHECK(validSetParametrsCar.GetEngineState() == true); //проверка state
			};
			BOOST_AUTO_TEST_CASE(TestCanBeEngineOnThenEngineOn)
			{
				CCar validEngineOnCar;
				BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
				BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//проверка, что включился
				BOOST_CHECK(validEngineOnCar.TurnOnEngine() == false);
				BOOST_CHECK(validEngineOnCar.GetEngineState() == true);//проверка, что все еще включен
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
		BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed));//задает минимальную скорость
		BOOST_CHECK(setParametrsCar.SetGear(gear));//задает передачу
		BOOST_CHECK(!setParametrsCar.SetSpeed(maxSpeed + 1)); //задает придел максимальной скорости на первой 20+1 и.т.д.
		if (minSpeed = 0)
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));//проверка миним скорости
		}
		else
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));//проверка миним скорости
		}
		BOOST_CHECK(setParametrsCar.SetSpeed(maxSpeed)); //задачет на всех передач мак скорость
		BOOST_CHECK(setParametrsCar.SetGear(0) == true); //на всех передачах, позволяет сменить на нейтральную передачу
	}


		BOOST_AUTO_TEST_SUITE(NeutralGearDuringMovement)
			BOOST_AUTO_TEST_CASE(CantBeIncreasedSpeed)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//проверяем, что авто находится в движении
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(100) ==  false);//задаем скорость
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//проверяем, что скорость осталась прежденей
			}
			BOOST_AUTO_TEST_CASE(ReducesTheRateOrTheSameSpeed)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//проверяем, что авто находится в движении
				
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(10) == true);//оставляем скорость преждней
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//проверяем, что скорость осталась прежденей
				BOOST_CHECK(validIncreasedSpeedCar.SetSpeed(10) == true);//проверяем можно ли уменьшить скорость
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetSpeed(), 10);//проверяем, что скорость уменьшилась
			}
			BOOST_AUTO_TEST_CASE(DoesNotAllowTheEngineToSwitchOff)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//проверяем, что авто находится в движении
				BOOST_CHECK(validIncreasedSpeedCar.GetEngineState() == true);//проверяем, что двигатель включен
				BOOST_CHECK(validIncreasedSpeedCar.TurnOffEngine() == false);//пытаемся его выключить
				BOOST_CHECK(validIncreasedSpeedCar.GetEngineState() == true);//проверяем, что не смогли выключить
			}
			BOOST_AUTO_TEST_CASE(DoesNotAllowTheEngineToSwitchReversGear)
			{
				CCar validIncreasedSpeedCar;
				validIncreasedSpeedCar.TurnOnEngine();
				validIncreasedSpeedCar.SetGear(1);
				validIncreasedSpeedCar.SetSpeed(10);
				validIncreasedSpeedCar.SetGear(0);
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), MOVE_UP);//проверяем, что авто находится в движении
				validIncreasedSpeedCar.SetGear(-1);//задаем передачу
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetGear(), 0);//проверяем, что передача осталась преждней
				BOOST_CHECK_EQUAL(validIncreasedSpeedCar.GetDirection(), 0);
			}
			
		BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()