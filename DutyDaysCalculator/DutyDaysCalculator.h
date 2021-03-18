#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;
class DutyDaysCalculator {
public:
	bool isWorkDay(gregorian::date dateToCheck);
};