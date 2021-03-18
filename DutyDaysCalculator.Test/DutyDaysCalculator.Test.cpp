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
			boost::gregorian::date testDate(2021, 4, 9);

			bool isWorkDay = dutyDaysCalculator.isWorkDay(testDate);

			Assert::IsFalse(isWorkDay);
		}
	};
}
