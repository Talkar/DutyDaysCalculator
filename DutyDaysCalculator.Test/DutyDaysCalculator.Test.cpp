#include "pch.h"
#include "CppUnitTest.h"
#include "../DutyDaysCalculator/DutyDaysCalculator.h"
#include "../DutyDaysCalculator/DutyDaysCalculator.cpp"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DutyDaysCalculatorTest
{
	TEST_CLASS(DutyDaysCalculatorTest)
	{
	public:
		
		TEST_METHOD(Verify_NewYearsDay_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 1, 1);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_MaundyThursday_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 4, 1);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_GoodFriday_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 4, 2);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_EasterSunday_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 4, 4);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_EasterMonday_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 4, 5);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_GeneralPrayerDay_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 4, 30);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_AscensionDay_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 5, 13);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_Pentecost_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 5, 23);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_WhitMonday_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 5, 24);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_ChristmasDay_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 12, 25);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}

		TEST_METHOD(Verify_StStephensDay_Test)
		{
			DutyDaysCalculator dutyDaysCalculator;
			boost::gregorian::date testDate(2021, 12, 26);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}
	};
}
