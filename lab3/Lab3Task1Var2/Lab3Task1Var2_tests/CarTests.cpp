#include "stdafx.h"
#include "..\\Lab3Task1Var2\Car.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE (Car_class)

	BOOST_AUTO_TEST_CASE(TestSetingSpeedAndGearThenEngineOff)
	{
		CCar validSetParametrsCar;
		BOOST_CHECK(validSetParametrsCar.SetSpeed(10) == false);
		BOOST_CHECK(validSetParametrsCar.SetGear(1) == false);
	}
	BOOST_AUTO_TEST_CASE(TestSetingSpeedAndGearThenEngineOn)
	{
		CCar successSetParametrsCar;
		BOOST_CHECK(successSetParametrsCar.TurnOnEngine() == true);
		BOOST_CHECK(successSetParametrsCar.SetSpeed(10) == true);
		//
		BOOST_CHECK(successSetParametrsCar.SetGear(1) == true);
	};

	BOOST_AUTO_TEST_CASE(TestEngineOnThenEngineOn)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == false);
	}
	BOOST_AUTO_TEST_CASE(TestEngineOnThenEngineOff)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
	}
	BOOST_AUTO_TEST_CASE(TestEngineOffThenEngineOff)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.TurnOffEngine() == false);
	}
	BOOST_AUTO_TEST_CASE(TestEngineOffThenEngineOn)
	{
		CCar validEngineOnCar;
		BOOST_CHECK(validEngineOnCar.TurnOnEngine() == true);
		BOOST_CHECK(validEngineOnCar.TurnOffEngine() == true);
	}
	BOOST_AUTO_TEST_CASE(TestDirectionsInfo)
	{
		CCar directionsCar;
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state off\nCar moving in towards staying\nCar have speed 0 km/s\nCar have gearshift 0\n");
		directionsCar.TurnOnEngine();
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards staying\nCar have speed 0 km/s\nCar have gearshift 0\n");
		directionsCar.SetSpeed(10);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards staying\nCar have speed 10 km/s\nCar have gearshift 0\n");//staying
		directionsCar.SetGear(1);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards Move Up\nCar have speed 10 km/s\nCar have gearshift 1\n");//Move Up
		directionsCar.SetGear(0);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards Move Up\nCar have speed 10 km/s\nCar have gearshift 0\n");//Move Up
		directionsCar.SetSpeed(0);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards staying\nCar have speed 0 km/s\nCar have gearshift 0\n");//staying
		directionsCar.SetGear(-1);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards staying\nCar have speed 0 km/s\nCar have gearshift -1\n");//staying
		directionsCar.SetSpeed(1);
		BOOST_CHECK_EQUAL(directionsCar.GetInfo(), "Engine car state on\nCar moving in towards Move Back\nCar have speed 1 km/s\nCar have gearshift -1\n");//Move Back
	}

	void CheckGearAndSpeedRange(CCar & setParametrsCar, int &gear, int &minSpeed, int &maxSpeed)
	{
		BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed));
		BOOST_CHECK(setParametrsCar.SetGear(gear));
		BOOST_CHECK(!setParametrsCar.SetSpeed(maxSpeed + 1));
		if (minSpeed = 0)
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));
		}
		else
		{
			BOOST_CHECK(setParametrsCar.SetSpeed(minSpeed - 1));
		}

		BOOST_CHECK(setParametrsCar.SetSpeed(maxSpeed));
		gear++;
	}

	BOOST_AUTO_TEST_CASE(TestSetingSpeedAndGear)
	{
		CCar setParametrsCar;
		setParametrsCar.TurnOnEngine();
		setParametrsCar.SetGear(0);
		setParametrsCar.SetSpeed(0);
		int gear = -1;
		int minS = 0;
		int maxS = 20;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 0;
		maxS = 150;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 0;
		maxS = 30;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 20;
		maxS = 50;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 30;
		maxS = 60;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 40;
		maxS = 90;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
		minS = 50;
		maxS = 150;
		CheckGearAndSpeedRange(setParametrsCar, gear, minS, maxS);
	}

BOOST_AUTO_TEST_SUITE_END()